#include <bits/stdc++.h>
using namespace std;int main(){char c;for(int i=0;i<10;i++){int res=1;while(cin.get(c)){if(c=='\n')break;if(c=='L'||c=='F'||c=='D'||c=='T')res<<=1;}printf("%d\n",res);}}