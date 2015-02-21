#include <bits/stdc++.h>
using namespace std ;

vector < vector <int> > S(101 , vector <int> (101 , -1)) ;
vector < vector <int> > A(101 , vector <int> (101 , -1)) ;
vector < vector <int> > B(101 , vector <int> (101 , -1)) ;
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

int solve_A(int n , int k) {
	if(A[n][k] != -1)
		return A[n][k] ;
	return A[n][k] = solve_B(n - 1 , k) + solve_S(n - 3 , k) ;
	
}

int solve_B(int n , int k) {
	if(B[n][k] != -1)
		return B[n][k] ;
}

int solve_S(int n , int k) {
	if(S[n][k] != -1)
		return S[n][k] ;
	int ans_ ;
	if(n == 0 || n == 1) {
		ans_ = 0 ;
	}
	else if(k == 0) {
		ans_ = fib(n) ;
	}
	else {
		ans_ = 2 * solve(n - 2 , k) + solve_A(n , k) + solve_B(n , k) ;
		answer[n][k] = ans_ ;
	}
	return ans_ ;
}

int main() {
	int T , z = 1 , n , k ;
	scanf("%d" , &T) ;
	while(T--) {
		scanf("%d %d %d" , &z , &n , &k) ;
		printf("%d %d\n" , z , solve(n , k)) ;
	}
}