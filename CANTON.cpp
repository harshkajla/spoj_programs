#include <bits/stdc++.h>
using namespace std ;

int main() {
	int t , n ;
	unsigned long long num , denum ;
	scanf("%d" , &t) ;
	while(t--) {
		scanf("%d" , &n) ;
		double tmp = (1 + sqrt(1 + 8 * n)) / 2.0 ;
		if(tmp - (int)tmp == 0.0)
			tmp = tmp - 1 ;
		int group = tmp ;
		int pos = n - group * (group - 1) / 2 ;
		//cout << group << " " << pos << endl ;
		
		if(group % 2 == 0) {
			num = pos ;
			denum = group + 1 - num ;
		}
		else {
			denum = pos ;
			num = group + 1 - denum ;
		}
		printf("TERM %d IS %lld/%lld\n", n , num , denum);
	}
}