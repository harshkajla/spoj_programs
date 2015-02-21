#include <iostream>
#include <stdio.h>
using namespace std ;

int main () {
	int t , n ;
	scanf("%d" , &t) ;
	
	while(t--) {
		scanf("%d" , &n) ;
		double fact = 1.0 ;
		int rem = 0 ;
		int a[200] ;
		a[0] = 1 ;
		int m = 1 ;
		int res ;
		for(int i = 1 ; i <= n ; i++) {
			rem = 0 ;
			for(int j = 0 ; j < m ; j++) {
				res = a[j] * i + rem ;
				a[j] = res % 10 ;
				rem = res / 10 ;
			}
			while(rem != 0) {
				a[m++] = rem % 10 ;
				rem = rem / 10 ;
			}
		}
		
		for(int i = m - 1 ; i >= 0 ; i--)
			printf("%d" , a[i]) ;
		printf("\n") ;
	}
}
