#include <iostream>
#include <stdio.h>
using namespace std ;

int main() {
	char num1[100] , c ;
	int num2 , carry = 0 , i ;
	string s ;
	cin >> s ;
	for(int i = 0 ; i < s.length() ; i++)
		num1[i] = s[s.length() - i - 1] ;
	scanf("%d" , &num2) ;
	for(i = 0 ; i < s.length() ; i++) {
		carry = num2 * (num1[i] - '0') + carry ;
		num1[i] = carry % 10 + '0' ;
		carry = carry / 10 ;
	}
	
	while(carry != 0) {
		num1[i++] = carry % 10 + '0' ;
		carry = carry / 10 ;
	}
	for(int j = i - 1 ; j >= 0 ; j--)
		cout << num1[j] ;
	cout << endl ;
}
