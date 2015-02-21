#include <bits/stdc++.h>
using namespace std ;

int budget , n ;
int min_cost ;

int solve(vector <int>& fees , vector <int>& fun , vector < vector <int> >& ans) {
	for(int j = 0 ; j <= n ; j++)
		ans[0][j] = 0 ;
	for(int i = 0 ; i <= budget ; i++)
		ans[i][0] = 0 ;
	for(int i = 1 ; i <= budget ; i++) {
		for(int j = 1 ; j <= n ; j++) {
			if(fees[j] <= i)
				ans[i][j] = max(ans[i - fees[j]][j - 1] + fun[j] , ans[i][j - 1]) ;
			else
				ans[i][j] = ans[i][j - 1] ;
		}
	}
	min_cost = budget ;
	while(ans[min_cost][n] == ans[min_cost - 1][n])
		min_cost-- ;
	return ans[budget][n] ;
}

int main() {
	while(true) {
		scanf("%d %d" , &budget , &n) ;
		if(budget == 0 && n == 0)
			return 0 ;
		vector <int> fees(n + 1) , fun(n + 1) ;
		vector < vector <int> > ans(budget + 1 , vector <int> (n + 1 , -1)) ;
		for(int i = 1 ; i <= n ; i++)
			scanf("%d %d" , &fees[i] , &fun[i]) ;
		printf("%d %d\n" , min_cost , solve(fees , fun , ans)) ;
	}
}