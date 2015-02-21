#include <bits/stdc++.h>
using namespace std ;

const int UNSOLVED = numeric_limits <short> :: max() ;
string s ;

short solve(int start , int end , vector < vector <short> >& ans) {
	if(start >= end)
		return 0 ;
	if(ans[start][end] == UNSOLVED) {
		if(s[start] == s[end])
			ans[start][end] = solve(start + 1 , end - 1 , ans) ;
		else
			ans[start][end] = 1 + min(solve(start + 1 , end , ans) , solve(start , end - 1 , ans)) ;
	}
	return ans[start][end] ;
}

int main() {
	int t ;
	scanf("%d" , &t) ;
	while(t--) {
		cin >> s ;
		int l = s.length() ;
		vector < vector <short> > ans(l , vector <short>(l , UNSOLVED)) ;
		printf("%d\n" , solve(0 , l - 1 , ans)) ;
	}
}