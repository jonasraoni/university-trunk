/*
 * Author: Jonas Raoni Soares da Silva
 * Description: builds two matrices, A and B, filling the diagonals with the given ID number,
 * then evaluates the matrix product of them and displays the biggest element.
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

const n = 7;
int matrixA[7][7], matrixB[7][7], matrixC[7][7];

void fillMatrix( const char *RA );
void printMatrix( const int *m[7][7] );
int getMax( const int *m[7][7] );
void multMatrix( );
void printElementInfo( const int element, const int *m[7][7] );

void main(){
	int maxElement;
	char RA[8];
	clrscr();

	printf( "Type your ID with 7 numbers:" );
	fgets( &RA, 8, stdin );

	fillMatrix( &RA );

	multMatrix( );
	printf("Displaying matrix \"C\"\n==========================\n" );
	printMatrix( &matrixC );

	maxElement = getMax( &matrixC );

	printf( "The biggest element is: %d\n", maxElement );
	printf( "\nInformation of the biggest element\n==============================\n");
	printElementInfo( maxElement, &matrixC );

	getch();
}

void fillMatrix( const char *RA ){
	int x, y;
	for( y = 0; y < n; y++ )
		for( x = 0; x < n; x++ ) {
			matrixA[ y ][ x ] = ( x == y ) ? RA[x]-48 : random(10);
			matrixB[ y ][ x ] = ( x + y + 1 == n ) ? RA[x]-48 : random(10);
		}
}

void printMatrix( const int *m[7][7] )
	int x, y;
	for( y = 0; y < n; y++ ) {
		printf("|");
		for( x = 0; x < n; x++ )
			printf( " %-6d ", m[y][x]  );
		printf("|\n");
	}
	printf("\n");
}

int getMax( const int *m[7][7] ){
	int max, x, y;
	max = m[0][0];
	for( y = 0; y < n; y++ )
		for( x = 0; x < n; x++ )
			if( m[y][x] > max )
				max = m[y][x];
	return max;
}

void multMatrix( ){
	int x, y, z;
	for( y = 0; y < n; y++ )
		for( x = 0; x < n; x++ ) {
			matrixC[y][x] = 0;
			for( z = 0; z < n; z++ )
				matrixC[y][x] += matrixA[y][z] * matrixB[z][y];
		}
}

void printElementInfo( const int element, const int *m[7][7] ){
	int x, y, count;
	count = 0;
	for( y = 0; y < n; y++ )
		for( x = 0; x < n; x++ )
			if( m[y][x] == element ) {
				count++;
				printf( "[%d,%d] = %d\n", y, x, m[y][x] );
			}
	count == 0 ? printf( "No element found.\n" ) : printf( "Found %d occurrences.", count );
}
