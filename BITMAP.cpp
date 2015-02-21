#include <bits/stdc++.h>
using namespace std ;

int t , n , m ;
const int UNSOLVED = numeric_limits <int> :: max() ;

int solve(int i , int j , vector < vector <int> >& least , vector < vector <char> >& pixel) {
	if(i < 0 || i >= n || j < 0 || j >= m)
		return UNSOLVED ;
	if(least[i][j] == UNSOLVED) {
		if(pixel[i][j] == '1')
			return 0 ;
		else {
			least[i][j] = min(least[i][j] , solve(i - 1 , j - 1 , least , pixel)) ;
			least[i][j] = min(least[i][j] , solve(i - 1 , j , least , pixel)) ;
			least[i][j] = min(least[i][j] , solve(i - 1 , j + 1 , least , pixel)) ;
			least[i][j] = min(least[i][j] , solve(i , j - 1 , least , pixel)) ;
			least[i][j] = min(least[i][j] , solve(i , j + 1 , least , pixel)) ;
			least[i][j] = min(least[i][j] , solve(i + 1 , j - 1 , least , pixel)) ;
			least[i][j] = min(least[i][j] , solve(i + 1 , j , least , pixel)) ;
			least[i][j] = min(least[i][j] , solve(i + 1 , j + 1 , least , pixel)) ;
			least[i][j] = least[i][j] + 2 ;
		}
	}
	return least[i][j] ;
}

int main() {
	scanf("%d" , &t) ;
	while(t--) {
		scanf("%d %d" , &n , &m) ;
		vector < vector <char> > pixel(n , vector <char> (m)) ;
		for(int i = 0 ; i < n ; i++) {
			string s ;
			cin >> s ;
			for(int j = 0 ; j < m ; j++) {
				pixel[i][j] = s[j] ;
			}
		}
		vector < vector <int> > least(n , vector <int>(m , UNSOLVED)) ;
		
		for(int i = 0 ; i < n ; i++) {
			for(int j = 0 ; j < m ; j++) {
				if(pixel[i][j] == '1')
					least[i][j] = 0 ;
			}
		}
		for(int i = 0 ; i < n ; i++) {
			for(int j = 0 ; j < m ; j++) {
				least[i][j] = solve(i , j , least , pixel) ;
			}
		}
		for(int i = 0 ; i < n ; i++) {
			for(int j = 0 ; j < m ; j++) {
				printf("%d " , least[i][j]) ;
			}
			printf("\n") ;
		}
	}
}