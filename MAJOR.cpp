#include <bits/stdc++.h>
using namespace std ;

int main() {
	int t , n , x ;
	scanf("%d" , &t) ;
	while(t--) {
		vector <int> data(2001 , 0) ;
		scanf("%d" , &n) ;
		for(int i = 0 ; i < n ; i++) {
			scanf("%d" , &x) ;
			data[x + 1000]++ ;
		}
		bool transmitted = false ;
		for(int i = 0 ; i <= 2000 ; i++) {
			if(data[i] * 2 > n) {
				transmitted = true ;
				printf("YES %d\n" , i - 1000) ;
				break ;
			}
		}
		if(!transmitted) {
			printf("NO\n") ;
		}
	}
}