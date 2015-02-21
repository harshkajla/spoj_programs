#include <bits/stdc++.h>
using namespace std ;

int main() {
	string a , b ;
	while(cin >> a >> b) {
		vector <int> array1(26 , 0) , array2(26 , 0) ;
		for(int i = 0 ; i < a.length() ; i++)
			array1[a[i] - 'a']++ ;
		for(int j = 0 ; j < b.length() ; j++)
			array2[b[j] - 'a']++ ;
		for(int i = 0 ; i < 26 ; i++) {
			int t = min(array1[i] , array2[i]) ;
			for(int j = 0 ; j < t ; j++)
				printf("%c" , (char)('a' + i)) ;
		}
		printf("\n") ;
	}
}