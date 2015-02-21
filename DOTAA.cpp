#include <bits/stdc++.h>
using namespace std ;

int main() {
	int t , n , m , D , H , count ;
	scanf("%d" , &t) ;
	while(t--) {
		count = 0 ;
		scanf("%d %d %d" , &n , &m , &D) ;
		for(int i = 0 ; i < n ; i++) {
			scanf("%d" , &H) ;
			if(H % D == 0)
				count = count + H / D - 1 ;
			else
				count = count + H / D ;
		}
		if(count >= m)
			printf("YES\n");
		else
			printf("NO\n");
	}
}