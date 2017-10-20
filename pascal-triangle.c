/*
 * Author: Jonas Raoni Soares da Silva
 * Description: Prints the pascal triangle according to the given degree
 */

#include <stdio.h>
#include <conio.h>

#define MAX 16

int main () {
	int unsigned vetor[MAX], grau, i = 0, j, top, left;

	clrscr();

	while( grau > MAX && printf( "Type a number between 0 and %d for the degree: ", MAX ) && scanf( "%u", &grau ) );
	while( i++ < grau && !( j = 0 ) && printf( "\n" ) )
		while( j < i && ( j == 0 && ( top = left = vetor[j] = 1 ) ? 1 : j > 0 && j < i-1 && ( top = vetor[j] ) && ( vetor[j] = left + top ) && ( left = top ) ? 1 : ( vetor[j] = 1 ) ) && printf( "%-5d", vetor[j] ) && ++j );
	getch();
	return 0;
}
