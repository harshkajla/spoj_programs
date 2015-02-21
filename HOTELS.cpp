#include <bits/stdc++.h>
using namespace std ;

int main() {
	int N ;
	unsigned long long M ;
	scanf("%d %lld" , &N , &M) ;
	vector <unsigned long long> prices(N) ;
	for(int i = 0 ; i < N ; i++)
		scanf("%lld" , &prices[i]) ;
	int i = 0 , j = 0 ;
	unsigned long long sum = 0 ;
	for(i = 0 ; i < N ; i++) {
		if(sum + prices[i] <= M)
			sum = sum + prices[i] ;
		else {
			//cout << sum << endl ;
			unsigned long long tmp = sum + prices[i] ;
			cout << tmp << endl ;
			for(int k = j ; k <= i ; k++) {
				tmp = tmp - prices[k] ;
				cout << tmp << endl ;
				if(tmp <= M) {
					j = k + 1 ;
					cout << "breaking  ;" << tmp << endl ;
					cout << i << " , " << j << endl ;
					break ;
				}
			}
			sum = max(sum , tmp) ;
		}
	}
	cout << sum << endl ;
}