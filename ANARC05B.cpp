#include <bits/stdc++.h>
using namespace std ;

const int max_sz = 20000 ;

int main() {
	int m , n , x ;
	while(true) {
		scanf("%d" , &m) ;
		if(m == 0)
			break ;
		vector <bool> a(max_sz + 1 , false) ;
		for(int i = 0 ; i < m ; i++) {
			scanf("%d" , &x) ;
			a[x + 10000] = true ;
		}
		scanf("%d" , &n) ;
		vector <bool> b(max_sz + 1 , false) ;
		for(int i = 0 ; i < n ; i++) {
			scanf("%d" , &x) ;
			b[x + 10000] = true ;
		}
		vector <bool> intersection(max_sz + 1 , false) ;
		for(int i = 0 ; i <= max_sz ; i++) {
			if(a[i] && b[i])
				intersection[i] = true ;
		}
		vector <int> s1 , s2 ;
		int sum1 = 0 , sum2 = 0 ;
		for(int i = 0 ; i <= max_sz ; i++) {
			if(!intersection[i]) {
				if(a[i])
					sum1 = sum1 + i - 10000 ;
				if(b[i])
					sum2 = sum2 + i - 10000 ;
			}
			else {
				s1.push_back(sum1) ;
				sum1 = 0 ;
				s2.push_back(sum2) ;
				sum2 = 0 ;
			}
		}
		s1.push_back(sum1) ;
		s2.push_back(sum2) ;
		int res = 0 ;
		for(int i = 0 ; i < s1.size() ; i++)
			res = res + max(s1[i] , s2[i]) ;
		for(int i = 0 ; i <= max_sz ; i++)
			if(intersection[i])
				res = res + i - 10000 ;
		printf("%d\n" , res) ;
	}
}