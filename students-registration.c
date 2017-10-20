/*
 * Author: Jonas Raoni Soares da Silva
 * Description: Insert, remove, search and update records of "students" and their grades into a binary file
 */

/********************* BIBLIOTECAS***********************/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


/********************* CONSTANTES ***********************/
#define MAX_NOME		80				/* qtd máximo de caracteres para o nome */
#define QTD_NOTAS		4				/* qtd de notas */
#define DATA_FILENAME	"database.dat"	/* arquivo padrão para salvar os dados */



/************************ TIPOS *************************/
/* tipo para determinar o status do registro atual */
typedef enum {
	REC_ACTIVE = 0xBABACA,	/* registro removido */
	REC_REMOVED				/* registro ativo */
} Status;


/* cabeçalhos */
typedef enum {
	HEADER_MAINMENU = 0xBAF0,
	HEADER_PROGRAM,
	HEADER_SEARCH
} Header;


/* tipo para manter informações sobre um aluno */
typedef struct { 
	Status status;					/* status do registro */
	unsigned int ra;				/* registro do aluno */
	char nome[ MAX_NOME+1 ];		/* nome do aluno */
	unsigned int nota[ QTD_NOTAS ];	/* notas do aluno */
} Record; 



/*********************** VARIÁVEIS ***********************/
FILE *database;					/* ponteiro para o arquivo do dados */
Record *curRec;					/* ponteiro para Record, usado para manter registros operados no momento */
unsigned int recordCount = 0;	/* quantidade de registros presentes na tabela */



/************************ FUNCOES ************************/
/*---------------------------------------------------------
readRecord
Objetivo: lê um registro para dentro de um Record
Entrada: posição do registro e Record
Saida: 0 ou 1 representando sucesso
---------------------------------------------------------*/
int readRecord( unsigned int recNo, Record *rec );


/*---------------------------------------------------------
writeRecord
Objetivo: grava um registro vindo de record no fim do arquivo
Entrada: Record
Saida: 0 ou 1 representando sucesso
---------------------------------------------------------*/
int writeRecord( Record *rec );


/*---------------------------------------------------------
updateRecord
Objetivo: regrava um registro em determinada posição
Entrada: posição do registro e o Record
Saida: 0 ou 1 representando sucesso
---------------------------------------------------------*/
int updateRecord( unsigned int recNo, Record *rec );


/*---------------------------------------------------------
removeRecord
Objetivo: marca um registro como removido no arquivo
Entrada: posição do registro
Saida: 0 ou 1 representando sucesso
---------------------------------------------------------*/
int removeRecord( unsigned int recNo );


/*---------------------------------------------------------
inserir
Objetivo: interface para inserir cadastro no arquivo
Output: registro no arquivo
---------------------------------------------------------*/
void inserir( void );


/*---------------------------------------------------------
excluir
Objetivo: marcar registro para remocao
Entrada: indice do elemento
---------------------------------------------------------*/
void excluir( unsigned int recNo );


/*---------------------------------------------------------
editar
Objetivo: edita um registro dado o índice
Entrada: índice do registro a editar
---------------------------------------------------------*/
void editar( unsigned int recNo );


/*---------------------------------------------------------
procurar
Objetivo: procura um registro dado ra / nome do aluno
Saida: indice do registro encontrado ou -1 caso contrario
---------------------------------------------------------*/
unsigned int procurar( void );


/*---------------------------------------------------------
setData
Objetivo: procura um registro dado ra / nome do aluno
Saida: indice do registro encontrado ou -1 caso contrario
---------------------------------------------------------*/
void setData( void );


/*---------------------------------------------------------
printRecord
Objetivo: imprimir um registro na tela
Entrada: posição
Saida: 0 ou 1 notificando sucesso e o texto no monitor
---------------------------------------------------------*/
int printRecord( unsigned int recNo );


/*---------------------------------------------------------
listRecords
Objetivo: listar todos os registros do programa
---------------------------------------------------------*/
void listRecords( void );


/*---------------------------------------------------------
printHeader
Objetivo: imprimir cabecalho do programa
Saida: impressao do cabecalho na tela
---------------------------------------------------------*/
void printHeader( int headerId );


/*---------------------------------------------------------
cls
Objetivo: "limpar" a tela
Saida: limpa a tela
---------------------------------------------------------*/
void cls( void );


/*---------------------------------------------------------
pause
Objetivo: pausar a execução do programa
Saída: mensagem na tela
---------------------------------------------------------*/
int pause( void );


