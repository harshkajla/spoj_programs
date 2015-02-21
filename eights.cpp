#include <iostream>
#include <stdio.h>
using namespace std ;
//1 , 4 , 6 , 9 , 11 , 14 , 16 , 19 , 21 , 24
//1 , 2 , 3 , 4 , 5  , 6  , 7  , 8  , 9  , 10
int main() {
	int t ;
	scanf("%d" , &t) ;
	unsigned long long k , n  ;
	while(t--) {
		scanf("%lld" , &k) ;
		if(k % 2 == 1) {
			k = (k + 1) / 2 ;
			n = (1 + (k - 1) * 5) * 100 + 92 ;
		}
		else {
			k = k / 2 ;
			n = (4 + (k - 1) * 5) * 100 + 42 ;
		}
		printf("%lld\n" , n) ;
	}
}
