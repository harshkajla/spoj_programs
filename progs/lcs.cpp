#include <iostream>
#include <stdio.h>
using namespace std ;

int main() {
	int m , n ;
	scanf("%d" , &m) ;
	scanf("%d" , &n) ;
	int a[m] , b[n] , c[m + 1][n + 1] ;
	for(int i = 0 ; i < m ; i++)
		scanf("%d" , &a[i]) ;
	for(int i = 0 ; i < n ; i++)
		scanf("%d" , &b[i]) ;
	//c[i][j] stores the length of lcs of a[0 .. i - 1] & b[0 .. j - 1]
	for(int i = 0 ; i <= m ; i++)
		c[i][0] = 0 ;
	for(int j = 1 ; j <= n ; j++)
		c[0][j] = 0 ;
	for(int i = 1 ; i <= m ; i++) {
		for(int j = 1 ; j <= n ; j++) {
			if(a[i - 1] == b[j - 1])
				c[i][j] = 1 + c[i - 1][j - 1] ;
			else
				c[i][j] = max(c[i - 1][j] , c[i][j - 1]) ;
		}
	}
	cout << c[m][n] << endl ;
}
