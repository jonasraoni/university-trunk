/*
 * Author: Jonas Raoni Soares da Silva
 * Description: One liner to sum the digits of a number
 */

#include<stdio.h>
#include<conio.h>

int digits( int );

int main(){
	int n;

	clrscr();
	printf( "Input the number: " );
	scanf( "%d", &n );

	printf( "%d", digits( n ) );

	getch();
	return 0;
}

int digits( int n ){
	int r = 0;
	while( ( ( r += n % 10 ) || 1 ) && ( n /= 10 ) );
	return r;
}
