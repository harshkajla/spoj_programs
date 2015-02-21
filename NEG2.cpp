#include <bits/stdc++.h>
using namespace std ;

int n ;

int rem() {
	if(n > 0)
		return n % -2 ;
	else
		return (-1 * n) % 2 ;
}

int main() {
	scanf("%d" , &n) ;
	if(n == 0) {
		printf("0\n") ;
		return 0 ;
	}
	string ans = "" ;
	while(n != 0) {
		ans = (char)(rem() + '0') + ans ;
		n = (n - rem()) / (-2) ;
	}
	cout << ans << endl ;
}