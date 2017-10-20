/*
 * Author: Jonas Raoni Soares da Silva
 * Description: Calculate the coefficient
 */

#include <stdio.h>
#include <conio.h>

#define MAX_COEF 20

int pow( int base, int exp ){
	int result = base;
	if( exp == 0 )
		return 1;
	while( --exp )
		result = result * base;
	return result;
}

int main() {
	int coef[MAX_COEF], result = 0, i = 0, x;

	clrscr();

	do{
		printf( "Type the coefficient %d: ", i+1 );
		scanf( "%d", &coef[i] );
		printf( "Type <enter> to continue\n" );
	} while ( ++i < MAX_COEF && getch() == '\r' );


	printf( "Type the base: " );
	scanf( "%d", &x );

	while( i-- )
		result += coef[i] * pow( x, i );

	printf( "Result = %d", result );

	getch();

	return 0;
}
