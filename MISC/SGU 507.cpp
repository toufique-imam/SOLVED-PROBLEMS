/*
ID: sabertooth
LANG: C++11
TASK:
*/
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cassert>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<unordered_map>
#include<iterator>
using namespace std;
typedef long long ll;

#define ff              first
#define ss              second
#define all(v)          v.begin(),v.end()
#define read            freopen("in.txt","r",stdin);
#define write           freopen("out.txt","w",stdout);
#define TEST            int test;scanf("%d",&test);for(int T=1;T<=test;T++)
#define lead_zero(x)    __builtin_clzll(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
#define reunique(v)     v.resize(std::unique(all(v)) - v.begin())
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
int myLog2(int x)
{
    return __builtin_clz(1) - __builtin_clz(x);
}
ll myLog2(ll x)
{
    return __builtin_clzll(1) - __builtin_clzll(x);
}
const int N=50009;
int mini[N];
int dsu[N];
set<int>s[N];
vector<int>v[N];
int cost[N];
int tim;
int sz[N];
void dfs(int x,int par)
{
    sz[x]=1;
    if(v[x].size()==0 || (v[x].size()==1 and v[x][v[x].size()-1]==par))
    {
        dsu[x]=++tim;
        s[tim].insert(cost[x]);
        mini[x]=2147483647;
        return;
    }
    int Bigchild=N-1,mx=0;
    for(auto i:v[x])
    {
        if(i==par)continue;
        dfs(i,x);
        sz[x]+=sz[i];
        if(sz[i]>mx)
        {
            mx=sz[i];
            Bigchild=i;
        }
    }
    dsu[x]=dsu[Bigchild];
    s[x]=s[Bigchild];
    mini[x]=mini[Bigchild];
    int xy,yx;
    for(auto i:v[x])
    {
        if(i==Bigchild)continue;
        for(auto j:s[dsu[i]])
        {
            s[dsu[x]].insert(j);
            auto xx=s[dsu[x]].find(j);
            xy=*xx;
            auto itr=xx;
            if(xx!=s[dsu[x]].begin())
            {
                itr--;
                yx=*itr;
                mini[x]=min(mini[x],abs(xy-yx));
            }
            itr=xx;
            itr++;
            if(itr!=s[dsu[x]].end())
            {
                yx=*itr;
                mini[x]=min(mini[x],abs(xy-yx));
            }
        }
    }
}
int main()
{
    int n,m,x;
    scanf("%d %d",&n,&m);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&x);
        v[x].push_back(i);
    }
    for(int i=n-m+1;i<=n;i++)
        scanf("%d",&cost[i]);
    dfs(1,0);
    for(int i=1;i<=n-m;i++)
        printf("%d ",mini[i]);
    puts("");
}
