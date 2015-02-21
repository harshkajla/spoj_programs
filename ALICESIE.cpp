#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std ;

int main() {
	int T , N ;
	scanf("%d" , &T) ;

	while(T--) {
		scanf("%d" , &N) ;
		printf("%d\n" , (N + 1) / 2) ;
	}
}