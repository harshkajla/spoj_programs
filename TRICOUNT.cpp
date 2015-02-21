#include <bits/stdc++.h>
using namespace std ;

int main() {
	int T ;
	unsigned long long res , N ;
	scanf("%d" , &T) ;
	while(T--) {
		scanf("%lld" , &N) ;
		if(N % 2 == 0)
			res = N * (N + 2) * (2 * N + 1) / 8 ;
		else
			res = (N * (N + 2) * (2 * N + 1) - 1) / 8 ;
		printf("%lld\n" , res) ;
	}
}