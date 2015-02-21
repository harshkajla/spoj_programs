#include <bits/stdc++.h>
using namespace std ;

int data[13][67] ;

void solve() {
	for(int i = 1 ; i <= 12 ; i++)
		for(int j = 0 ; j <= 66 ; j++)
			data[i][j] = 0 ;
	data[1][0] = 1 ;
	data[2][0] = 1 ;
	data[2][1] = 1 ;
	for(int i = 3 ; i <= 12 ; i++) {
		for(int j = 0 ; j <= 66 ; j++) {
			for(int k = 0 ; k <= i - 1 ; k++) {
				data[i][j + k] = data[i][j + k] + data[i - 1][j] ;
			}
		}
	}
}

int main() {
	solve() ;
	int d , n , k ;
	scanf("%d" , &d) ;
	while(d--) {
		scanf("%d %d" , &n , &k) ;
		printf("%d\n" , data[n][k]) ;
	}
}