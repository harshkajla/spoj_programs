#include <iostream>
#include <stdio.h>
using namespace std ;

int main() {
	float num ;
	while(true) {
		scanf("%f" , &num) ;
		if(num == 0.00)
			return 0 ;
		double sum = 0.0 ;
		unsigned long long i = 1 ;
		while(sum < num) {
			sum = sum + 1.0 / (i + 1) ;
			//cout << "s" << sum << endl ;
			i++ ;
		}
		printf("%lld card(s)\n" , i - 1) ;
	}
}
