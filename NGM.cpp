#include <bits/stdc++.h>
using namespace std ;

int main() {
	int N ;
	scanf("%d" , &N) ;
	if(N == 0) {
		printf("1\n") ;
		printf("0\n") ;
		return 0 ;
	}
	if(N % 10 == 0)
		printf("2\n") ;
	else {
		printf("1\n") ;
		printf("%d\n" , N % 10) ;
	}
}