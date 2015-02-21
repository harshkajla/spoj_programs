#include <bits/stdc++.h>
using namespace std ;

const unsigned long long UNSOLVED = numeric_limits <unsigned long long> :: max() ;
int n ;

unsigned long long smoke(int lo , int hi , vector < vector <unsigned long long> >& ans , vector < vector <int> >& col) {
	if(ans[lo][hi] == UNSOLVED) {
		for(int i = lo ; i < hi ; i++) {
			ans[lo][hi] = min(ans[lo][hi] , smoke(lo , i , ans , col) + smoke(i + 1 , hi , ans , col) + (unsigned long long)col[lo][i] * col[i + 1][hi]) ;
		}
	}
	return ans[lo][hi] ;
}

int main() {
	while(cin >> n) {
		vector <int> colour(n) ;
		vector < vector <unsigned long long> > ans(n , vector <unsigned long long>(n , UNSOLVED)) ;
		vector < vector <int> > col(n , vector <int>(n)) ;
		for(int i = 0 ; i < n ; i++) {
			scanf("%d" , &colour[i]) ;
			ans[i][i] = 0 ;
			col[i][i] = colour[i] ;
		}
		for(int i = 0 ; i < n ; i++) {
			for(int j = i + 1 ; j < n ; j++) {
				col[j][i] = col[i][j] = (col[i][j - 1] + colour[j]) % 100 ;
			}
		}
		printf("%lld\n" , smoke(0 , n - 1 , ans , col)) ;
	}
}