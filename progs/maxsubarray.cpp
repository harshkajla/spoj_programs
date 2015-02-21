#include <iostream>
#include <stdio.h>
using namespace std ;

int main() {
	int n ;
	scanf("%d" , &n) ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++)
		scanf("%d" , &a[i]) ;
		
	int max_ending_here = a[0] , max_so_far = a[0] ;
	for(int i = 1 ; i < n ; i++) {
		max_ending_here = max(a[i] , max_ending_here + a[i]) ;
		max_so_far = max(max_so_far , max_ending_here) ;
	}
	printf("%d\n" , max_so_far) ;
}