/*---------------------------------------------------------
error
Objetivo: imprimir erro
Entrada: mensagem
Saída: mensagem na tela + mensagem de pausa
---------------------------------------------------------*/
int error( char* msg );


/*---------------------------------------------------------
getChars
Objetivo: capturar cadeia de caracteres da tela
Entrada: ponteiro para cadeia de char e limite de chars que
  devem ser capturados
---------------------------------------------------------*/
char* getChars( char *s, int limit );



/********************* IMPLEMENTACAO *********************/
int main( int argc, char *argv[] ) {

	unsigned int op;

	if( !( curRec = (Record *)malloc( sizeof( Record ) ) ) ){
		error(  "Erro ao alocar memória." );
		return 1;
	};

	if( !( database = fopen( DATA_FILENAME, "rb+" )) && !( database = fopen( DATA_FILENAME, "wb+" ) ) ) {
		error( "Erro ao abrir/criar o arquivo de banco de dados." );
		return 1;
	}

	fseek( database, 0, SEEK_END );
	recordCount = ftell( database ) / sizeof( Record );

	for( ; ; cls(), printHeader( HEADER_PROGRAM ), printHeader( HEADER_MAINMENU ), scanf( "%d", &op ) ) {
		switch ( op ){
			case 1:
				cls();
				printHeader( HEADER_PROGRAM );
				inserir();
				break;
			case 2:
				cls();
				printHeader( HEADER_PROGRAM );
				( op = procurar() )+1 ? excluir( op ) : error( "Registro nao encontrado." );
				break;
			case 3:
				cls();
				printHeader( HEADER_PROGRAM );
				( op = procurar() )+1 ? editar( op ) : error( "Registro nao encontrado" );
				break;
			case 4:
				cls();
				printHeader( HEADER_PROGRAM );
				( op = procurar() ) + 1 ? printRecord( op ) && pause() : error( "Registro nao encontrado." );
		break;
			case 5:
				cls();
				printHeader( HEADER_PROGRAM );
				listRecords();
				pause();
				break;
			case 6: {
				
				FILE *database2;

				if( database2 = fopen( DATA_FILENAME".tmp", "wb" ) ) {
					fseek( database, 0, SEEK_SET );
					while( fread( curRec, sizeof( Record ), 1, database ) && ( curRec->status == REC_REMOVED || fwrite( curRec, sizeof( Record ), 1, database2 ) ) );
					fclose( database2 );
					fclose( database );
					unlink( DATA_FILENAME );
					rename( DATA_FILENAME".tmp", DATA_FILENAME );
				}
				else {
					error( "Ocorreram problemas ao compactar o banco de dados." );
					fclose( database );
				}
				
				free( curRec );
				printf( "\nOBRIGADO!!! Naum se esqueca de fazer o deposito =]" );
				pause();
				return 0;
			}
			default:
				continue;
		}
	}
}


int readRecord( unsigned int recNo, Record *rec ){
	if( recNo >= recordCount )
		return 0;
	fseek( database, recNo * sizeof( Record ), SEEK_SET );
	return fread( rec, sizeof( Record ), 1, database )*sizeof( Record ) == sizeof( Record );
}


int writeRecord( Record *rec ){
	fseek( database, 0, SEEK_END );
	pause();
	return fwrite( rec, sizeof( Record ), 1, database )*sizeof( Record ) == sizeof( Record ) && ++recordCount;
}


int updateRecord( unsigned int recNo, Record *rec ){
	if( recNo >= recordCount )
		return 0;
	fseek( database, recNo * sizeof( Record ), SEEK_SET );
	return fwrite( rec, sizeof( Record ), 1, database )*sizeof( Record ) == sizeof( Record );
}


int removeRecord( unsigned int recNo ){
	if( recNo >= recordCount || !readRecord( recNo, curRec ) )
		return 0;
	curRec->status = REC_REMOVED;
	return updateRecord( recNo, curRec );
}


void inserir( void ) {
	setData();
	!writeRecord( curRec ) && error( "Erro gravando no arquivo" );
}


void excluir( unsigned int recNo ){
	if( printRecord( recNo ) ) {
		printf( "\nTem certeza que deseja remover? (pressione 1)" );
		getch() == '1' && !removeRecord( recNo ) && error( "Erro removendo o registro" );
	}
}


void editar( unsigned int recNo ){
	if( readRecord( recNo, curRec ) && printRecord( recNo ) ){
		printf( "\nTem certeza que deseja editar? (pressione 1)" );
		if( getch() != '1' )
			return;
		setData();
		!updateRecord( recNo, curRec ) && error( "Problemas ao atualizar." );
	}	
}


