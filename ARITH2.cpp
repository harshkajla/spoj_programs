#include <bits/stdc++.h>
using namespace std ;

int main() {
	int T ;
	char c1 , c2 ;
	unsigned long long res , tmp ;
	scanf("%d" , &T) ;
	while(T--) {
		res = 0 ;
		scanf("%lld" , &tmp) ;
		cin >> c2 ;
		if(c2 == '=') {
			printf("%lld\n" , tmp) ;
			continue ;
		}
		res = tmp ;
		while(true) {
			c1 = c2 ;
			scanf("%lld" , &tmp) ;
			cin >> c2 ;
			if(c1 == '+')
				res = res + tmp ;
			else if(c1 == '-')
				res = res - tmp ;
			else if(c1 == '/')
				res = res / tmp ;
			else if(c1 == '*')
				res = res * tmp ;
			if(c2 == '=') {
				printf("%lld\n" , res) ;
				break ;
			}
		}
	}
}