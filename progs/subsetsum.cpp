#include <iostream>
#include <stdio.h>
using namespace std ;

bool subsetSum(int * a , int n , int sum) {
	//subset[i][j] returns true if it is possible to get a sum of i using a[0 .. j - 1]
	bool subset[sum + 1][n + 1] ;
	//if sum is 0, then always true
	for(int j = 0 ; j <= n ; j++)
		subset[0][j] = true ;
	//if sum is non zero but the set is 0 then false
	for(int i = 1 ; i <= sum ; i++)
		subset[i][0] = false ;
	//general case
	for(int i = 1 ; i <= sum ; i++) {
		for(int j = 1 ; j <= n ; j++) {
			subset[i][j] = subset[i][j - 1] ;
			if(i >= a[j - 1])
				subset[i][j] = subset[i][j - 1] || subset[i - a[j - 1]][j - 1] ;
		}
	}
	return subset[sum][n] ;
}

int main () {
	int n ;
	scanf("%d" , &n) ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++)
		scanf("%d" , &a[i]) ;
	int sum ;
	scanf("%d" , &sum) ;
	bool b = subsetSum(a , n , sum) ;
	printf("%d\n" , b) ;
}
