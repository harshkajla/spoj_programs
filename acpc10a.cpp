#include <iostream>
#include <stdio.h>
using namespace std ;

int main () {
	int a , b , c ;
	while(true) {
		scanf("%d" , &a) ;
		scanf("%d" , &b) ;
		scanf("%d" , &c) ;
		if(a == 0 && b == 0 && c == 0)
			break ;
		if(2 * b == a + c) {
			printf("AP %d\n" , (c + b - a)) ;
		}
		else {
			printf("GP %d\n" , (c * (b / a))) ;
		}
	}
}
