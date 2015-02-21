#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits>
using namespace std ;

int h , w ;

int solve(int x , int y , vector < vector <int> >& chamber , vector < vector <int> >& ans) {
	if(x == h - 1 && y >= 0 && y < w)
		return chamber[x][y] ;
	if(x < 0 || x >= h || y < 0 || y >= w)
		return numeric_limits <int> :: max() ;
	if(ans[x][y] == -1) {
		ans[x][y] = chamber[x][y] + min(min(solve(x + 1 , y - 1 , chamber , ans) , solve(x + 1 , y , chamber , ans)) , solve(x + 1 , y + 1 , chamber , ans)) ;
	}
	return ans[x][y] ;
}

int main() {
	scanf("%d %d" , &h , &w) ;
	vector < vector <int> > chamber(h , vector <int>(w)) ;
	vector < vector <int> > ans(h , vector <int>(w , -1)) ;
	for(int i = 0 ; i < h ; i++)
		for(int j = 0 ; j < w ; j++)
			scanf("%d" , &chamber[i][j]) ;
	int count = numeric_limits <int> :: max() ;
	for(int j = 0 ; j < w ; j++)
		count = min(count , solve(0 , j , chamber , ans)) ;
	printf("%d\n" , count) ;
}