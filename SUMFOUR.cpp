#include <bits/stdc++.h>
using namespace std ;

int search(int lo , int hi , int elm , vector <int>& right) {
	if(lo <= hi) {
		int mid = (lo + hi) / 2 ;
		if(elm < right[mid])
			return search(lo , mid - 1 , elm , right) ;
		else if(elm > right[mid])
			return search(mid + 1 , hi , elm , right) ;
		else
			return mid ;
	}
	else
		return -1 ;
}

int main() {
	int N ;
	scanf("%d" , &N) ;
	vector <int> left ;
	vector <int> right ;
	vector <int> A(N) ;
	vector <int> B(N) ;
	vector <int> C(N) ;
	vector <int> D(N) ;
	for(int i = 0 ; i < N ; i++)
		scanf("%d %d %d %d" , &A[i] , &B[i] , &C[i] , &D[i]) ;

	for(int i = 0 ; i < N ; i++)
		for(int j = 0 ; j < N ; j++)
			left.push_back((A[i] + B[j]) * (-1)) ;

	for(int i = 0 ; i < N ; i++)
		for(int j = 0 ; j < N ; j++)
			right.push_back(C[i] + D[j]) ;

	sort(right.begin() , right.end()) ;
	unsigned long long res = 0 ;

	for(int i = 0 ; i < N * N ; i++)
		cout << left[i] << " " << right[i] << endl ;

	for(int i = 0 ; i < N * N ; i++) {
		if(search(0 , N * N - 1 , left[i] , right) != -1)
			res++ ;
	}
	printf("%lld\n" , res) ;
}