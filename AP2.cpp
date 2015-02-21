#include <iostream>
#include <stdio.h>
using namespace std ;

int main() {
	int T ;
	unsigned long long t3, t3last, sum , n , a , d ;
	scanf("%d" , &T) ;
	while(T--) {
		scanf("%lld" , &t3) ;
		scanf("%lld" , &t3last) ;
		scanf("%lld" , &sum) ;
		n = (2 * sum) / (t3 + t3last) ;
		d = (t3last - t3) / (n - 5) ;
		a = t3 - 2 * d ;
		printf("%lld\n" , n) ;
		for(int i = 0 ; i < n ; i++)
			printf("%lld " , a + i * d) ;
		printf("\n") ;
	}
}