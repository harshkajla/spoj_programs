#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std ;

unsigned long long count(unsigned long long n) {
	unsigned long long t = 0 ;
	unsigned long long p = sqrt(n) ;
	for(unsigned long long i = 1 ; i <= p ; i++) {
		if(n % i == 0)
			t++ ;
	}
	return t ;
}

int main() {
	unsigned long long n ;
	scanf("%lld" , &n) ;
	unsigned long long total = 0 ;
	for(unsigned long long i = 1 ; i <= n ; i++) {
		total = total + count(i) ;
	}
	printf("%lld" , total) ;
}
