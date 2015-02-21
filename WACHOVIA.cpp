#include <bits/stdc++.h>
using namespace std ;

const int UNSOLVED = INT_MIN ;

int solve(int K , int last , vector < vector <int> >& ans , vector <int>& weight , vector <int>& value) {
	if(last == -1)
		return 0 ;
	if(K <= 0)
		return 0 ;
	if(ans[K][last] == UNSOLVED) {
		if(weight[last] <= K)
			return ans[K][last] = max(value[last] + solve(K - weight[last] , last - 1 , ans , weight , value) , solve(K , last - 1 , ans , weight , value)) ;
		else
			return ans[K][last] = solve(K , last - 1 , ans , weight , value) ;
	}
}

int main() {
	int t , K , M ;
	scanf("%d" , &t) ;
	while(t--) {
		scanf("%d %d" , &K , &M) ;
		vector <int> weight(M) ;
		vector <int> value(M) ;
		for(int i = 0 ; i < M ; i++)
			scanf("%d %d" , &weight[i] , &value[i]) ;
		vector < vector <int> > ans(K + 1 , vector <int>(M , UNSOLVED)) ;
		printf("Hey stupid robber, you can get %d.\n\n" , solve(K , M - 1 , ans , weight , value)) ;
	}
}