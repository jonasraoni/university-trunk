/*
 * Author: Jonas Raoni Soares da Silva
 * Description: Displays "strange numbers", the rule is:
 * - The number must have 4 digits
 * - The sum of the first 2 digits with the last 2 digits multiplied by itself must be equals to the given number
 */

#include <stdio.h>
#include <conio.h>

int main() {
	int i, n = 10000;

	clrscr();

	while( (--n > 999) && ( (i = n / 100 + n % 100 )*i == n  && printf( "\"%d\" is perfect.\n", n) || 1 ) );

	getch();
}
