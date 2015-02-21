#include <bits/stdc++.h>
using namespace std ;

int main() {
	int arr[] = {137 , 1315 , 73 , 136 , 255 , 1384 , 16385} ;
	for(int i = 0 ; i < 7 ; i++) {
		vector <int> indices ;
		while(arr[i] > 0) {
			indices.push_back(log10(arr[i]) / log10(2)) ;
			arr[i] = arr[i] - pow(2 , (int)(log10(arr[i]) / log10(2))) ;
		}

	}
}