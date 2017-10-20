/*
 * Author: Jonas Raoni Soares da Silva
 * Description: election with 2 candidates, none and null vote
 */

#include <stdio.h>
#include <conio.h>

int main() {
	char vote[3];
	int amount[5] = {0};

	do{
		clrscr();
		printf( "Type the number of your candidate Alibabah (83), Alcapone (93), None (00), Null (any inexistent number):" );
		scanf( "%s", &vote );

		amount[ !strcmp( vote, "83") ? 0 : !strcmp( vote, "93" ) ? 1 : !strcmp( vote, "00" ) ? 2 : 3 ]++;
		amount[4]++;

	} while( printf("Press enter to vote more or any other key to display the results.") && (getch() == '\r' ) );

	printf( "\n\nAlibabah = %d\nAlcapone = %d\nWhite = %d\nNull = %d", amount[0], amount[1], amount[2], amount[3] );

	getch();

	return 0;
}
