#include <bits/stdc++.h>
using namespace std ;

int main() {
	int T , x ;
	string s , t ;
	scanf("%d" , &T) ;
	for(int j = 1 ; j <= T ; j++) {
		cin >> x ;
		cin >> s ;
		vector <int> data(8 , 0) ;
		for(int i = 0 ; i <= 37 ; i++) {
			t = s.substr(i , 3) ;
			if(t == "TTT")
				data[0]++ ;
			else if(t == "TTH")
				data[1]++ ;
			else if(t == "THT")
				data[2]++ ;
			else if(t == "THH")
				data[3]++ ;
			else if(t == "HTT")
				data[4]++ ;
			else if(t == "HTH")
				data[5]++ ;
			else if(t == "HHT")
				data[6]++ ;
			else if(t == "HHH")
				data[7]++ ;
		}
		printf("%d" , j) ;
		for(int i = 0 ; i < 8 ; i++)
			printf(" %d" , data[i]) ;
		printf("\n") ;
	}
}