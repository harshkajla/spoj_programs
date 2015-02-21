#include <bits/stdc++.h>
using namespace std ;

vector <int> primes ;
void generate_primes() {
	primes.push_back(2) ;
	for(int i = 3 ; i < 1000 ; i++) {
		bool p = true ;
		for(int j = 2 ; j * j <= i ; j++)
			if(j % i == 0) {
				p = false ;
				break ;
			}
		if(p == true)
			primes.push_back(i) ;
	}
}

int totient(int n) {
	int res = n ;
	for(int i = 0 ; primes[i] * primes[i] <= n && i < primes.size() ; i++) {
		if(n % primes[i] == 0) {
			res = res - res / primes[i] ;
			while(n % primes[i] == 0)
				n = n / primes[i] ;
		}
	}
	if(n != 1)
		res = res - res / n ;
	return res ;
}

int main() {
	generate_primes() ;
	int T , n ;
	scanf("%d" , &T) ;
	while(T--) {
		scanf("%d" , &n) ;
		printf("%d\n" , totient(n)) ;
	}
}