unsigned int procurar( void ) {

	unsigned int ra, i = 0;
	char *nome;
	int n;

	fseek( database, 0, SEEK_SET );

	printHeader( HEADER_SEARCH );

	for( ; ; scanf( "%d", &n ) ) {
		if( n == 1 ) {
			printf( "RA do Aluno: " );
			scanf( "%u", &ra );
			while( fread( curRec, sizeof( Record ), 1, database ) && ++i )
				if( curRec->status == REC_ACTIVE && curRec->ra == ra )
					return --i;
		}
		else if( n == 2 ) {
			if( !(nome = (char *)malloc( MAX_NOME+1 )) ) {
				error( "Erro ao alocar memória.\n" );
				return -1;
			};
			printf( "Nome do Aluno: " );
			getChars( nome, MAX_NOME );
			while( fread( curRec, sizeof( Record ), 1, database ) && ++i )
				if( curRec->status == REC_ACTIVE && !stricmp( curRec->nome, nome ) )
					return --i;
			free( nome );
		}
		else if( n != 3 )
			continue;
		return -1;
	}
}


void setData( void ) {

	int i = QTD_NOTAS;

	curRec->status = REC_ACTIVE;
	printf("\n    RA: ");
	scanf("%u", &curRec->ra);
	printf(" Aluno: ");

	getChars( curRec->nome, MAX_NOME );

	for( i = 0; i < QTD_NOTAS; i++ ){
		printf( "%d Nota: ", i+1 );
		scanf( "%u", &curRec->nota[i] );
	}
}


int printRecord( unsigned int recNo ){
	int i;
	if( readRecord( recNo, curRec ) ){ 
		printf( "RA\t\t|NOME\n%u\t\t|%s", curRec->ra, curRec->nome );
		for( i = 0; i < QTD_NOTAS; printf( " N%d(%u)", i+1, curRec->nota[i] ), i++ );
		return 1;
	}
	return 0;
}


void listRecords( void ){

	int i = 0, j;

	fseek( database, 0, SEEK_SET );
	printf( "RA\t\t|NOME\t\n" );
	while( fread( curRec, sizeof( Record ), 1, database ) ) {
		if( curRec->status == REC_ACTIVE ) {
			i++ == 10 && !( i = 0 ) && pause();
			printf( "%u\t\t|%s\t", curRec->ra, curRec->nome );
			for( j = 0; j < QTD_NOTAS; printf( " N%d(%u)", j+1, curRec->nota[j] ), j++ );
			printf( "\n" );
		}
	}
}


void printHeader( int headerId ){

	switch( headerId ) {
		case HEADER_PROGRAM: printf(
"===============================================================================\
\n============================= CADASTRO DE ALUNOS ==============================\
\n===============================================================================\nRegistros cadastrados: %u\n\n", recordCount
			);
			break;

		case HEADER_MAINMENU: printf(
"DIGITE O NUMERO DA OPCAO DESEJADA\n\
\n  INCLUIR REGISTRO:\t(1)\
\n  EXCLUIR REGISTRO:\t(2)\
\n  ALTERAR REGISTRO:\t(3)\
\n  PROCURAR REGISTRO:\t(4)\
\n   LISTAR REGISTROS:\t(5)\
\n              SAIR:\t(6)\
\n\n----------------------------\
\nOPCAO DESEJADA: " );
			break;

		case HEADER_SEARCH: printf(
"DIGITE A OPCAO QUE DESEJA PROCURAR\n\
        NUMERO DO RA: (1)\n\
       NOME DO ALUNO: (2)\n\
            CANCELAR: (3)\nOPCAO: " );
			break;
	}

}


void cls( void ){

	/*static char *s = NULL;*/

 	system( "cls" );

	/*if( !s ){
		int n = 25;
		char *s2;
		*( ( s2 = s = (char *)malloc( n+1 ) ) + n ) = '\0';
		while( *s2 ) *(s2++) = '\n';
	}
	gotoxy( 25, 80 );
	printf( s );
	gotoxy( 1, 1 );*/
}


int pause( void ){
	printf( "\n\nPressiona qualquer tecla para continuar.\n\n" );
	return getch();
}


int error( char *msg ){
	printf( "\n\n%s", msg );
	return pause();
}


char* getChars( char *s, int limit ){
	char *result = s;
	fflush( stdin );
	while( limit-- && (( *s++ = getc( stdin ) ) != '\n' ) );
	*(--s) = '\0';
	return result;
}
