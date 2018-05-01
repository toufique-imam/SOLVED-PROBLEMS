/*
ID: sabertooth9
LANG: C++11
TASK: ariprog
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int pre[62509];
int v[300];
int high;
bool cnt[125009];
void gen_bisquares()
{
    int pos=0;
    int sz=0;
    for(int i=0; i<=m; i++)
        v[sz++]=i*i;
    for(int i=0; i<sz; i++)for(int j=i; j<sz; j++)cnt[v[i]+v[j]]=1;
}
bool cando(int base,int dif,int high)
{
    int cntt=0;
    for(int i=base;; i+=dif)
    {
        if(i>high)
            return 0;
        if(cnt[i])
            cntt++;
        else
            break;
        if(cntt==n)
            return 1;
    }
    return 0;
}
int main()
{
    freopen("ariprog.in","r",stdin);
    freopen("ariprog.out","w",stdout);
    scanf("%d %d",&n,&m);
    gen_bisquares();
    high=2*m*m;
    vector< pair<int,int> >vx;
    bool f=0;
    for(int i=1; i<=high/(n-1); i++)for(int j=0; j<=m*m; j++)if(cnt[j] and (cnt[j+(n-1)*i]) and cando(j,i,high))printf("%d %d\n",j,i),f=1;
    if(!f)printf("NONE\n");
}
