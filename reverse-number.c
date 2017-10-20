/*
 * Author: Jonas Raoni Soares da Silva
 * Description: Reverse the order of digits in a number
 */

#include<stdio.h>
#include<conio.h>

int main(){
	int n, r = 0;
	clrscr();
	printf("Type the number: ");
	scanf("%d", &n);
	while(r = n % 10 + r * 10, n /= 10, n);
	printf("Reverse %d", r);
	getch();
	return 0;
}
