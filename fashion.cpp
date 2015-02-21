#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std ;

int main () {
	int t ;
	int n ;
	scanf("%d" , &t) ;
	while(t--) {
		scanf("%d" , &n) ;
		int m[n] , w[n] ;
		for(int i = 0 ; i < n ; i++)
			scanf("%d" , &m[i]) ;
		for(int i = 0 ; i < n ; i++)
			scanf("%d" , &w[i]) ;
		sort(m , m + n) ;
		sort(w , w + n) ;
		unsigned long long sum  = 0 ;
		for(int i = 0 ; i < n ; i++)
			sum = sum + m[i] * w[i] ;
		printf("%lld\n" , sum) ;
	}
}
