#include <bits/stdc++.h>
using namespace std ;

string stick ;
const int UNSOLVED = INT_MIN ;

bool is_more_sweet(int start , int end) {
	int count = 0 ;
	for(int i = start ; i <= end ; i++)
		if(stick[i] == '1')
			count++ ;
	if(count > (end - start + 1) / 2)
		return true ;
	else
		return false ;
}

int break_stick(int start , int end , vector < vector <int> >& ans) {
	if(start > end)
		return 0 ;
	if(start == end) {
		if(stick[start] == '1')
			return 1 ;
	}
	if(ans[start][end] == UNSOLVED) {
		for(int i = start ; i <= end ; i++) {
			if(is_more_sweet(start , i))
				ans[start][end] = max((i - start + 1) + break_stick(i + 1 , end , ans) , ans[start][end]) ;
			else
				ans[start][end] = max(break_stick(i + 1 , end , ans) , ans[start][end]) ;
		}
	}
	return ans[start][end] ;
}

int main() {
	int t , N ;
	scanf("%d" , &t) ;
	while(t--) {
		scanf("%d" , &N) ;
		vector < vector <int> > ans(N , vector <int> (N , UNSOLVED)) ;
		cin >> stick ;
		printf("%d\n" , break_stick(0 , N - 1 , ans)) ;
	}
}