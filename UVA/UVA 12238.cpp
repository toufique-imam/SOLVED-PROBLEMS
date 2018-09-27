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
#define loop            int test;scanf("%d",&test);for(int T=1;T<=test;T++)
/* int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction
const int N=1e5;
ll dist[N+2];
int level[N+2];
vector< pii>v[N+2];
int spaerse_table[N+2][30];
int T[N+2];
void cln()
{
    memset(T,-1,sizeof T);
    memset(spaerse_table,-1,sizeof spaerse_table);
    for(int i=0;i<=N;i++)
        v[i].clear();
    memset(level,0,sizeof level);
    memset(dist,0,sizeof dist);
}
void dfs(int x,int par)
{
    for(int i=0;i<(int)v[x].size();i++)
    {
        int u=v[x][i].ff;
        int dis=v[x][i].ss;
        if(u==par)continue;
        T[u]=x;
        dist[u]=dist[x]+dis;
        level[u]=level[x]+1;
        dfs(u,x);
    }
}
void create_sparse(int n)
{
    for(int i=0;i<=n;i++)
        spaerse_table[i][0]=T[i];
    for(int j=0;(1<<j)<n;j++)
        for(int i=0;i<=n;i++)
            if(spaerse_table[i][j-1]!=-1)
                spaerse_table[i][j]=spaerse_table[spaerse_table[i][j-1]][j-1];
}
int LCA(int v1,int v2)
{
    if(level[v1]<level[v2])swap(v1,v2);
    int lg=1,nxt=lg+1;
    while((1<<nxt)<=level[v1])
    {
        lg++;
        nxt=lg+1;
    }
    for(int i=lg;i>-1;i--)
    {
        if(level[v1]-(1<<i)>=level[v2])
            v1=spaerse_table[v1][i];
    }
    if(v1==v2)
        return v1;
    for(int i=lg;i>-1;i--)
    {
        if(spaerse_table[v1][i]!=-1 and spaerse_table[v1][i]!=spaerse_table[v2][i])
            v1=spaerse_table[v1][i],v2=spaerse_table[v2][i];
    }
    return T[v1];
}
ll find_dist(int v1,int v2)
{
    int x=LCA(v1,v2);
    ll X=dist[v1]+dist[v2]-2*dist[x];
    return X;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1 and n)
    {
        cln();
        int a,b;
        for(int i=1;i<n;i++)
        {
            scanf("%d %d",&a,&b);
            v[i].push_back(make_pair(a,b));
            v[a].push_back(make_pair(i,b));
        }
        dfs(0,-1);
        create_sparse(n);
        int q;
        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            scanf("%d %d",&a,&b);
            printf("%lld",find_dist(a,b));
            if(i!=q-1)
                printf(" ");
        }
        printf("\n");
    }
}
