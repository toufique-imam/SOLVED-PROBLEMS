/*
ID:sabertooth9
TASK:
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;
#define ll              long long
#define pb              push_back
#define read(s)         freopen(#s,"r",stdin)
#define write(s)        freopen(#s,"w",stdout)
#define lead_zero(x)    __builtin_clzll(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
#define mod             1000000007
#define all(v)          v.begin(),v.end()
#define maxx            100000

vector< pair<int,int> >qq;
int ax[]= {1,-1,0,0};
int ay[]= {0,0,-1,1};
vector<int>v[maxx+9];
int visited[maxx+9];
int lykans,vamp;

void clean()
{
    qq.clear();
    for(int i=0; i<maxx; i++)
        v[i].clear();
    memset(visited,-1,sizeof(visited));
    lykans=0,vamp=0;
}

void dfs(int child,int spices)
{
    if(spices==0)
        lykans++;
    else
        vamp++;
    visited[child]=spices;
    for(int i=0; i<v[child].size(); i++)
        if(visited[v[child][i]]==-1)
            dfs(v[child][i],!(1&spices));
    return;
}

void dfs1(int child)
{
    visited[child]=-1;
    for(int i=0; i<v[child].size(); i++)
    {
        if(visited[v[child][i]]!=-1)
            dfs1(v[child][i]);
    }
    return;
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int _t=1; _t<=test; _t++)
    {
        clean();
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
            qq.push_back(make_pair(a,b));
        }
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            if(visited[qq[i].first]==-1)
            {
                vamp=0,lykans=0;
                dfs(qq[i].first,0);
                int t1=max(vamp,lykans);
                vamp=0,lykans=0;
                dfs1(qq[i].first);
                dfs(qq[i].first,1);
                int t2=max(vamp,lykans);
                cnt+=max(t1,t2);
                lykans=0,vamp=0;
            }
        }
        printf("Case %d: %d\n",_t,cnt);
    }
}

