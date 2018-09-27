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
const int N=5000;
vector<int>v[N+2];
int sparse_table[N+2][18];
int T[N+2];
int level[N+2];
int power[18];
int pwrsz;
void cln()
{
    memset(T,-1,sizeof T);
    for(int i=0;i<=N;i++)
        v[i].clear();
    memset(level,0,sizeof level);
}
void dfs(int x,int par)
{
    for(int i=0;i<(int)v[x].size();i++)
    {
        int u=v[x][i];
        if(u==par)continue;
        level[u]=level[x]+1;
        T[u]=x;
        dfs(u,x);
    }
}
void create_sparse(int n)
{
    memset(sparse_table,-1,sizeof sparse_table);
    for(int i=1;i<=n;i++)sparse_table[i][0]=T[i];
    for(int j=0;(1<<j)<n;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(sparse_table[i][j-1]!=-1)
                sparse_table[i][j]=sparse_table[sparse_table[i][j-1]][j-1];
        }
    }
}
int bin_sch(int key)
{
    int lo=0,hi=pwrsz-1,mid,ans=0;
    while(hi>=lo)
    {
        mid=(lo+hi)>>1;
        if(power[mid]<=key)
        {
            lo=mid+1;
            ans=mid;
        }
        else
            hi=mid-1;
    }
    return ans;
}
int find_kth_par(int v1,int k)
{
    int ans=v1;
    while(k>0)
    {
        int x=bin_sch(k);
        k-=power[x];
        ans=sparse_table[ans][x];
    }
    return ans;
}
int LCA(int v1,int v2)
{
    if(level[v1]<level[v2])swap(v1,v2);
    int lg=1;
    int nxt=lg+1;
    while((1<<nxt)<=level[v1])
    {
        lg++;
        nxt=lg+1;
    }
    for(int i=lg;i>-1;i--)
        if(level[v1]-(1<<i)>=level[v2])
            v1=sparse_table[v1][i];
    if(v1==v2)
        return v1;
    for(int i=lg;i>-1;i--)
    {
        if(sparse_table[v1][i]!=-1 and sparse_table[v1][i]!=sparse_table[v2][i])
            v1=sparse_table[v1][i],v2=sparse_table[v2][i];
    }
    return T[v1];
}
pair<bool,pii> find_dist(int v1,int v2)
{
    if(level[v1]<level[v2])swap(v1,v2);
    int x=LCA(v1,v2);
    int X=level[v1]+level[v2]-2*level[x];
    bool f=0;
    int ans1=0,ans2=0;
    if(X%2==0)
    {
        f=1;
        ans1=find_kth_par(v1,X/2);
    }
    else
    {
        ans1=find_kth_par(v1,X/2+1);
        ans2=find_kth_par(v1,X/2);
    }
    return make_pair(f,make_pair(ans1,ans2));
}

int main()
{
    for(pwrsz=0;(1<<pwrsz)<=N;pwrsz++)
        power[pwrsz]=(1<<pwrsz);
    int n;
    while(scanf("%d",&n)==1 and n)
    {
        cln();
        int a,b;
        for(int i=1;i<n;i++)
        {
            scanf("%d %d",&a,&b);
            v[a].pb(b);
            v[b].pb(a);
        }
        dfs(1,0);
        create_sparse(n);
        int q;
        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            scanf("%d %d",&a,&b);
            pair<bool,pii>p=find_dist(a,b);
            if(p.ff)
                printf("The fleas meet at %d.\n",p.ss.ff);
            else
                printf("The fleas jump forever between %d and %d.\n",min(p.ss.ff,p.ss.ss),max(p.ss.ff,p.ss.ss));
        }
    }
}

