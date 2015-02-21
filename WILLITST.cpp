#include <bits/stdc++.h>
using namespace std ;

int main() {
	unsigned long long n , copy ;
	scanf("%lld" , &n) ;
	copy = n ;
	int index = -1 ;
	while(copy != 0) {
		copy = copy >> 1 ;
		index++ ;
	}
	//cout << index << endl ;
	unsigned long long check = 1 ;
	for(int i = 1 ; i <= index ; i++)
		check = check << 1 ;
	if(check == n)
		printf("TAK\n") ;
	else
		printf("NIE\n") ;
}