#include <bits/stdc++.h>
using namespace std ;

int main() {
	int T ;
	unsigned long long a , b , c ;
	scanf("%d" , &T) ;
	while(T--) {
		scanf("%lld %lld %lld" , &a , &b , &c) ;
		printf("%lld\n" , a * a - 2 * b) ;
	}
}