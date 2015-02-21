#include <bits/stdc++.h>
using namespace std ;

int main() {
	int A , D ;
	while(true) {
		scanf("%d %d" , &A , &D) ;
		if(A == 0)
			return 0 ;
		//cout << A << " " << D << endl ;
		vector <int> attack(A) ;
		vector <int> defend(D) ;
		for(int i = 0 ; i < A ; i++)
			scanf("%d" , &attack[i]) ;
		for(int i = 0 ; i < D ; i++)
			scanf("%d" , &defend[i]) ;
		sort(attack.begin() , attack.end()) ;
		sort(defend.begin() , defend.end()) ;
		if(attack[0] < defend[1])
			printf("Y\n") ;
		else
			printf("N\n") ;
	}
}