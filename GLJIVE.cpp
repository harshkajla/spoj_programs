#include <bits/stdc++.h>
using namespace std ;

int main() {
	int sum = 0 , sum1 = 0 , x ;
	for(int i = 0 ; i < 10 ; i++) {
		cin >> x ;
		sum1 = sum + x ;
		if(sum1 >= 100)
			break ;
		else
			sum = sum1 ;
	}
	int diff1 = 100 - sum , diff2 = sum1 - 100 ;
	if(diff1 < diff2)
		printf("%d\n" , sum) ;
	else if(diff2 <= diff1)
		printf("%d\n" , sum1) ;
}