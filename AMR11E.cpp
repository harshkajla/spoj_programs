#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std ;

vector <int> primes ;
vector <bool> check(32000 , false) ;
vector <int> lucky ;

bool islucky(int k) {
	int factors = 0 ;
	for(int j = 0 ; primes[j] < k ; j++) {
		if(k % primes[j] == 0) {
			factors++ ;
			if(factors >= 3) {
				return true ;
			}
		}
	}
	return false ;
}

void sieve() {
	for(int i = 3 ; i <= 180 ; i = i + 2)
		if(!check[i])
			for(int j = i * i ; j <= 32000 ; j = j + i)
				check[j] = true ;
	primes.push_back(2) ;
	for(int i = 3 ; i <= 32000 ; i = i + 2)
		if(!check[i])
			primes.push_back(i) ;
}

void generate_lucky() {
	int k = 30 ;
	int factors ;
	for(int k = 30 ; ; k++) {
		if(lucky.size() == 1000)
			return ;
		if(islucky(k))
			lucky.push_back(k) ;
	}
}

int main() {
	sieve() ;
	int T , n ;
	scanf("%d" , &T) ;
	generate_lucky() ;
	while(T--) {
		scanf("%d" , &n) ;
		printf("%d\n" , lucky[n - 1]) ;
	}
}