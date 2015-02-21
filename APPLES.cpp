#include <bits/stdc++.h>
using namespace std ;

const int UNSOLVED = -1 ;
int N , M ;

int solve(int i , int j , vector < vector <int> >& apples , vector < vector <int> >& solution) {
	if(solution[i][j] == UNSOLVED) {
		if(i == N - 1)
			solution[i][j] = apples[i][j] + solve(i , j + 1 , apples , solution) ;
		else if(j == M - 1)
			solution[i][j] = apples[i][j] + solve(i + 1 , j , apples , solution) ;
		else
			solution[i][j] = apples[i][j] + max(solve(i , j + 1 , apples , solution) , solve(i + 1 , j , apples , solution)) ;
	}
	return solution[i][j] ;
}


int main() {
	scanf("%d %d" , &N , &M) ;
	vector < vector <int> > apples(N , vector <int> (M)) ;
	vector < vector <int> > solution(N , vector <int> (M , UNSOLVED)) ;
	for(int i = 0 ; i < N ; i++)
		for(int j = 0 ; j < M ; j++)
			scanf("%d" , &apples[i][j]) ;
	solution[N - 1][M - 1] = apples[N - 1][M - 1] ;
	printf("%d\n" , solve(0 , 0 , apples , solution)) ;
}