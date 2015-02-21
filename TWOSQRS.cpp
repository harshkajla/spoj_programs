#include <bits/stdc++.h>
using namespace std ;

int main() {
	int c ;
	unsigned long long n ;
	scanf("%d" , &c) ;
	vector <unsigned long long> squares(1000001) ;
	for(int i = 0 ; i <= 1000000 ; i++)
		squares[i] = (unsigned long long)i * (unsigned long long)i ;
	while(c--) {
		scanf("%lld" , &n) ;
		bool ispossible = false ;
		for(int i = 0 ; i <= 1000000 ; i++) {
			if(n <= squares[i]) {
				ispossible = false ;
				break ;
			}
			else {
				unsigned long long tmp = sqrt(n - squares[i]) ;
				if(tmp * tmp == n - squares[i]) {
					ispossible = true ;
					break ;
				}
			}
		}
		if(ispossible)
			printf("Yes\n") ;
		else
			printf("No\n") ;
	}
}