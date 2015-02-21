#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std ;

int main() {
	int T ;
	long long x, y, S , n1 , n2 , n , a , d , p , q , r ;
	scanf("%d" , &T) ;
	while(T--) {
		scanf("%lld" , &x) ;
		scanf("%lld" , &y) ;
		scanf("%lld" , &S) ;
		p = x + y ;
		q = -1 * (7 * x + 5 * y + 2 * S) ;
		r = 12 * S ;
		n1 = llrint(0.5 * (-1.0 * q / p + sqrtl((q * 1.0 / p) * (q * 1.0 / p) - 4.0 * r / p))) ;
		n2 = llrint(0.5 * (-1.0 * q / p - sqrtl((q * 1.0 / p) * (q * 1.0 / p) - 4.0 * r / p))) ;
		//n1 = (7 * x + 5 * y + 2 * S + (sqrtl((7 * x + 5 * y + 2 * S) * (7 * x + 5 * y + 2 * S) - 4 * (x + y) * 12 * S))) / (2 * (x + y)) ;
		//n2 = (7 * x + 5 * y + 2 * S - (sqrtl((7 * x + 5 * y + 2 * S) * (7 * x + 5 * y + 2 * S) - 4 * (x + y) * 12 * S))) / (2 * (x + y)) ;
		n = max(n1 , n2) ;
		a = ((n - 4) * x - 2 * y) / (n - 6) ;
		d = (y - x) / (n - 6) ;
		printf("%lld\n" , n) ;
		for(int i = 0 ; i < n ; i++)
			printf("%lld " , a + i * d) ;
		printf("\n") ;
	}
}