#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std ;

int main() {
	int T , n ;
	scanf("%d" , &T) ;
	while(T--) {
		scanf("%d" , &n) ;
		int m = 1 + ceil(log10(n) / log10(2)) ;
		printf("%d\n" , m) ;
	}
}