#include <bits/stdc++.h>
using namespace std ;

int n , k ;

unsigned long long solve(int start , int end , vector <bool>& is_opening , bool flag) {
	unsigned long long ans = 0 ;
	if(start > end)
		ans = 1 ;
	else if(is_opening[end])
		ans = 0 ;
	else if(start + 1 == end)
		ans = 1 ;
	else {
		if(flag == true)
			ans = solve(start + 1 , end - 1 , is_opening , false) ;
		else {
			ans = solve(start + 1 , end - 1 , is_opening , false) ;
			for(int i = start + 2 ; i <= end - 1 ; i = i + 2)
				ans = ans + solve(start , i - 1 , is_opening , false) * solve(i , end , is_opening , true) ;
		}
	}
	//cout << start << " , " << end << " : " << ans << endl ;
	return ans ;
}

int main() {
	int d , x ;
	scanf("%d" , &d) ;
	while(d--) {
		scanf("%d %d" , &n , &k) ;
		vector <bool> is_opening(false , 2 * n + 1) ;
		for(int i = 0 ; i < k ; i++) {
			scanf("%d" , &x) ;
			is_opening[x] = true ;
		}
		printf("%lld\n" , solve(1 , 2 * n , is_opening , false)) ;
	}
}