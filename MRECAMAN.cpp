#include <bits/stdc++.h>
using namespace std ;

int main() {
	int k ;
	vector <int> ans(500001) ;
	vector <bool> present(3000000 , false) ;
	ans[0] = 0 ;
	present[0] = true ;
	for(int i = 1 ; i <= 500000 ; i++) {
		int t = ans[i - 1] - i ;
		if(t > 0) {
			if(!present[t]) {
				present[t] = true ;
				ans[i] = t ;
			}
			else {
				t = ans[i - 1] + i ;
				present[t] = true ;
				ans[i] = t ;
			}
		}
		else {
			t = ans[i - 1] + i ;
			present[t] = true ;
			ans[i] = t ;
		}
	}
	while(true) {
		scanf("%d" , &k) ;
		if(k == -1)
			break ;
		printf("%d\n" , ans[k]) ;
	}
}