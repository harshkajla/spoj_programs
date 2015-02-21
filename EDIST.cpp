#include <bits/stdc++.h>
using namespace std ;

string A , B ;


int dist(int m , int n , vector < vector <int> >& ans) {
	if(m == 0)
		return n ;
	else if(n == 0)
		return m ;
	if(ans[m][n] == -1) {
		ans[m][n] = min(dist(m - 1 , n , ans) , dist(m , n - 1 , ans)) + 1 ;
		if(A[m - 1] == B[n - 1])
			ans[m][n] = min(ans[m][n] , dist(m - 1 , n - 1 , ans)) ;
		else
			ans[m][n] = min(ans[m][n] , dist(m - 1 , n - 1 , ans) + 1) ;
	}
	return ans[m][n] ;
}

int main() {
	int T , m , n ;
	scanf("%d" ,  &T) ;
	while(T--) {
		cin >> A ;
		cin >> B ;
		int m = A.length() ;
		int n = B.length() ;
		vector < vector <int> > ans(m + 1 , vector <int>(n + 1 , -1)) ;
		printf("%d\n" , dist(m , n , ans)) ;
	}
}