#include <bits/stdc++.h>
using namespace std ;

string s ;
const int UNSOLVED = -1 ;

//the tree rooted at root returns the index of its last node
int compute_last_node(int root , vector <int>& last) {
	if(last[root] != UNSOLVED)
		return last[root] ;
	if(s[root] == '0')
		return last[root] = root ;
	if(s[root] == '1')
		return last[root] = compute_last_node(root + 1 , last) ;
	if(s[root] == '2')
		return last[root] = compute_last_node(compute_last_node(root + 1 , last) + 1 , last) ;
}

int solve_max(int root , bool is_green , vector <int>& last , vector < vector <int> >& ans_max) {
	if(ans_max[root][is_green] != UNSOLVED)
		return ans_max[root][is_green] ;
	if(s[root] == '0') {
		if(is_green)
			return ans_max[root][is_green] = 1 ;
		else
			return ans_max[root][is_green] = 0 ;
	}
	if(s[root] == '1') {
		if(is_green)
			return ans_max[root][is_green] = 1 + solve_max(root + 1 , false , last , ans_max) ;
		else
			return ans_max[root][is_green] = max(solve_max(root + 1 , true , last , ans_max) , solve_max(root + 1 , false , last , ans_max)) ;
	}
	if(s[root] == '2') {
		int r = last[root + 1] + 1 ;
		if(is_green)
			return ans_max[root][is_green] = solve_max(root + 1 , false , last , ans_max) + solve_max(r , false , last , ans_max) + 1 ;
		else
			return ans_max[root][is_green] = max(solve_max(root + 1 , true , last , ans_max) + solve_max(r , false , last , ans_max) , solve_max(root + 1 , false , last , ans_max) + solve_max(r , true , last , ans_max)) ;
	}
}

int solve_min(int root , bool is_green , vector <int>& last , vector < vector <int> >& ans_min) {
	if(ans_min[root][is_green] != UNSOLVED)
		return ans_min[root][is_green] ;
	if(s[root] == '0') {
		if(is_green)
			return ans_min[root][is_green] = 1 ;
		else
			return ans_min[root][is_green] = 0 ;
	}
	if(s[root] == '1') {
		if(is_green)
			return ans_min[root][is_green] = 1 + solve_min(root + 1 , false , last , ans_min) ;
		else
			return ans_min[root][is_green] = min(solve_min(root + 1 , true , last , ans_min) , solve_min(root + 1 , false , last , ans_min)) ;
	}
	if(s[root] == '2') {
		int r = last[root + 1] + 1 ;
		if(is_green)
			return ans_min[root][is_green] = solve_min(root + 1 , false , last , ans_min) + solve_min(r , false , last , ans_min) + 1 ;
		else
			return ans_min[root][is_green] = min(solve_min(root + 1 , true , last , ans_min) + solve_min(r , false , last , ans_min) , solve_min(root + 1 , false , last , ans_min) + solve_min(r , true , last , ans_min)) ;
	}
}

int main() {
	int t ;
	scanf("%d" , &t) ;
	while(t--) {
		cin >> s ;
		vector <int> last(s.length() , UNSOLVED) ;
		for(int i = 0 ; i < s.length() ; i++)
			last[i] = compute_last_node(i , last) ;
		vector < vector <int> > ans_max(s.length() , vector <int>(2 , UNSOLVED)) ;
		vector < vector <int> > ans_min(s.length() , vector <int>(2 , UNSOLVED)) ;
		printf("%d %d\n" , max(solve_max(0 , true , last , ans_max) , solve_max(0 , false , last , ans_max)) , min(solve_min(0 , true , last , ans_min) , solve_min(0 , false , last , ans_min))) ;
	}
}