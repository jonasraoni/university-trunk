/*
 * Author: Jonas Raoni Soares da Silva
 * Description: One liner to exchange two integer variables
 */

#include <stdio.h>
#include <conio.h>

void main(){
	int a, b;
	clrscr();
	printf("Type the value a");
	scanf("%d",&a);
	printf("Type the value of b");
	scanf("%d",&b);
	a = b - a + ( b = a );
	printf("a= %d",a);
	printf("\nb= %d",b);
	getch();
}
