#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std ;
int main() {
	srand(time(NULL)) ;
	cout << 20 << endl ;
	for(int i = 0 ; i < 20 ; i++)
		cout << rand() % 1001 << endl ;
}