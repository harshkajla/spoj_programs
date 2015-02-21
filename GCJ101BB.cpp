#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std ;

int main() {
	int C, N, K, B, T ;
	scanf("%d" , &C) ;
	for(int t = 1 ; t <= C ; t++) {
		scanf("%d" , &N) ;
		scanf("%d" , &K) ;
		scanf("%d" , &B) ;
		scanf("%d" , &T) ;
		vector <int> x(N) ;
		vector <int> v(N) ;
		for(int i = 0 ; i < N ; i++)
			scanf("%d" , &x[i]) ;
		for(int i = 0 ; i < N ; i++)
			scanf("%d" , &v[i]) ;
		vector <bool> will_go(N , false) ;
		vector <int> reach ;
		for(int i = N - 1 ; i>= 0 ; i--) {
			if(B - x[i] <= T * v[i]) {
				will_go[i] = true ;
				reach.push_back(i) ;
			}
		}
		if(reach.size() < K) {
			printf("Case #%d: IMPOSSIBLE\n" , t) ;
			continue ;
		}
		int swaps = 0 ;
		for(int i = 0 ; i < K ; i++) {
			for(int j = reach[i] ; j < N ; j++)
				if(will_go[j] == false)
					swaps++ ;
		}
		printf("Case #%d: %d\n" , t , swaps) ;
	}
}