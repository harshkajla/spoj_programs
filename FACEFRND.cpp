#include <bits/stdc++.h>
using namespace std ;

int main() {
	int N , x , M ;
	scanf("%d" , &N) ;
	set <int> friends , friends_of_friends ;
	for(int i = 0 ; i < N ; i++) {
		scanf("%d" , &x) ;
		friends.insert(x) ;
		scanf("%d" , &M) ;
		for(int j = 0 ; j < M ; j++) {
			scanf("%d" , &x) ;
			friends_of_friends.insert(x) ;
		}
	}
	set <int> :: iterator it = friends.begin() ;
	for( ; it != friends.end() ; it++)
		friends_of_friends.erase(*it) ;
	int res = friends_of_friends.size() ;
	printf("%d" , res) ;
}