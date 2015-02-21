#include <bits/stdc++.h>
using namespace std ;

int main() {
	int T, N ;
	unsigned long long sum ;
	scanf("%d" , &T) ;
	while(T--) {
		sum = 0 ;
		scanf("%d" , &N) ;
		vector <int> num(N) ;
		for(int i = 0 ; i < N ; i++)
			scanf("%d" , &num[i]) ;
		int sz = 100001 ;
		vector <bool> a(sz, false) ;
		a[0] = true ;
		for(int i = 0 ; i < N ; i++) {
			for(int j = sz - 1 ; j >= 0 ; j--) {
				if(a[j] == true)
					a[j + num[i]] = true ;
			}
		}
		for(int i = 0 ; i < sz ; i++)
			if(a[i] == true)
				sum = sum + i ;
		printf("%lld\n" , sum) ;
	}
}