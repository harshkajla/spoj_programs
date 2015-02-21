#include <bits/stdc++.h>
using namespace std ;

class matrix {
	public :
	int a , b , c , d ;
	matrix() {
		a = d = 1 ;
		b = c = 0 ;
	}
	void set(int p , int q , int r , int s) {
		a = p ; b = q ; c = r ; d = s ;
	}
	matrix operator*(matrix m) {
		matrix res ;
		res.set(a * m.a + b * m.c , a * m.b + b * m.d , c * m.a + d * m.c , c * m.b + d * m.d) ;
		return res ;
	}
} ;

matrix power(matrix& m , int n) {
	if(n == 0) {
		matrix t ;
		return t ;
	}
	else if(n % 2 == 1)
		return m * power(m , n - 1) ;
	else {
		matrix c = power(m , n / 2) ;
		return c * c ;
	}
}

int main() {
	int T , n , m ;
	scanf("%d" , &T) ;
	while(T--) {
		scanf("%d %d" , &n , &m) ;
		
	}
}