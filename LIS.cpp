#include <bits/stdc++.h>
using namespace std ;

const int UNSOLVED = 1 ;
int N ;
vector <int> length , num ;

int lis(int index) {
	if(length[index] == UNSOLVED) {
		for(int i = 0 ; i < index ; i++) {
			if(num[i] <= num[index])
				length[index] = max(length[index] , 1 + lis(i)) ;
		}
	}
	return length[index] ;
}

int main() {
	scanf("%d" , &N) ;
	length.resize(N) ;
	num.resize(N) ;
	for(int i = 0 ; i < N ; i++) {
		scanf("%d" , &num[i]) ;
		length[i] = UNSOLVED ;
	}
	printf("%d\n" , lis(N - 1)) ;
}