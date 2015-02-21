#include <bits/stdc++.h>
using namespace std ;

int main() {
	int G , B ;
	int a , b , res ;
	while(true) {
		scanf("%d %d" , &G , &B) ;
		if(G == -1)
			break ;
		a = min(G , B) ;
		b = max(G , B) ;
		res = ceil(b * 1.0 / (a + 1)) ;
		printf("%d\n" , res);
	}
}