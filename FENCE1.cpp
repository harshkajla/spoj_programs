#include <bits/stdc++.h>
#include <cmath>
using namespace std ;

int main() {
	double L ;
	while(true) {
		scanf("%lf" , &L) ;
		if(L == 0)
			break ;
		double res = 0.5 * L * L / M_PI ;
		printf("%.2lf\n" , res);
	}
}