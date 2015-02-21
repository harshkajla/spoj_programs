#include <iostream>
#include <stdio.h>
using namespace std ;

int last(int a , int b) {
	if(b == 0)
		return 1 ;
	else if(b % 2 == 1)
		return ((a % 10) * last(a , b - 1)) % 10 ;
	else {
		int c = last(a , b / 2) ;
		return (c * c) % 10 ;
	}
}

int main() {
	int a , b , t ;
	scanf("%d" , &t) ;
	while(t--) {
		scanf("%d" , &a) ;
		scanf("%d" , &b) ;
		int l = last(a , b) ;
		printf("%d\n" , l) ;
	}
}
