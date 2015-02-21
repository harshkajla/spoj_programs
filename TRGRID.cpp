#include <bits/stdc++.h>
using namespace std ;

int main() {
	int T , N , M ;
	scanf("%d" , &T) ;
	while(T--) {
		scanf("%d %d" , &N , &M) ;
		if(N <= M && N % 2 == 1)
			printf("R\n") ;
		else if(N <= M && N % 2 == 0)
			printf("L\n") ;
		else if(N > M && M % 2 == 0)
			printf("U\n") ;
		else if(N > M && M % 2 == 1)
			printf("D\n") ;
	}
}