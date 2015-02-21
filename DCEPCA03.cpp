#include <bits/stdc++.h>
using namespace std ;

int primes[] = {2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31 , 37 , 41 , 43 , 47 , 53 , 59 , 61 , 67 , 71 , 73 , 79 , 83 , 89 , 97} ;

int totient(int num) {
	int res = num ;
	for(int i = 0 ; i < 25 ; i++) {
		if(num % primes[i] == 0) {
			res = res - res / primes[i] ;
			while(num % primes[i] == 0)
				num = num / primes[i] ;
		}
	}
	if(num != 1)
		res = res - res / num ;
	return res ;
}

int main() {
	int T , N ;
	unsigned long long H = 0 ;
	scanf("%d" , &T) ;
	while(T--) {
		H = 0 ;
		scanf("%d" , &N) ;
		for(int i = 1 ; i <= N ; i++)
			H = H + (unsigned long long)totient(i) ;
		H = H * H ;
		printf("%lld\n" , H) ;
	}
}