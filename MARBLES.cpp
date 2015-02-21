#include <bits/stdc++.h>
using namespace std ;

int n , k ;

unsigned long long ncr(int n , int r) {
	if(r == 0)
		return 1 ;
	if(r == 1)
		return n ;
	vector <unsigned long long> prev(r + 1) ;
	for(int i = 1 ; i <= r ; i++)
		prev[i] = 0 ;
	prev[0] = 1 ;
	for(int i = 1 ; i <= n ; i++) {
		unsigned long long a = prev[0] , b = prev[1] , c = prev[2] ;
		for(int j = 1 ; j < r - 1 ; j++) {
			prev[j] = a + b ;
			a = b ;
			b = c ;
			c = prev[j + 2] ;
		}
		prev[r - 1] = a + b ;
		prev[r] = b + c ;
	}
	return prev[r] ;
}

int main() {
	int T ;
	scanf("%d" , &T) ;
	while(T--) {
		scanf("%d %d" , &n , &k) ;
		printf("%lld\n" , ncr(n - 1 , min(k - 1 , n - k))) ;
	}
}