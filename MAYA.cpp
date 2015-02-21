#include <bits/stdc++.h>
using namespace std ;

unsigned long long convert(string dig) {
	if(dig == "S")
		return 0 ;
	else if(dig == ".")
		return 1 ;
	else if(dig == "..")
		return 2 ;
	else if(dig == "...")
		return 3 ;
	else if(dig == "....")
		return 4 ;
	else if(dig == "-")
		return 5 ;
	else if(dig == ". -")
		return 6 ;
	else if(dig == ".. -")
		return 7 ;
	else if(dig == "... -")
		return 8 ;
	else if(dig == ".... -")
		return 9 ;
	else if(dig == "- -")
		return 10 ;
	else if(dig == ". - -")
		return 11 ;
	else if(dig == ".. - -")
		return 12 ;
	else if(dig == "... - -")
		return 13 ;
	else if(dig == ".... - -")
		return 14 ;
	else if(dig == "- - -")
		return 15 ;
	else if(dig == ". - - -")
		return 16 ;
	else if(dig == ".. - - -")
		return 17 ;
	else if(dig == "... - - -")
		return 18 ;
	else
		return 19 ;
}

int main() {
	int n ;
	while(true) {
		scanf("%d" , &n) ;
		if(n == 0)
			break ;
		vector <string> d(7 , "S") ;
		string s ;
		getline(cin , s) ;
		for(int i = n - 1 ; i >= 0 ; i--)
			getline(cin , d[i]) ;
		printf("%lld\n" , convert(d[0]) + 20 * convert(d[1]) + 360 * convert(d[2]) + 7200 * convert(d[3]) + 144000 * convert(d[4]) + 2880000 * convert(d[5]) + 57600000 * convert(d[6])) ;
	}
}