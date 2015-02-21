#include <bits/stdc++.h>
using namespace std ;

vector <int> p ;
int N ;
vector < vector <int> > cache ;

int profit(int left , int right) {
	if(left > right)
		return 0 ;
	int year = N - (right - left + 1) + 1 ;
	if(cache[left][right] == -1)
		cache[left][right] = max(profit(left + 1 , right) + year * p[left] , profit(left , right - 1) + year * p[right]) ;
	return cache[left][right] ;
}

int main() {
	scanf("%d" , &N) ;
	p.resize(N) ;
	cache.resize(N) ;
	for(int i = 0 ; i < N ; i++) {
		cache[i].resize(N) ;
		for(int j = 0 ; j < N ; j++)
			cache[i][j] = -1 ;
	}
	for(int i = 0 ; i < N ; i++)
		scanf("%d" , &p[i]) ;
	cout << profit(0 , N - 1) << endl ;
}