/*
 * Author: Jonas Raoni Soares da Silva
 * Description: Returns the biggest/smallest numbers from a sequence
 */

#include <stdio.h>
#include <conio.h>

int main () {
	int maior, menor, n;

	clrscr();

	printf( "Type the first number: " );
	scanf( "%d", &n );
	maior = menor = n;

	while( printf( "Input another number: " ) && scanf( "%d", &n ) && ( ( n > maior ? maior = n : n < menor ? menor = n : NULL ) || 1 ) && printf( "If finished press \"s\"?\n" ) && getch() != 's' );
	printf( "\nThe biggest was %d and the smallest was %d", maior, menor ) && getch();
	return 0;
}
