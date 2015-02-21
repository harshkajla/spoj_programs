#include <bits/stdc++.h>
using namespace std ;

int main() {
	int t , n ;
	scanf("%d" , &t) ;
	while(t--) {
		scanf("%d" , &n) ;
		double res = 0.0 ;
		for(int i = 1 ; i <= n ; i++)
			res = res + (n * 1.0) / i ;
		printf("%.2lf\n", res) ;
	}
}