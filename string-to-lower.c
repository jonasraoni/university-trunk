/*
 * Author: Jonas Raoni Soares da Silva
 * Description: One liner to convert uppercase characters to lowercase
 */

#include<stdio.h>
#include<conio.h>

int main(){
	char *nome, *nomeBegin = nome;

	clrscr();
	printf( "Input your name: " );

	gets( nome );
	nome--;

	while( *nome++ != '\0' && ( ( *nome >= 'A' && *nome <= 'Z' && (*nome += 32) ) || 1 ) );

	printf( "%s", nomeBegin );

	getch();
	return 0;
}
