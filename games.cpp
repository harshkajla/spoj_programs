#include <iostream>
#include <stdio.h>
using namespace std ;

int main() {
	int t ;
	double avg ;
	scanf("%d" , &t) ;
	while(t--) {
		scanf("%lf" , &avg) ;
		for(int i = 1 ; ; i++) {
			double k = avg * i ;
			double p = k - (int)k ;
			if(p == 0.0) {
				printf("%d\n" , i) ;
				break ;
			}
		}
	}
}