#include <bits/stdc++.h>
using namespace std ;

int main() {
	int T , N ;
	scanf("%d" , &T) ;
	for(int t = 1 ; t <= T ; t++) {
		scanf("%d" , &N) ;
		vector <int> coins(N) ;
		for(int i = 0 ; i < N ; i++)
			scanf("%d" , &coins[i]) ;
		if(N == 0)
			printf("Case %d: 0\n" , t) ;
		else if(N == 1)
			printf("Case %d: %d\n" , t , coins[0]) ;
		else if(N == 2)
			printf("Case %d: %d\n" , t , max(coins[0] , coins[1])) ;
		else if(N == 3) {
			unsigned long long res = coins[0] + coins[2] ;
			if(res < coins[1])
				res = coins[1] ;
			printf("Case %d: %lld\n" , t , res) ;	
		}
		else {
			vector <long long> total(N) ;
			total[0] = coins[0] ;
			total[1] = (long long)max(coins[0] , coins[1]) ;
			if((long long)coins[0] + (long long)coins[2] > (long long)coins[1])
				total[2] = (long long)coins[0] + (long long)coins[2] ;
			else
				total[2] = (long long)coins[1] ;
			for(int i = 3 ; i < N ; i++) {
				if(total[i - 2] > total[i - 3])
					total[i] = (long long)coins[i] + total[i - 2] ;
				else
					total[i] = (long long)coins[i] + total[i - 3] ;
			}
			if(total[N - 1] > total[N - 2])
				printf("Case %d: %lld\n" , t , total[N - 1]) ;
			else
				printf("Case %d: %lld\n" , t , total[N - 2]) ;
		}
	}
}