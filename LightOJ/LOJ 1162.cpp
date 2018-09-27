/*
ID: sabertooth
LANG: C++11
TASK:
*/
#include<bits/stdc++.h>
//#include <unordered_map>
//#include <unordered_set>
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
int myLog2(int x)
{
    return __builtin_clz(1) - __builtin_clz(x);
}
const int N=1e5+3;
int table[N][20];
int cost[N];
vector<int>v[N];
int level[N];
int par[N];
int n;
void create_sparse()
{
    memset(table,-1,sizeof table);
    for(int i=1;i<n;i++)
        table[i][0]=par[i];
    for(int j=1;(1<<j)<=N;j++)
    {
        for(int i=1;i<n;i++)
        {
            if(table[i][j-1]!=-1)
                table[i][j]=table[table[i][j-1]][j-1];
        }
    }
}

void dfs(int x,int par)
{
    for(int i=0;i<v[x].size();i++)
    {
        if(par==v[x][i])continue;
        level[v[x][i]]=level[x]+1;
        dfs(v[x][i],x);
    }
}
int bin_sch(int node,int cc)
{
    int hi=myLog2(level[node]);
    int lo=0;
    int mid,ans=-1;
    if(cost[table[node][0]]<cc)return -1;
    while(hi>=lo)
    {
        mid=(lo+hi)/2;
        if(cost[table[node][mid]]>=cc)
        {
            ans=table[node][mid];
            lo=mid+1;
        }
        else
            hi=mid-1;
    }
    return ans;
}
int query(int node,int cc)
{
    int ans=node;
    int x=bin_sch(node,cc);
    while(x!=-1 and ans!=0)
    {
        ans=x;
        x=bin_sch(ans,cc);
    }
    return ans;
}
int main()
{
    TEST
    {
        for(int i=0;i<N;i++)v[i].clear();
        int q,a,b;
        scanf("%d %d",&n,&q);
        cost[0]=1;
        par[0]=-1;
        for(int i=1;i<n;i++)
        {
            scanf("%d %d",&par[i],&cost[i]);
            v[par[i]].push_back(i);
        }
        dfs(0,-1);
        create_sparse();
        printf("Case %d:\n",T);
        while(q--)
        {
            scanf("%d %d",&a,&b);
            printf("%d\n",query(a,b));
        }
    }
}
