#include <bits/stdc++.h>
using namespace std;
string s;
int A;
int modulo(int p) {
	int r = 0 ;
	for(int i = 0 ; i < s.length() ; i++) {
		r = 10 * r + s[i] - '0' ;
		r = r % p ;
	}
	return r ;
}
int gcd(int m , int n) {
	if(min(m , n) == 0)
		return max(m , n);
	return gcd(max(m , n) % min(m , n) , min(m , n));
}
int main() {
	int T , B;
	scanf("%d" , &T);
	while(T--) {
		scanf("%d" , &A);
		cin >> s;
		if(s == "0")
			printf("%d\n" , A);
		else if(A == 0)
			cout << s << endl;
		else {
			B = modulo(A);
			printf("%d\n" , gcd(A , B));
		}
	}
}