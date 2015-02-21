#include <bits/stdc++.h>
using namespace std ;

int dig(int n) {
	int res = 0 ;
	while(n != 0) {
		res++ ;
		n = n / 10 ;
	}
	return res ;
}

bool check(int n) {
	vector <int> a(10 , 0) ;
	while(n != 0) {
		a[n % 10]++ ;
		n = n / 10 ;
	}
	for(int i = 0 ; i < 10 ; i++)
		if(a[i] > 1)
			return false ;
	return true ;
}

int main() {/*
	int i = 1 ;
	int count = 0 ;
	while(dig(i * 495) < 6) {
		if(dig(i * 495) == 5 || dig(i * 495) == 4)
			if(check(i * 495) == true) {
				cout << i * 495 << endl ;
				count++ ;
			}
		i++ ;
	}
	cout << count << endl ;*/
	cout << "1/420" << endl ;
}