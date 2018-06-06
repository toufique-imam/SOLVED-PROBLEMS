#include<bits/stdc++.h>
//#include<unordered_map>
//#include<unordered_set>
 
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
/*
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
priority_queue<int, greater<int>, pairing_heap_tag> pq[1009];
#define fbo         find_by_order
#define ook         order_of_key
*/
typedef long long ll;
typedef unsigned long long ull;
typedef vector< vector<ll> >matrix;
#define gcd(A,B)        __gcd(A,B)
#define PQ              priority_queue
#define ii              int,int
#define pll             pair<ll,ll>
#define PI              2*acos(0.0)
#define all(v)          v.begin(),v.end()
#define pii             pair<ii>
#define pb              push_back
#define sf(x)           scanf("%I64d",&x)
#define sff(x,y)        scanf("%I64d %I64d",&x,&y)
#define sl(x)           scanf("%lld",&x)
#define sll(x,y)        scanf("%lld %lld",&x,&y)
#define ff              first
#define ss              second
#define segtree         lt=2*par,rg=2*par+1,mid=(st+en)/2
#define read            freopen("input.txt","r",stdin)
#define write           freopen("output.txt","w",stdout)
#define fast            ios_base::sync_with_stdio(0),cin.tie(0)
#define lead_zero(x)    __builtin_clzll(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
#define max_ull         18446744073709551615
#define max_ll          9223372036854775807;
#define set(N,cur)      N=(N|(1LL<<cur))
#define reset(N,cur)    N=(N&(~(1LL<<cur)))
#define check(N,cur)    ((N&(1LL<<cur))==0)
#define all(v)          v.begin(),v.end()
#define reunique(v)     v.resize(std::unique(all(v)) - v.begin())
/* int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction
vector< pii >v[109];
vector< pii >vx[109];
int k;
pii dp[109][109][109][2];
void cln()
{
    for(int i=0; i<109; i++)
        v[i].clear();
    for(int i=0; i<109; i++)
        vx[i].clear();
    memset(dp,-1,sizeof dp);
}
void dfsx(int x,int par)
{
    for(int i=0; i<(int)vx[x].size(); i++)
    {
        int y=vx[x][i].ff;
        if(par!=y)
        {
            dfsx(y,x);
            v[x].push_back(vx[x][i]);
        }
    }
}
pii dfs(int par,int idx,int w,int connected)
{
    if(idx==v[par].size())
        return {w,connected};
    pii &ans=dp[par][idx][w][connected];
    if(ans.ff!=-1)
        return ans;
    ans= {1e9,1e9};
    pii t1,t2;
    if(w+v[par][idx].ss<=k)
    {
        t1=dfs(v[par][idx].ff,0,w+v[par][idx].ss,0);//connected with par
        t2=dfs(par,idx+1,t1.ff,connected);//next child
        ans= {t2.ff,t1.ss+t2.ss};
    }
    t1=dfs(v[par][idx].ff,0,0,1);//not connected
    t2=dfs(par,idx+1,w,connected);
    t2.ss+=t1.ss;
    if(t2.ss<ans.ss)
        ans=t2;
    else if(t2.ss==ans.ss and t2.ff<ans.ff)
        ans=t2;
    return ans;
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int T=1; T<=test; T++)
    {
        int n;
        scanf("%d %d",&n,&k);
        int a,b,c;
        cln();
        for(int i=1; i<n; i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            vx[a].push_back(make_pair(b,c));
            vx[b].push_back(make_pair(a,c));
        }
        dfsx(1,0);
        pii ans=dfs(1,0,0,1);
        printf("Case %d: %d\n",T,min(n,ans.ss));
    }
}
 
