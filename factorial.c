/*
 * Author: Jonas Raoni Soares da Silva
 * Description: Calculates the factorial of a number
 */

#include<stdio.h>
#include<conio.h>

int factorial( int );

int main(){
	int n;

	clrscr();
	printf( "Input the number: " );
	scanf( "%d", &n );

	printf( "%d", factorial( n < 0 ? n * -1 : n ) );

	getch();
	return 0;
}

int factorial( int n ){
	return n == 1 ? 1 : n * factorial( n - 1 );
}
