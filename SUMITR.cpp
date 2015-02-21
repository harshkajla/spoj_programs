#include<bits/stdc++.h>
#define x for(j=0;j<=i;j++)
using namespace std;int n,l,a[100][100],i,j;int main(){cin>>n;while(n--){cin>>l;for(i=0;i<l;i++)x cin>>a[i][j];for(i=l-2;i>=0;i--)x a[i][j]=a[i][j]+max(a[i+1][j],a[i+1][j+1]);cout<<a[0][0]<<endl;}}