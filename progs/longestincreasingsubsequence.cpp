#include <iostream>
#include <stdio.h>
using namespace std ;

int main () {
	int n ;
	scanf("%d" , &n) ;
	int a[n] , l[n] ;
	for(int i = 0 ; i < n ; i++) {
		scanf("%d" , &a[i]) ;
	}
	int max ;
	for(int i = n - 1 ; i >= 0 ; i--) {
		l[i] = 1 ;
		for(int j = i + 1 ; j < n ; j++) {
			if(a[j] >= a[i])
				if(l[j] >= l[i])
					l[i] = 1 + l[j] ;
		}
	}
	max = l[0] ;
	for(int i = 1 ; i < n ; i++)
		if(l[i] > max)
			max = l[i] ;
	printf("%d\n" , max) ;
}
