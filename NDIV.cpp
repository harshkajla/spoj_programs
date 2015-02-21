#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std ;

int primes[10000] ;
int check[32000] ;

void sieve() {
	for(int i = 3 ; i <= 180 ; i += 2)
        if(!check[i])
            for(int j = i * i ; j <= 32000 ; j += i)
                check[j] = 1 ;
    primes[0] = 2 ;
    int j = 1 ;
    for(int i = 3 ; i <= 32000 ; i += 2)
        if(!check[i])
            primes[j++] = i ;
}

int main() {
	int a , b , n ;
	scanf("%d" , &a) ;
	scanf("%d" , &b) ;
	scanf("%d" , &n) ;
	int res = 0 ;
	sieve() ;
	for(int i = a ; i <= b ; i++) {
		int total = 1 ;
		int k = 0 ;
		int num = i ;
		for(int j = primes[k] ; j * j <= i ; j = primes[++k]) {
			int count = 0 ;
			while(num % j == 0) {
				num = num / j ;
				count++ ;
			}
			total = total * (count + 1) ;
		}
		if(num != 1)
			total = total * 2 ;
		if(total == n)
			res++ ;
	}
	printf("%d\n" , res) ;
}