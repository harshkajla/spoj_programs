#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>
using namespace std ;

int main() {
	int T , N1 , N2 , x ;
	scanf("%d" , &T) ;
	while(T--) {
		set <int> h1 , h2 ;
		scanf("%d" , &N1) ;
		for(int i = 0 ; i < N1 ; i++) {
			scanf("%d" , &x) ;
			h1.insert(x) ;
		}
		scanf("%d" , &N2) ;
		for(int i = 0 ; i < N2 ; i++) {
			scanf("%d" , &x) ;
			h2.insert(x) ;
		}
		int min_diff = 1000000 , tmp , diff ;
		set <int> :: iterator it = h1.begin() ;
		for(it = h1.begin() ; it!= h1.end() ; it++) {
			set <int> :: iterator z = h2.lower_bound(*it) ;
			tmp = *z ;
			diff = (*it) - tmp ;
			if(diff < 0)
				diff = (-1) * diff ;
			if(diff < min_diff)
				min_diff = diff ;
			if(z!= h2.begin())
				z-- ;
			tmp = *z ;
			diff = (*it) - tmp ;
			if(diff < 0)
				diff = (-1) * diff ;
			if(diff < min_diff)
				min_diff = diff ;
		}
		printf("%d\n" , min_diff) ;
	}
}