#include <bits/stdc++.h>
#define sn(n) scanf("%d" , &n)
using namespace std ;

int main() {
	int n ;
	while(true) {
		sn(n) ;
		if(n == -1)
			return 0 ;
		int t1 = (3 + sqrt(12.0 * n - 3)) / 6 ;
		int t2 = (3 - sqrt(12.0 * n - 3)) / 6 ;
		if(3 * t1 * (t1 - 1) + 1 == n || 3 * t2 * (t2 - 1) + 1 == n)
			printf("Y\n") ;
		else
			printf("N\n") ;
	}
}