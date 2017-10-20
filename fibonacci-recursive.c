/*
 * Author: Jonas Raoni Soares da Silva
 * Description: Calculates the fibonacci sequence with recursion
 */

#include <stdio.h>
#include <conio.h>

int fibonacci( n ){
	return n > 2 ? fibonacci( n - 1 ) + fibonacci( n - 2 ): 1;
}
 
int main() {
	int long unsigned n;
	clrscr();
	printf( "Input the number: " );
	scanf( "%d", &n );
	printf( "The result is %d", fibonacci( n ) );
	getch();
}
