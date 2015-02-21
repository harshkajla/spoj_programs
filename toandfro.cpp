#include <iostream>
#include <stdio.h>
using namespace std ;

int main () {
	int c ;
	string s ;
	while(true) {
		scanf("%d" , &c) ;
		cin >> s ;
		if(c == 0)
			break ;
		int k = 2 * c + 1 ;
		for(int i = 0 ; i < c ; i++) {
			k = k - 2 ;
			for(int j = i ; j < s.length() ; j = j + 2 * c) {
				printf("%c" , s[j]) ;
				if(j + k < s.length())
					printf("%c" , s[j + k]) ;
			}
		}
		printf("\n") ;
	}
}
