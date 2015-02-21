#include <iostream>
#include <stdio.h>
using namespace std ;

int main () {
	int T , N ;
	scanf("%d" , &T) ;
	while(T--) {
		scanf("%d" , &N) ;
		int count = 0 ;
		while(N != 0) {
			N = N / 5 ;
			count = count + N ;
		}
		printf("%d\n" , count) ;
	}
}
