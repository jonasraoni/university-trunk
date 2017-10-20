/*
 * Author: Jonas Raoni Soares da Silva
 * Description: displays the nth (reverse) digit
 */

#include<stdio.h>
#include<conio.h>

int nth( int, int );

int main(){
	int n, i;

	clrscr();
	printf( "Input the number: " );
	scanf( "%d", &n );

	printf( "Input the position: ");
	scanf( "%d", &i );

	printf( "%d", kezimo( n, i ) );

	getch();
	return 0;
}

int nth( int n, int i ){
	while( --i && ( n /= 10 ) );
	return n % 10;
}
