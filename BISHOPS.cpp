#include <bits/stdc++.h>
using namespace std ;

int main() {
	string inp , res = "" , smaller , subtract ;
	while(cin >> inp) {
		if(inp == "1") {
			printf("1\n") ;
			continue ;
		}
		res = "" ;
		subtract = "" ;
		smaller = "2" ;
		int carry = 0 ;
		for(int i = inp.length() - 1 ; i >= 0 ; i--) {
			int dig = 2 * (inp[i] - '0') + carry ;
			carry = dig / 10 ;
			dig = dig % 10 ;
			res = (char)(dig + '0') + res ;
		}
		if(carry != 0)
			res = (char)(carry + '0') + res ;

		int borrow = 0 ;
		while(smaller.length() != res.length())
			smaller = '0' + smaller ;
		int i = smaller.length() - 1 , j = res.length() - 1 ;
		for( ; i >= 0 ; i-- , j--) {
			int p = (res[i] - '0') - borrow ;
			int q = smaller[i] - '0' ;
			borrow = 0 ;
			if(p < q) {
				p = p + 10 ;
				borrow = 1 ;
			}
			subtract = (char)(p - q + '0') + subtract ;
		}
		for(j = 0 ; j < subtract.length() ; j++)
			if(subtract[j] != '0')
				break ;
		subtract = subtract.substr(j) ;
		cout << subtract << endl ;
	}

}