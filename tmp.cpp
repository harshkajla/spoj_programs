#include <bits/stdc++.h>
using namespace std ;
int main() {
	char c ;
	for(int i = 0 ; i < 10 ; i++) {
		int res = 1 ;
		while(cin.get(c)) {
			if(c == '\n')
				break ;
			cout << c ;
		}
		cout << "done" << endl ;
	}
}