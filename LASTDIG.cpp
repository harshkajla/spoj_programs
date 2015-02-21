#include <bits/stdc++.h>
using namespace std ;

int result[][4] = {{1,1,1,1},{6,2,4,8},{1,3,9,7},{6,4,6,4},{5,5,5,5},{6,6,6,6},{1,7,9,3},{6,8,4,2},{1,9,1,9}};

int main() {
	int t , a , b ;
	scanf("%d" , &t) ;
	while(t--) {
		scanf("%d %d" , &a , &b) ;
		int last = a % 10 ;
		if(a == 0 && b == 0) {
			printf("1\n") ;
			continue ;
		}
		if(last == 0) {
			printf("0\n") ;
			continue ;
		}
		else if(b == 0) {
			printf("1\n") ;
			continue ;
		}
		else {
			b = b % 4 ;
			printf("%d\n" , result[last - 1][b]) ;
		}
	}
}