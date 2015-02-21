#include <bits/stdc++.h>
using namespace std ;

int squareadd(int n) {
	int res = 0 ;
	while(n != 0) {
		int last = n % 10 ;
		res = res + last * last ;
		n = n / 10 ;
	}
	return res ;
}

int solve(unsigned int N) {
	vector <bool> done(810 , false) ;
	unsigned long long steps = 0 ;
	//cout << N << " " ;
	while(true) {
		if(done[N] == true || N == 4) {
			return -1 ;
		}
		else {
			if(N == 1) {
				return steps ;
			}
			else {
				done[N] = true ;
				steps++ ;
			}
		}
		N = squareadd(N) ;
		//cout << N << " " ;
	}
}

int main() {
	unsigned int N ;
	scanf("%d" , &N) ;
	
	vector <int> converge(810 , 0) ;
	for(int i = 1 ; i < 810 ; i++)
		converge[i] = solve(i) ;
	N = squareadd(N) ;
	if(converge[N] == -1)
		printf("-1\n") ;
	else
		printf("%d\n" , converge[N] + 1) ;
}