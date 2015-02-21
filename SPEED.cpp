#include <bits/stdc++.h>
using namespace std ;

int gcd(int m , int n) {
	if(min(m , n) == 0)
		return max(m , n) ;
	return gcd(max(m , n) % min(m , n) , min(m , n)) ;
}

int main() {
	int t , v1 , v2 , vrel ;
	scanf("%d" , &t) ;
	while(t--) {
		scanf("%d %d" , &v1 , &v2) ;
		if(v1 < 0 && v2 < 0) {
			v1 = -1 * v1 ;
			v2 = -1 * v2 ;
		}
		vrel = v1 - v2 ;
		if(vrel < 0)
			vrel = -1 * vrel ;
		printf("%d\n" , vrel / gcd(vrel , max(v1 , v2))) ;
	}
}