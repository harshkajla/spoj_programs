#include <bits/stdc++.h>
using namespace std ;

int gcd(int m , int n) {
	if(n == 0)
		return m ;
	if(m == 0)
		return n ;
	return gcd(max(m , n) % min(m , n) , min(m , n)) ;
}

int main() {
	int T , A , B ;
	scanf("%d" , &T) ;
	while(T--) {
		scanf("%d %d" , &A , &B) ;
		int g = gcd(A , B) ;
		A = A / g ;
		B = B / g ;
		printf("%d %d\n", B , A);
	}
}