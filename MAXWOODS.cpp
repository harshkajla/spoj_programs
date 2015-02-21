#include <bits/stdc++.h>
using namespace std ;
int m , n ;
int solve(int x , int y , vector < vector <char> >& grid , vector < vector <int> >& answer_right , vector < vector <int> >& answer_left , bool is_right , vector < vector <bool> >& solved_right , vector < vector <bool> >& solved_left) {
	if(x >= m || y >= n || x < 0 || y < 0)
		return 0 ;
	if(is_right && solved_right[x][y])
		return answer_right[x][y] ;
	if((!is_right) && solved_left[x][y])
		return answer_left[x][y] ;
	if(grid[x][y] == '#') {
		solved_left[x][y] = true ;
		solved_right[x][y] = true ;
		return 0 ;
	}
	if(is_right) {
		answer_right[x][y] = max(solve(x , y + 1 , grid , answer_right , answer_left , true , solved_right , solved_left) , solve(x + 1 , y , grid , answer_right , answer_left , false , solved_right , solved_left)) ;
		if(grid[x][y] == 'T')
			answer_right[x][y]++ ;
		solved_right[x][y] = true ;
		return answer_right[x][y] ;
	}
	else {
		answer_left[x][y] = max(solve(x , y - 1 , grid , answer_right , answer_left , false , solved_right , solved_left) , solve(x + 1 , y , grid , answer_right , answer_left , true , solved_right , solved_left)) ;
		if(grid[x][y] == 'T')
			answer_left[x][y]++ ;
		solved_left[x][y] = true ;
		return answer_left[x][y] ;
	}
}
int main() {
	int t ;
	scanf("%d" , &t) ;
	while(t--) {
		scanf("%d %d" , &m , &n) ;
		vector < vector <char> > grid(m , vector <char>(n)) ;
		for(int i = 0 ; i < m ; i++)
			for(int j = 0 ; j < n ; j++)
				cin >> grid[i][j] ;
		vector < vector <int> > answer_right(m , vector <int>(n)) ;
		vector < vector <int> > answer_left(m , vector <int>(n)) ;
		vector < vector <bool> > solved_left(m , vector <bool>(n , false)) ;
		vector < vector <bool> > solved_right(m , vector <bool>(n , false)) ;
		printf("%d\n\n" , solve(0 , 0 , grid , answer_right , answer_left , true , solved_right , solved_left)) ;		
	}
}