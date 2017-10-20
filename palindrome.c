/*
 * Author: Jonas Raoni Soares da Silva
 * Description: Checks whether a given string is a palindrome
 */

#include <stdio.h>

int isPalindrome( char *s ){
	char *s2 = s + strlen( s ) - 1;
	if( !*s )
		return 1;
	while( *s++ == *s2-- && *s );
	return !*s && *( --s ) == *( ++s2 );
}

int main( int argc, char *argv[] ){
	char s[255];

	printf( "Input the text:" );
	gets( s );
	printf( "%s \n", isPalindrome( s ) ? "Yes" : "No" );

	system( "pause" );

	return 0;
}
