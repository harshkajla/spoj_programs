#include <bits/stdc++.h>
using namespace std ;

int gcd(int m , int n) {
	if(min(m , n) == 0)
		return max(m , n) ;
	return gcd(max(m , n) % min(m , n) , min(m , n)) ;
}

int main() {
	int N , x , y ;
	scanf("%d" , &N) ;
	scanf("%d" , &x) ;
	vector <int> differences(N - 1) ;
	for(int i = 0 ; i < N - 1 ; i++) {
		scanf("%d" , &y) ;
		differences[i] = y - x ;
		x = y ;
	}

	int res = gcd(differences[0] , differences[1]) ;
	for(int i = 2 ; i < N - 1 ; i++)
		res = gcd(differences[i] , res) ;
	int answer = 0 ;
	for(int i = 0 ; i < N - 1 ; i++)
		answer = answer + differences[i] / res - 1 ;
	printf("%d\n" , answer) ;
}