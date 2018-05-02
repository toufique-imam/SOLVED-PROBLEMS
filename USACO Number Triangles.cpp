/*
ID: sabertooth9
LANG: C++11
TASK: numtri
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int v[1009][1009];
int n;
int main()
{
    freopen("numtri.in","r",stdin);
    freopen("numtri.out","w",stdout);
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)for(j=0;j<=i;j++)scanf("%d",&v[i][j]);
    for(i=n-2;i>-1;i--)for(j=0;j<=i;j++)v[i][j]+=max(v[i+1][j],v[i+1][j+1]);
    printf("%d\n",v[0][0]);
}
