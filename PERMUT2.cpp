#include <bits/stdc++.h>
using namespace std ;

int main() {
	int n ;
	while(true) {
		scanf("%d" , &n) ;
		if(n == 0)
			break ;
		vector <int> data(n + 1) ;
		for(int i = 1 ; i <= n ; i++)
			scanf("%d" , &data[i]) ;
		bool ambiguous = true ;
		for(int i = 1 ; i <= n ; i++)
			if(data[data[i]] != i) {
				ambiguous = false ;
				break ;
			}
		if(ambiguous == true)
			printf("ambiguous\n") ;
		else
			printf("not ambiguous\n") ;
	}
}