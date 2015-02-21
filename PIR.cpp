#include <bits/stdc++.h>
using namespace std ;

int main() {
	int t ;
	double ab , ac , ad , bc , bd , cd ;
	double U , V , W , u , v , w , X , x , Y , y , Z , z ;
	double a , b , c , d ;
	scanf("%d" , &t) ;
	while(t--) {
		scanf("%lf %lf %lf %lf %lf %lf" , &ab , &ac , &ad , &bc , &bd , &cd) ;
		U = ab ; V = ac ; W = bc ; u = cd ; v = bd ; w = ad ;
		X = (w - U + v) * (U + v + w) ;
		x = (U - v + w) * (v - w + U) ;
		Y = (u - V + w) * (V + w + u) ;
		y = (V - w + u) * (w - u + V) ;
		Z = (v - W + u) * (W + u + v) ;
		z = (W - u + v) * (u - v + W) ;
		a = sqrt(x * Y * Z) ;
		b = sqrt(y * Z * X) ;
		c = sqrt(z * X * Y) ;
		d = sqrt(x * y * z) ;
		printf("%.4lf\n" , sqrt((b + c + d - a) * (a + c + d - b)) * sqrt((a + b + d - c) * (a + b + c - d)) / (192 * u * v * w)) ;
	}
}