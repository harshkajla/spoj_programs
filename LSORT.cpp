#include <bits/stdc++.h>
using namespace std ;

int N ;
const int UNSOLVED = INT_MAX ;

int min_cost_to_build(int i , int j , vector < vector <int> > ans) {
	if(j < i)
		return 0 ;
	if(ans[i][j] == UNSOLVED)
		return min(min_cost_to_build(i + 1 , j , ans) , min_cost_to_build(i , j - 1 , ans)) ;
	return ans[i][j] ;
}

int main() {
	int T ;
	scanf("%d" , &T) ;
	while(T--) {
		scanf("%d" , &N) ;
		vector <int> P(N) ;
		for(int i = 0 ; i < N ; i++)
			scanf("%d" , &P[i]) ;
		vector < vector <int> > ans(N + 1 , vector <int>(N + 1 , UNSOLVED)) ;
		printf("%d\n" , min_cost_to_build(1 , N , ans)) ;
	}
}