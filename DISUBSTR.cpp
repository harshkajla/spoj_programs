#include <bits/stdc++.h>
using namespace std ;

int n ;

int rem() {
	return n % -2 ;
}

int main() {
	scanf("%d" , &n) ;
	string ans = "" ;
	while(n != 0) {
		ans = (char)(rem + '0') + ans ;
		n = n / (-2) ;
	}
}