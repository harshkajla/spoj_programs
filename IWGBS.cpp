#include <bits/stdc++.h>
using namespace std ;

string a , b , c ;

void add() {
	int l1 = a.length() , l2 = b.length() ;
	for(int i = l1 ; i < l2 ; i++)
		a = "0" + a ;
	for(int i = l2 ; i < l1 ; i++)
		b = "0" + b ;
	int l = max(l1 , l2) ;
	int dig , carry = 0 ;
	c = "" ;
	for(int i = l - 1 ; i >= 0 ; i--) {
		dig = (a[i] - '0') + (b[i] - '0') + carry ;
		carry = dig / 10 ;
		dig = dig % 10 ;
		c = (char)(dig + '0') + c ;
	}
	if(carry != 0)
		c = (char)(carry + '0') + c ;
}

int main() {
	a = "2" ;
	b = "3" ;
	int N ;
	scanf("%d" , &N) ;
	if(N == 1)
		printf("2\n") ;
	else if(N == 2)
		printf("3\n") ;
	else {
		for(int i = 3 ; i <= N ; i++) {
			add() ;
			a = b ;
			b = c ;
		}
		cout << c << "\n" ;
	}
}