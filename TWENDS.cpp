#include <bits/stdc++.h>
using namespace std ;

const int UNSOLVED = INT_MAX ;
int score1 , score2 ;

int play(int i , int j , vector <int>& data , vector < vector <int> >& ans) {
	if(i + 1 == j)
		return max(data[i] , data[j]) - min(data[i] , data[j]) ;
	int pi , pj ;
	if(ans[i][j] != UNSOLVED)
		return ans[i][j] ;
	if(data[i + 1] >= data[j])
		pi = play(i + 2 , j , data , ans) + data[i] - data[i + 1] ;
	else
		pi = play(i + 1 , j - 1 , data , ans) + data[i] - data[j] ;
	if(data[i] >= data[j - 1])
		pj = play(i + 1 , j - 1 , data , ans) + data[j] - data[i] ;
	else
		pj = play(i , j - 2 , data , ans) + data[j] - data[j - 1] ;
	return ans[i][j] = max(pi , pj) ;
}

int main() {
	int n ;
	int count = 0 ;
	while(true) {
		scanf("%d" , &n) ;
		if(n == 0)
			break ;
		vector < vector <int> > ans(n , vector <int>(n , UNSOLVED)) ;
		count++ ;
		score1 = score2 = 0 ;
		vector <int> data(n) ;
		for(int i = 0 ; i < n ; i++)
			scanf("%d" , &data[i]) ;
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n" , count , play(0 , n - 1 , data , ans)) ;
	}
}