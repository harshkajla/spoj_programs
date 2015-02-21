#include <bits/stdc++.h>
using namespace std ;

int main() {
	int N , x , y ;
	scanf("%d" , &N) ;
	int total = 0 ;
	int half = 0 , three_fourth = 0 , quarter = 0 ;
	for(int i = 0 ; i < N ; i++) {
		scanf("%d/%d" , &x , &y) ;
		if(x == 1 && y == 2)
			half++ ;
		else if(x == 3 && y == 4)
			three_fourth++ ;
		else
			quarter++ ;
	}
	quarter = quarter - three_fourth ;
	total = three_fourth ;
	if(quarter < 0) {
		total = total + half / 2 ;
		if(half % 2 == 1)
			total++ ;
	}
	else {
		int total1 , total2 ;
		total1 = total2 = total ;
		//calculate total1
		total1 = total1 + half / 2 ;
		if(half % 2 == 0) {
			total1 = total1 + quarter / 4 ;
			if(quarter % 4 != 0)
				total1++ ;
		}
		else {
			total1++ ;
			int quarter_ = quarter - 2 ;
			if(quarter_ > 0) {
				total1 = total1 + quarter_ / 4 ;
				if(quarter_ % 4 != 0)
					total1++ ;
			}
		}
		//cout << "total1 : " << total1 << endl ;
		//calculate total2
		if(quarter % 2 == 0) {
			int quarter_ = quarter / 2 ;
			if(half > quarter_) {
				total2 = total2 + quarter_ ;
				int half_ = half - quarter_ ;
				total2 = total2 + half_ / 2 ;
				if(half_ % 2 == 1)
					total2++ ;
			}
			else {
				total2 = total2 + half ;
				total2 = total2 + (quarter - 2 * half) / 4 ;
				if((quarter - 2 * half) % 4 != 0)
					total2++ ;
			}
		}
		else {
			int quarter_ = quarter / 2 ;
			if(half > quarter_) {
				total2 = total2 + quarter_ ;
				int half_ = half - quarter_ ;
				total2 = total2 + half / 2 + 1 ;
			}
			else {
				total2 = total2 + half ;
				total2 = total2 + (quarter - 2 * half) / 4 ;
				if((quarter - 2 * half) % 4 != 0)
					total2++ ;
			}
		}
		total = min(total2 , total1) ;
	}
	cout << total + 1 << endl ;
}