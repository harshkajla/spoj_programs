#include <bits/stdc++.h>
using namespace std ;

int main() {
	double c , hang ;
	int n ;
	while(true) {
		scanf("%lf" , &c) ;
		if(c == 0.00)
			break ;
		hang = 0.0 ;
		for(int i = 2 ; ; i++) {
			hang = hang + 1.0 / i ;
			if(hang >= c) {
				n = i + 1 ;
				break ;
			}
		}
		printf("%d card(s)\n" , n - 2) ;
	}
}