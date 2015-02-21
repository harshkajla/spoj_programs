#include <iostream>
#include <stdio.h>
using namespace std ;

int main () {
	int n ;
	while(true) {
		scanf("%d" , &n) ;
		if(n == 0)
			break ;
		int res = n * (n + 1) * (2 * n + 1) ;
		res = res / 6 ;
		printf("%d\n" , res) ;
	}
}
