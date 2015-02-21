#include <bits/stdc++.h>
using namespace std ;

vector <int> ans(100 , -1) ;

int fib(int n) {
	if(n == 1)
		return 2 ;
	if(n == 2)
		return 3 ;
	if(ans[n] == -1)
		ans[n] = fib(n - 1) + fib(n - 2) ;
	return ans[n] ;
}

int main() {
	while(true) {
		int n ;
		cin >> n ;
		cout << fib(n) << endl ;
	}
}

