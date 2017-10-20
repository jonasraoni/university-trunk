/*
 * Author: Jonas Raoni Soares da Silva
 * Description: Giving a maximum number, prints all perfect numbers found in the interval
 * A perfect number is equals to the sum of its divisors excluding itself
 */

#include <stdio.h>
#include <conio.h>

int main() {
	int s, i, n;

	clrscr();

	printf( "Type a number:" );
	scanf( "%d", &n );

	++n;
	while( --n > 1 ) {
		for( s=0, i = 1; i <= n; i++ )
			if( !(n % i) && ( s+= i ) );
		if( 2 * n == s && printf( "\"%d\" is a perfect number\n", n ) );
	}
	getch();
}
