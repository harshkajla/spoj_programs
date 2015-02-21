#include <bits/stdc++.h>
using namespace std ;

const int p = 10000007 ;
int data[101][101] ;

void solve() {
	for(int i = 0 ; i <= 100 ; i++)
		for(int j = 1 ; j <= 100 ; j++)
			data[i][j] = 0 ;
	for(int i = 0 ; i <= 100 ; i++)
		data[i][0] = 1 ;
	data[1][0] = 1 ;
	data[1][1] = 1 ;
	for(int i = 2 ; i <= 100 ; i++) {
		for(int j = 0 ; j <= i ; j++)
			data[i][j] = (data[i - 1][j] + data[i - 1][j - 1]) % p ;
	}
}

int ncr(int n , int r) {
	if(n < r || n == 0)
		return 0 ;
	if(r == 0)
		return 1 ;
	r = max(r , n - r) ;
	return data[n][r] ;
}

int main() {
	solve() ;
	int n , r ;
	scanf("%d %d" , &n , &r) ;
	if(n < r)
		printf("-1\n") ;
	else
		printf("%d\n" , ncr(n - 1 , r - 1)) ;
}