/*
 * Author: Jonas Raoni Soares da Silva
 * Description: Given at least 3 numbers, displays the amount of triplets found.
 * For the sequence 4 9 2 2 2 7 7 7 7 the answer must be 3,
 * since there's 1 triplet of "2" and 2 triplets of "7".
 */

#include <stdio.h>
#include <conio.h>

#define MAX 20

int main () {
	int vetor[MAX], i = 0, j = 0;

	clrscr();

	while( printf( "Enter the number %d: ", i+1 ) && scanf( "%d", &vetor[i] ) && printf( "If finished press \"s\"\n" ) && ( i++ < MAX && getch() != 's' ) || i < 3 );
	while( --i > 1 && ( ( ( vetor[i] == vetor[i-1] && vetor[i] == vetor[i-2] ) && ++j ) || 1 ) );
	if( j && printf( "Found %d triplets =)", j ) );
	getch();
	return 0;
}
