#include <bits/stdc++.h>
using namespace std ;

int main() {
	int t , needed , friends , count  , res ;
	scanf("%d" , &t) ;
	for(int counter = 1 ; counter <= t ; counter++) {
		printf("Scenario #%d:\n" , counter) ;
		scanf("%d %d" , &needed , &friends) ;
		vector <int> stamps(friends) ;
		for(int i = 0 ; i < friends ; i++)
			scanf("%d" , &stamps[i]) ;
		sort(stamps.begin() , stamps.end()) ;
		count = 0 ;
		res = 0 ;
		for(int i = stamps.size() - 1 ; i >= 0 ; i--) {
			count = count + stamps[i] ;
			res++ ;
			if(count >= needed) {
				printf("%d\n\n" , res) ;
				break ;
			}
		}
		if(count < needed) {
			printf("impossible\n\n") ;
		}
	}
}