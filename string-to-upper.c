/*
 * Author: Jonas Raoni Soares da Silva
 * Description: One liner to convert lowercase characters to uppercase
 */

#include<stdio.h>
#include<conio.h>

int main(){
	char *nome, *nomeBegin = nome;

	clrscr();
	printf( "Input your name: " );

	gets( nome );

 	while( ( ( *nome >= 'a' && *nome <= 'z' && (*nome -= 32) ) || 1 ) && *nome++ != '\0' );

	printf( "%s", nomeBegin );

	getch();
	return 0;
}
