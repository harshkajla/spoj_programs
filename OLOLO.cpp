#include <bits/stdc++.h>
using namespace std ;

int main() {
	int N ;
	scanf("%d" , &N) ;
	int res = 0 , num ;
	for(int i = 0 ; i < N ; i++) {
		scanf("%d" , &num) ;
		res = res ^ num ;
	}
	printf("%d\n" , res) ;
}