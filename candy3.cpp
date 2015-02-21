#include <iostream>
#include <stdio.h>
#include <sstream>
using namespace std ;

int main() {
	int t ;
	unsigned long long sum , count ;
	scanf("%d" , &t) ;
	while(t--) {
		sum = 0 ;
		scanf("%lld" , &count) ;
		unsigned long long x ;
		for(unsigned long long i = 0 ; i < count ; i++) {
			scanf("%lld" , &x) ;
			sum = (sum + x) % count ;
		}
		if(sum % count == 0)	
			printf("YES\n") ;
		else
			printf("NO\n") ;
	}
}
