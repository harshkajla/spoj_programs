#include <bits/stdc++.h>
using namespace std ;

int main() {
	string inp ;
	int n ;
	while(true) {
		cin >> inp ;
		if(inp == "00e0")
			break ;
		n = (10 * (inp[0] - '0') + (inp[1] - '0')) * (int)pow(10 , inp[3] - '0') ;
		int m = n , p = 0 ;
		while(m != 0) {
			m = m >> 1 ;
			p++ ;
		}
		p = pow(2 , p - 1) ;
		printf("%d\n" , 1 + (n - p) * 2) ;
	}
}