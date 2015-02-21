#include <bits/stdc++.h>
using namespace std ;

unsigned long long max(unsigned long long m , unsigned long long n) {
	if(m > n)
		return m ;
	else
		return n ;
}

unsigned long long min(unsigned long long m , unsigned long long n) {
	if(m < n)
		return m ;
	else
		return n ;
}

unsigned long long gcd(unsigned long long m , unsigned long long n) {
	if(min(m , n) == 0)
		return max(m , n) ;
	return gcd(max(m , n) % min(m , n) , min(m , n)) ;
}

int main() {
	int T ;
	unsigned long long N , limit ;
	scanf("%d" , &T) ;
	while(T--) {
		scanf("%lld" , &N) ;
		limit = N / 2 ;
		for(unsigned long long i = limit ; i >= 1 ; i--) {
			if(gcd(N , i) == 1) {
				printf("%lld\n", i) ;
				break ;
			}
		}
	}
}