#include <bits/stdc++.h>
using namespace std ;

double max(double a , double b) {
	if(a > b)
		return a ;
	else
		return b ;
}

int main() {
	int E , F , S , M , E_ , F_ , S_ , M_ ;
	int cakes ;
	while(true) {
		scanf("%d %d %d %d %d %d %d %d" , &E , &F , &S , &M , &E_ , &F_ , &S_ , &M_) ;
		if(E == -1)
			return 0 ;
		cakes = ceil(E * 1.0 / E_) ;
		cakes = max(cakes , ceil(F * 1.0 / F_)) ;
		cakes = max(cakes , ceil(S * 1.0 / S_)) ;
		cakes = max(cakes , ceil(M * 1.0 / M_)) ;
		printf("%d %d %d %d\n" , cakes * E_ - E , cakes * F_ - F , cakes * S_ - S , cakes * M_ - M) ;
	}
}