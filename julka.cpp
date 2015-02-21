#include <iostream>
#include <stdio.h>
using namespace std ;

int main () {
	string a , b ;
	string bigger , smaller , add , subtract ;
	string K , N ;
	for(int z = 0 ; z < 10 ; z++) {
		cin >> a ;
		cin >> b ;
		if(a == "0" && b == "0") {
			cout << 0 << endl << 0 << endl ;
			continue ;
		}
		if(a == b) {
			cout << a << endl << 0 << endl ;
			continue ;
		}
		add = "" ;
		subtract = "" ;
		K = "" ;
		N = "" ;
		if(a.length() < b.length()) {
			smaller = a ;
			bigger = b ;
		}
		else {
			smaller = b ;
			bigger = a ;
		}
		int carry = 0 ;
		int i = smaller.length() - 1 , j = bigger.length() - 1 ;
		for( ; i >= 0 ; i-- , j--) {
			int digit = (carry + (smaller[i] - '0') + (bigger[j] - '0')) ;
			carry = digit / 10 ;
			digit = digit % 10 ;
			add = (char)(digit + '0') + add ;
		}
		for( ; j >= 0 ; j--) {
			int digit = (carry + (bigger[j] - '0')) ;
			carry = digit / 10 ;
			digit = digit % 10 ;
			add = (char)(digit + '0') + add ;
		}
		if(carry != 0)
			add = (char)(carry + '0') + add ;
		int borrow = 0 ;
		while(smaller.length() != bigger.length())
			smaller = '0' + smaller ;
		i = smaller.length() - 1 , j = bigger.length() - 1 ;
		for( ; i >= 0 ; i-- , j--) {
			int p = (bigger[i] - '0') - borrow ;
			int q = smaller[i] - '0' ;
			borrow = 0 ;
			if(p < q) {
				p = p + 10 ;
				borrow = 1 ;
			}
			subtract = (char)(p - q + '0') + subtract ;
		}
		int rem = 0 ;
		for(int i = 0 ; i < add.length() ; i++) {
			int digit = rem * 10 + (add[i] - '0') ;
			K = K + (char)(digit / 2 + '0') ;
			rem = digit % 2 ;
		}
		rem = 0 ;
		for(int i = 0 ; i < subtract.length() ; i++) {
			int digit = rem * 10 + (subtract[i] - '0') ;
			N = N + (char)(digit / 2 + '0') ;
			rem = digit % 2 ;
		}
		for(i = 0 ; i < K.length() ; i++)
			if(K[i] != '0')
				break ;
		K = K.substr(i) ;
		for(i = 0 ; i < N.length() ; i++)
			if(N[i] != '0')
				break ;
		N = N.substr(i) ;
		cout << K << endl ;
		cout << N << endl ;
		//cout << add << " " << subtract << " " << K << " " << N << endl ;
	}
}
