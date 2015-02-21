#include <iostream>
#include <stdio.h>
using namespace std ;

int main () {
	int N ;
	while(true) {
		scanf("%d" , &N) ;
		if(N == -1)
			break ;
		int a[N] ;
		int sum = 0 ;
		for(int i = 0 ; i < N ; i++) {
			scanf("%d" , &a[i]) ;
			sum = sum + a[i] ;
		}
		if(sum % N != 0) {
			printf("-1\n") ;
			continue ;
		}
		sum = sum / N ;
		int count = 0 ;
		for(int i = 0 ; i < N ; i++) {
			if(a[i] > sum)
				count = count + a[i] - sum ;
		}
		printf("%d\n" , count) ;
	}
}
