#include <bits/stdc++.h>
using namespace std ;

int stoi(string s) {
	int res = 0 ;
	for(int i = 0 ; i < s.length() ; i++)
		res = res * 10 + s[i] - '0' ;
	return res ;
}

int main() {
	int T ;
	int a , b , c ;
	scanf("%d" , &T) ;
	while(T--) {
		string s1 , s2 , s3 ;
		cin >> s1 ;
		cin >> s2 >> s2 ;
		cin >> s3 >> s3 ;
		if(s1.find('m') != string :: npos) {
			b = stoi(s2) ;
			c = stoi(s3) ;
			a = c - b ;
		}
		else if(s2.find('m') != string :: npos) {
			a = stoi(s1) ;
			c = stoi(s3) ;
			b = c - a ;
		}
		else {
			a = stoi(s1) ;
			b = stoi(s2) ;
			c = a + b ;
		}
		printf("%d + %d = %d\n" , a , b , c) ;
	}
}