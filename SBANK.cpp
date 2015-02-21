#include <bits/stdc++.h>
using namespace std ;

int n ;
class bank_account {
	public:
		string a , b , c , d , e , f ;
		bank_account() {
		}
		bank_account(const bank_account& other) {
			a = other.a ;
			b = other.b ;
			c = other.c ;
			d = other.d ;
			e = other.e ;
			f = other.f ;
		}
		void read() {
			cin >> a >> b >> c >> d >> e >> f ;
		}
		void print() {
			cout << a << " " << b << " " << c << " " << d << " " << e << " " << f ;
		}
		bool operator == (const bank_account& other) {
			if(a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f)
				return true ;
			else
				return false ;
		}
} ;

bool compare(const bank_account& one , const bank_account& two) {
	if(one.a < two.a)
		return true ;
	else if(one.a == two.a) {
		if(one.b < two.b)
			return true ;
		else if(one.b == two.b) {
			if(one.c < two.c)
				return true ;
			else if(one.c == two.c) {
				if(one.d < two.d)
					return true ;
				else if(one.d == two.d) {
					if(one.e < two.e)
						return true ;
					else if(one.e == two.e) {
						if(one.f < two.f)
							return true ;
						else
							return false ;
					}
					else
						return false ;
				}
				else
					return false ;
			}
			else
				return false ;
		}
		else
			return false ;
	}
	else
		return false ;
}

int main() {
	int T ;
	scanf("%d" , &T) ;
	while(T--) {
		scanf("%d" , &n) ;
		vector <bank_account> account_number(n) ;
		for(int i = 0 ; i < n ; i++) {
			account_number[i].read() ;
		}
		sort(account_number.begin() , account_number.end() , compare) ;
		bank_account prev(account_number[0]) ;
		int count = 1 ;
		for(int i = 1 ; i < n ; i++) {
			if(account_number[i] == prev)
				count++ ;
			else {
				prev.print() ;
				printf(" %d\n" , count) ;
				count = 1 ;
				prev.a = account_number[i].a ; prev.b = account_number[i].b ; prev.c = account_number[i].c ;
				prev.d = account_number[i].d ; prev.e = account_number[i].e ; prev.f = account_number[i].f ;
			}
		}
		prev.print() ;
		printf(" %d\n\n" , count) ;
	}
}