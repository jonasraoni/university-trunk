/*
 * Author: Jonas Raoni Soares da Silva
 * Description: Calculates the fibonacci sequence
 */

#include <stdio.h>

int main(){
	int n, n2 = 1, f1 = 1, f2 = 1;

	printf( "Input the number: " );
	scanf("%d", &n );
	if( --n > 1 )
		while( --n && (f1 = n2 = f2 + (f2 = f1), 1));
	printf( "The result is: %d", n2 );
	return 0;
}
