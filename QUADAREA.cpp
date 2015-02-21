#include <bits/stdc++.h>
using namespace std ;

int main() {
	int T ;
	double a , b , c , d ;
	double area ;
	scanf("%d" , &T) ;
	while(T--) {
		scanf("%lf %lf %lf %lf" , &a , &b , &c , &d) ;
		area = 0.25 * sqrt((b + c + d - a) * (a + c + d - b)) * sqrt((a + b + d - c) * (a + b + c - d)) ;
		printf("%lf\n" , area) ;
	}
}