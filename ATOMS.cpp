#include <bits/stdc++.h>
using namespace std ;

int main() {
	int P ;
	unsigned long long N , K , M ;
	scanf("%d" , &P) ;
	/*
	while(P--) {
		scanf("%lld %lld %lld" , &N , &K , &M) ;
		if(N > M) {
			printf("0\n") ;
			continue ;
		}
		int T = log10(M * 1.0 / N) / log10(K) ;
		printf("%d\n" , T) ;
	}*/
	while(P--) {
		scanf("%lld %lld %lld" , &N , &K , &M) ;
		long long T = 0 ;
		unsigned long long total = N ;
		while(true) {
			if((double)N * (double)K > (double)M)
				break ;
			N = N * K ;
			T++ ;
		}
		printf("%lld\n" , T) ;
	}
}