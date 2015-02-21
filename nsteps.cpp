#include <iostream>
#include <stdio.h>
using namespace std ;

int main () {
	int N ;
	int x , y ;
	scanf("%d" , &N) ;
	while(N--) {
		scanf("%d" , &x) ;
		scanf("%d" , &y) ;
		if(y == x || y == x - 2) {
			if((x % 2 == 0) && (y % 2 == 0)) {
				printf("%d\n" , (x + y)) ;
			}
			else if((x % 2 == 1) && (y % 2 == 1)) {
				printf("%d\n" , (x + y - 1)) ;
			}
		}
		else {
			printf("No Number\n") ;
		}
	}
}
