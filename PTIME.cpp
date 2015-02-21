#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std ;

int main() {
	int N ;
	scanf("%d" , &N) ;
	vector <int> primes ;
	primes.push_back(2) ;
	for(int i = 3 ; i <= N ; i = i + 2) {
		bool p = true ;
		for(int j = 2 ; j * j <= i ; j++) {
			if(i % j == 0) {
				p = false ;
				break ;
			}
		}
		if(p == true)
			primes.push_back(i) ;
	}
	vector <int> powers(primes.size() , 0) ;
	for(int i = 0 ; i < primes.size() ; i++) {
		int tmp = N ;
		while(tmp != 0) {
			powers[i] = powers[i] + tmp / primes[i] ;
			tmp = tmp / primes[i] ;
		}
	}
	for(int i = 0 ; i < powers.size() - 1 ; i++)
		printf("%d^%d * " , primes[i] , powers[i]) ;
	printf("%d^%d\n" , primes[primes.size() - 1] , powers[primes.size() - 1]) ;
}