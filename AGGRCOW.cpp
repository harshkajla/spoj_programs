#include <bits/stdc++.h>
using namespace std ;

int t , N , C ;
vector <int> position ;

int f(int x) {
	int curr = position[0] ;
	int done = 1 ;
	for(int i = 1 ; i < N ; i++) {
		if(position[i] - curr >= x) {
			curr = position[i] ;
			done++ ;
		}
	}
	if(done >= C)
		return 1 ;
	else
		return 0 ;
}

int solve() {
	int lo = 0 , hi = position[N - 1] ;
	while(lo < hi) {
		int mid = (lo + hi) / 2 ;
		if(f(mid) == 1)
			lo = mid + 1 ;
		else
			hi = mid ;
	}
	return lo - 1 ;
}

int main() {
	scanf("%d" , &t) ;
	while(t--) {
		scanf("%d %d" , &N , &C) ;
		position.resize(N) ;
		for(int i = 0 ; i < N ; i++)
			scanf("%d" , &position[i]) ;
		sort(position.begin() , position.end()) ;
		printf("%d\n" , solve()) ;
	}
}