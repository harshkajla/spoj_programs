#include <bits/stdc++.h>
using namespace std ;

int main() {
	int T ;
	unsigned long long N , res ;
	scanf("%d" , &T) ;
	while(T--) {
		scanf("%lld" , &N) ;
		res = (3 * N * (N - 1) / 2 + 2 * N) % 1000007 ;
		printf("%lld\n" , res) ;
	}
}