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
vector< int >v[1009];
int dp1[1009];
int dp2[1009];
bool visited[1009];
void cln()
{
    memset(visited,0,sizeof visited);
    memset(dp1,0,sizeof dp1);
    memset(dp2,0,sizeof dp2);
    for(int i=0;i<1009;i++)v[i].clear();
}
void recur(int u,int par)
{
    visited[u]=1;
    int sum1,sum2;
    sum1=sum2=0;
    for(int i=0;i<(int)v[u].size();i++)
    {
        int x=v[u][i];
        if(x==par)continue;
        recur(x,u);
        sum1+=dp2[x];
        sum2+=max(dp1[x],dp2[x]);
    }
    dp1[u]=1+sum1;
    dp2[u]=sum2;
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int T=1; T<=test; T++)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        int a,b;
        cln();
        for(int i=0; i<m; i++)
        {
            scanf("%d %d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                recur(i,0);
                ans+=max(dp1[i],dp2[i]);
            }
        }
        printf("Case %d: %d\n",T,ans);
    }
}
