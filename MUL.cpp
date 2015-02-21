#include <bits/stdc++.h>
using namespace std ;

string a , b , res , tmp ;

void add() {
	//cout << res << " " << tmp << endl ;
	for(int i = res.length() ; i < max(tmp.length() , res.length()) ; i++)
		res = "0" + res ;
	for(int i = tmp.length() ; i < res.length() ; i++)	
		tmp = "0" + tmp ;
	int carry = 0 , dig ;
	for(int i = max(tmp.length() , res.length()) - 1 ; i >= 0 ; i--) {
		dig = (res[i] - '0') + (tmp[i] - '0') + carry ;
		carry = dig / 10 ;
		dig = dig % 10 ;
		res[i] = (char)(dig + '0') ;
	}
	res = (char)(carry + '0') + res ;
}

int main() {
	int n , num , carry , dig ;
	scanf("%d" , &n) ;
	while(n--) {
		res = "" ;
		carry = 0 ;
		cin >> a ;
		cin >> b ;
		if(a == "0" || b == "0") {
			printf("0\n") ;
			continue ;
		}
		for(int i = b.length() - 1 ; i >= 0 ; i--) {
			num = b[i] - '0' ;
			carry = 0 ;
			tmp = "" ;
			for(int j = a.length() - 1 ; j >= 0 ; j--) {
				dig = num * (a[j] - '0') + carry ;
				carry = dig / 10 ;
				dig = dig % 10 ;
				tmp = (char)(dig + '0') + tmp ;
			}
			tmp = (char)(carry + '0') + tmp ;
			for(int j = 1 ; j < b.length() - i ; j++)
				tmp = tmp + "0" ;
			add() ;
		}
		int j ;
		for(j = 0 ; j < res.length() ; j++)
			if(res[j] != '0')
				break ;
		printf("%s\n" , res.substr(j).c_str()) ;
	}
}