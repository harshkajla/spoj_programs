#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std ;

unsigned long long a[10000000] ;
int f[10000000] ;
vector <bool> is_done(10000000 , false) ;

void sieve() {
	for(int i = 2 ; i < 10000000 ; i++) {
		if(is_done[i] == false) {
			for(int j = i ; j < 10000000 ; j = j + i) {
				if(is_done[j] == false) {
					is_done[j] = true ;
					f[j] = i ;
				}
			}
			a[i] = a[i - 1] + i ;
		}
		else
			a[i] = a[i - 1] + f[i] ;
	}
}

int main() {
	int T , N ;
	scanf("%d" , &T) ;
	a[0] = 0 ;
	a[1] = 0 ;
	sieve() ;
	int done = 1 ;
	while(T--) {
		scanf("%d" , &N) ;
		printf("%lld\n", a[N]);
	}
}