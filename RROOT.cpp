#include <bits/stdc++.h>
using namespace std ;

int main() {
	int T ;
	double S , p ;
	scanf("%d" , &T) ;
	while(T--) {
		scanf("%lf" , &S) ;
		if(S <= 2.00)
			p = 0.5 + S / 12.0 ;
		else
			p = 1 - sqrt(2) / (3.0 * sqrt(S)) ;
		printf("%.6lf\n" , p) ;
	}
}