#include <bits/stdc++.h>
using namespace std ;

string inp ;

int main() {
	unsigned long long res ;
	int l ;
	while(true) {
		cin >> inp ;
		if(inp == "0")
			break ;
		l = inp.length() ;
		vector <int> solve(l) ;
		if(inp[0] != '0')
			solve[0] = 1 ;
		if(inp[1] != '0')
			solve[1] = solve[0] ;
		else
			solve[1] = 0 ;
		int num = 10 * (inp[0] - '0') + (inp[1] - '0') ;
		if(num >= 10 && num <= 26)
			solve[1]++ ;
		for(int i = 2 ; i < l ; i++) {
			if(inp[i] != '0')
				solve[i] = solve[i - 1] ;
			else
				solve[i] = 0 ;
			num = 10 * (inp[i - 1] - '0') + (inp[i] - '0') ;
			if(num >= 10 && num <= 26)
				solve[i] = solve[i] + solve[i - 2] ;
		}
		printf("%d\n" , solve[l - 1]);
	}
}