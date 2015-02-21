#include <bits/stdc++.h>
using namespace std ;

int main() {
	int T , NG , NM ;
	scanf("%d" , &T) ;
	while(T--) {
		scanf("%d %d" , &NG , &NM) ;
		vector <int> godzilla(NG) ;
		vector <int> mecha(NM) ;
		for(int i = 0 ; i < NG ; i++)
			scanf("%d" , &godzilla[i]) ;
		for(int i = 0 ; i < NM ; i++)
			scanf("%d" , &mecha[i]) ;
		sort(godzilla.begin() , godzilla.end()) ;
		sort(mecha.begin() , mecha.end()) ;
		int i = 0 , j = 0 ;
		while(true) {
			if(i == NG) {
				printf("MechaGodzilla\n") ;
				break ;
			}
			else if(j == NM) {
				printf("Godzilla\n") ;
				break ;
			}
			else {
				if(godzilla[i] < mecha[j]) {
					i++ ;
				}
				else {
					j++ ;
				}
			}
		}
	}
}