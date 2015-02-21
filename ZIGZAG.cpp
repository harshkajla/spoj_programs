#include <bits/stdc++.h>
typedef unsigned long long ull ;
using namespace std ;

ull N ;

int main() {
	ull K ;
	scanf("%lld %lld" , &N , &K) ;
	ull sum = 0 ;
	char c ;
	ull x = 0 , y = 0 ;
	for(ull i = 0 ; i <= K ; i++) {
		scanf("%c" , &c) ;
		if(c == 'D')
			x++ ;
		else if(c == 'R')
			y++ ;
		else if(c == 'L')
			y-- ;
		else if(c == 'U')
			x-- ;
		sum = sum + ((x + y < N) ? (1 + (x + y + 1) * (x + y) / 2 + ((x + y) % 2 == 0 ? y : x)) : (N * N + 1 - (1 + (N - x - 1 + N - y - 1 + 1) * (N - x - 1 + N - y - 1) / 2 + ((N - x - 1 + N - y - 1) % 2 == 0 ? (N - y - 1) : (N - x - 1))))) ;
	}
	printf("%lld\n" , sum) ;
}