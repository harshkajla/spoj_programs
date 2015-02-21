#include <iostream>
#include <stdio.h>
using namespace std ;

int reverse(int a) {
	int res = 0 , rem ;
	while(a != 0) {
		rem = a % 10 ;
		res = res * 10 + rem ;
		a = a / 10 ;
	}
	return res ;
}

int main () {
	int N , a , b ;
	scanf("%d" , &N) ;
	while(N--) {
		scanf("%d" , &a) ;
		scanf("%d" , &b) ;
		a = reverse(a) ;
		b = reverse(b) ;
		printf("%d\n" , reverse(a + b)) ;
	}
}
