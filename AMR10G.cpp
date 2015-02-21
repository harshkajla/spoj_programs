#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std ;

int main() {
	int T , K , N ;
	scanf("%d" , &T) ;
	while(T--) {
		scanf("%d" , &N) ;
		scanf("%d" , &K) ;
		vector <int> heights(N) ;
		for(int i = 0 ; i < N ; i++)
			scanf("%d" , &heights[i]) ;
		sort(heights.begin() , heights.end()) ;
		int diff = heights[K - 1] - heights[0] ;
		for(int i = 1 ; i + K - 1 < N ; i++)
			if(heights[i + K - 1] - heights[i] < diff)
				diff = heights[i + K - 1] - heights[i] ;
		printf("%d\n" , diff) ;
	}
}