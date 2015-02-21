#include <iostream>
#include <stdio.h>
#include <string>
using namespace std ;

void add(string& s1 , string& s2 , string& s3) {
	s3 = "" ;
	int l1 = s1.length() , l2 = s2.length() ;
	for(int i = l1 ; i < l2 ; i++)
		s1 = '0' + s1 ;
	for(int i = l2 ; i < l1 ; i++)
		s2 = '0' + s2 ;
	int l = max(l1 , l2) ;
	int carry = 0 ;
	for(int i = l - 1 ; i >= 0 ; i--) {
		carry = carry + (s1[i] - '0') + (s2[i] - '0') ;
		s3 = (char)((carry % 10) + '0') + s3 ;
		carry = carry / 10 ;
	}
	while(carry != 0) {
		s3 = (char)((carry % 10) + '0') + s3 ;
		carry = carry / 10 ;
	}
}

void subtract(string& s1 , string& s2 , string& s3) {
	s3 = "" ;
	int l1 = s1.length() , l2 = s2.length() ;
	for(int i = l2 ; i < l1 ; i++)
		s2 = '0' + s2 ;
	int l = l1 ;
	int carry = 0 ;
	for(int i = l - 1 ; i >= 0 ; i--) {
		int a = s1[i] - carry ;
		carry = 0 ;
		int b = s2[i] ;
		if(a < b) {
			a = 10 + a ;
			carry = 1 ;
		}
		s3 = (char)(a - b + '0') + s3 ;
	}
	if(s3[0] == '0')
		s3 = s3.substr(1) ;
}
int main() {
	int t , l ;
	string s ;
	scanf("%d" , &t) ;
	while(t--) {
		getline(cin , s) ;
		getline(cin , s) ;
		l = s.length() ;
		string s1 = "" , s2 = "" , s3 = "" ;
		int p = 0 , i ;
		for(i = 0 ; i < l ; i++) {
			if(s[i] == 'm')
				p = 1 ;
			if(s[i] == ' ')
				break ;
			s1 = s1 + s[i] ;
		}
		i = i + 3 ;
		for( ; i < l ; i++) {
			if(s[i] == 'm')
				p = 2 ;
			if(s[i] == ' ')
				break ;
			s2 = s2 + s[i] ;
		}
		i = i + 3 ;
		for( ; i < l ; i++) {
			if(s[i] == 'm')
				p = 3 ;
			if(s[i] == ' ')
				break ;
			s3 = s3 + s[i] ;
		}
		if(p == 1)
			subtract(s3 , s2 , s1) ;
		else if(p == 2)
			subtract(s3 , s1 , s2) ;
		else
			add(s1 , s2 , s3) ;
		cout << s1 << " + " << s2 << " = " << s3 << endl ;
	}
}
