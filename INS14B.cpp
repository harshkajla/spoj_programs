#include <bits/stdc++.h>
using namespace std ;

int primes[] = {2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31} ;

int main() {
	int T , N , count ;
	scanf("%d" , &T) ;
	while(T--) {
		count = 1 ;
		scanf("%d" , &N) ;
		if(N % 2 == 1) {
			printf("0\n") ;
			continue ;
		}
		vector <int> power(12 , 0) ;
		for(int i = 0 ; i < 11 ; i++) {
			if(N % primes[i] == 0) {
				while(N % primes[i] == 0) {
					N = N / primes[i] ;
					power[i]++ ;
				}
			}
		}
		if(N != 1)
			power[11]++ ;
		
		count = count * (2 * power[0]) ;
		for(int i = 1 ; i < 12 ; i++)
			count = count * (2 * power[i] + 1) ;
		printf("%d\n" , count) ;
	}
}