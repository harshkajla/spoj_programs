#include <bits/stdc++.h>
using namespace std ;

vector <int> primes ;
vector <bool> check(100001 , true) ;

void solve() {
	for(int i = 3 ; i * i <= 100000 ; i = i + 2)
		if(check[i] == true)
			for(int j = i * i ; j <= 100000 ; j = j + i)
				check[j] = false ;
	primes.push_back(2) ;
	for(int i = 3 ; i <= 100000 ; i = i + 2)
		if(check[i] == true)
			primes.push_back(i) ;
	check[0] = check[1] = check[2] = true ;
	//for(int i = 0 ; i < 10 ; i++)
	//	cout << primes[i] << " " ;
	//cout << endl ;
	return ;
}

int main() {
	solve() ;
	int t , a , b ;
	scanf("%d" , &t) ;
	while(t--) {
		int count = 0 ;
		scanf("%d %d" , &a , &b) ;
		if(a <= 0 && 0 <= b)
			count++ ;
		if(a <= 1 && 1 <= b)
			count++ ;
		if(a <= 2 && 2 <= b)
			count++ ;
		if(a <= 3 && 3 <= b)
			count++ ;
		printf("%d\n" , count) ;
	}
}