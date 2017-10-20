/*
 * Author: Jonas Raoni Soares da Silva
 * Description: One liner to reverse a string
 */

#include<stdio.h>
#include<conio.h>

int main(){
	char *nome, *nomeBegin = nome;

	clrscr();
	printf( "Input your name: " );

	gets( nome );
	nome--;

	while( *nome++ != '\0' && ( ( ( *nome >= 'a' && *nome <= 'z' && (*nome -= 32) ) ) || ( ( *nome >= 'A' && *nome <= 'Z' && (*nome += 32) ) ) || 1 ) );

	printf( "%s", nomeBegin );

	getch();
	return 0;
}
