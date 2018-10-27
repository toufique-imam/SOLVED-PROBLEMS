/*
ID: sabertooth
LANG: C++11
TASK:
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define eps             1e-9
#define inf             0x3f3f3f3f
#define INF             2e18
#define PI              acos(-1.0)
#define ff              first
#define ss              second
#define all(v)          v.begin(),v.end()
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(min(a,b),min(c,d))
#define max4(a,b,c,d)   max(max(a,b),max(c,d))
#define max5(a,b,c,d,e) max(max3(a,b,c),max(d,e))
#define min5(a,b,c,d,e) min(min3(a,b,c),min(d,e))
#define Iterator(a)     __typeof__(a.begin())
#define read            freopen("in.txt","r",stdin);
#define write           freopen("out.txt","w",stdout);
#define TEST            int test;scanf("%d",&test);for(int T=1;T<=test;T++)
#define lead_zero(x)    __builtin_clzll(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
#define reunique(v)     v.resize(std::unique(all(v)) - v.begin())
#define MP              make_pair
#define PB              push_back
#define EB              emplace_back
#define segtree         int mid=(st+en)/2,lt=node*2,rg=node*2+1
#define MERGE(v1,v2,v)  merge(all(v1),all(v2),back_inserter(v))

const int N=2000+9;
vector<int>v[N];
int color[N];
void cln()
{
    for(int i=0;i<N;i++){
        v[i].clear();
    }
    memset(color,-1,sizeof color);
}
bool dfs(int x,int col){
    int rev=col^1,now;
    color[x]=col;
    bool f=1;
    for(int i=0;i<(int)v[x].size();i++){
        now=v[x][i];
        if(color[now]==-1){
            f=dfs(now,rev);
            if(f==0)return f;
        }
        else if(color[now]==color[x]){
            return 0;
        }
    }
    return 1;
}
int main()
{
    TEST
    {
        cln();
        int n,m,a,b;
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            v[a].EB(b);
            v[b].EB(a);
        }
        bool f=1;
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                f=dfs(i,0);
                if(!f)break;
            }
        }
        printf("Scenario #%d:\n",T);
        if(!f){
            puts("Suspicious bugs found!");
        }
        else{
            puts("No suspicious bugs found!");
        }
    }
}
