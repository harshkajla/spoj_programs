#include <bits/stdc++.h>
using namespace std ;

int main() {
	int T , r ;
	double res ;
	scanf("%d" , &T) ;
	for(int i = 1 ; i <= T ; i++) {
		scanf("%d" , &r) ;
		res = 4.0 * r * r + 0.25 ;
		printf("Case %d: %.2lf\n" , i , res) ;
	}
}