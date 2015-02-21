#include <bits/stdc++.h>
using namespace std ;

int S , N ;
vector <int> size , value ;
const int UNSOLVED = INT_MIN ;

unsigned long long solve(int last , int w , vector < vector <int> >& ans) {
	if(last == -1)
		return 0 ;
	if(w <= 0)
		return 0 ;
	if(ans[last][w] == UNSOLVED) {
		if(size[last] > w)
			ans[last][w] = solve(last - 1 , w , ans) ;
		else
			ans[last][w] = max(solve(last - 1 , w , ans) , solve(last - 1 , w - size[last] , ans) + value[last]) ;
	}
	return ans[last][w] ;
}

int main() {
	scanf("%d %d" , &S , &N) ;
	size.resize(N) ;
	value.resize(N) ;
	vector < vector <int> > ans(N , vector <int>(S + 1 , UNSOLVED)) ;
	for(int i = 0 ; i < N ; i++)
		scanf("%d %d" , &size[i] , &value[i]) ;
	printf("%lld\n" , solve(N - 1 , S , ans)) ;
}