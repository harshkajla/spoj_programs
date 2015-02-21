#include <bits/stdc++.h>
using namespace std ;

int n , left ;
vector <int> parts ;

int check[101][101] ;

bool breakable(int x , int y , vector <bool> done) {
	if(left == 0)
		return true ;
	for(int i = 0 ; i < n ; i++) {
		if(done[i] == false) {
			if(parts[i] % x == 0) {
				return breakable()
			}
		}
	}
}

int main() {
	while(true) {
		vector <bool> done ;
		scanf("%d" , &n) ;
		if(n == 0)
			break ;
		scanf("%d %d" , &x , &y) ;
		parts.resize(n) ;
		done.resize(n) ;
		for(int i = 0 ; i < n ; i++)
			done[i] = false ;
		left = n ;
		for(int i = 0 ; i < n ; i++) {
			scanf("%d" , &parts[i]) ;
		}
		for(int i = 0 ; i <= 100 ; i++)
			for(int j = 0 ; j <= 100 ; j++)
				check[i][j] = -1 ;
		check[0][0] = 1 ;
		if(breakable(x , y , done))
			printf("YES\n") ;
		else
			printf("NO\n") ;
	}
}