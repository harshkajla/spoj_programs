#include <bits/stdc++.h>
using namespace std ;

int main() {
	string s ;
	int t = 0 ;
	while(true) {
		t++ ;
		cin >> s ;
		if(s[0] == '-')
			break ;
		stack <char> left ;
		int count = 0 ;
		for(int i = 0 ; i < s.length() ; i++) {
			if(s[i] == '{')
				left.push('{') ;
			else {
				if(left.empty() == false)
					left.pop() ;
				else {
					left.push('{') ;
					count++ ;
				}
			}
		}
		count = count + left.size() / 2 ;
		printf("%d. %d\n" , t , count) ;
	}
}