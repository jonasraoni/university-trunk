/*
 * Author: Jonas Raoni Soares da Silva
 * Description: Calculates the square of a number using the fact that:
 * the square of a positive number N is equals to the sum of the first N odd numbers
 */

#include <stdio.h>
#include <conio.h>

int main () {
	int n = 0, i;

	clrscr();

	printf( "Type a number: " );
	scanf( "%d", &i );

	i < 0 ? i*=-1 : NULL;
	while( i-- )
		n += ( i << 1 ) + 1;

	printf( "Result: %d", n );

	getch();
	return 0;
}
