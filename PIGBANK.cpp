#include <bits/stdc++.h>
using namespace std ;

const int UNSOLVED = numeric_limits <int> :: max() ;

int main() {
	int T , E , F , N ;
	scanf("%d" , &T) ;
	while(T--) {
		scanf("%d %d" , &E , &F) ;
		scanf("%d" , &N) ;
		vector <int> value(N) ;
		vector <int> weight(N) ;
		for(int i = 0 ; i < N ; i++)
			scanf("%d %d" , &value[i] , &weight[i]) ;
		int min_amount[F - E + 1] ;
		min_amount[0] = 0 ;
		for(int i = 1 ; i <= F - E ; i++) {
			min_amount[i] = UNSOLVED ;
			for(int j = 0 ; j < N ; j++) {
				if(weight[j] <= i)
					if(min_amount[i - weight[j]] != UNSOLVED)
						min_amount[i] = min(min_amount[i] , value[j] + min_amount[i - weight[j]]) ;
			}
		}
		if(min_amount[F - E] != UNSOLVED)
			printf("The minimum amount of money in the piggy-bank is %d.\n" , min_amount[F - E]) ;
		else
			printf("This is impossible.\n") ;
	}
}