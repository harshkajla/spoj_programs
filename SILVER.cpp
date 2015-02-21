#include <bits/stdc++.h>
using namespace std ;

int main() {
	int n ;
	while(true) {
		scanf("%d" , &n) ;
		if(n == 0)
			break ;
		else
			printf("%d\n" , (int)(log10(n * 1.0) / log10(2.0))) ;
	}
}