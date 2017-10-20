/*
 * Author: Jonas Raoni Soares da Silva
 * Description: After inputting n numbers, build an array with the indexes of the even elements and display
 */

#include <stdio.h>
#include <conio.h>

#define MAX 20

int main () {
	int a[MAX], p[MAX], i = 0, j = 0;

	clrscr();

	while( printf( "Input the number %d: ", i+1 ) && scanf( "%d", &a[i] ) && printf( "If finished, press 's')?\n" ) && i++ < MAX && getch() != 's' );
	while( i-- && ( ( !( a[i] % 2 ) && ( p[j++] = i ) ) || 1 ) );
	printf( "\nIndexes of the even elements\n" );
	while( j && printf( "%d ", p[--j] ) );
	getch();

	return 0;
}
