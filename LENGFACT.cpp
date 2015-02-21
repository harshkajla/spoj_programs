#include <bits/stdc++.h>
using namespace std ;

double pi = 3.1415926535897932384626433832795028841971693993751058209 ;
double e = 2.718281828459045235360287471352662497757247093699959574966967 ;

int main() {
	int t ;
	unsigned long long res , n ;
	scanf("%d" , &t) ;
	while(t--) {
		scanf("%lld" , &n) ;
		if(n == 0 || n == 1) {
			printf("1\n") ;
			continue ;
		}
		//res = (unsigned long long)1 + (unsigned long long)(floor(0.5 * log10(2 * pi * n) + n * (log10(n * 1.0) - log10(e)))) ;
		res = log10(2 * pi * n) / 2 + n * (log10(n) - log10(e)) ;
		res++ ;
		printf("%lld\n" , res) ;
	}
}