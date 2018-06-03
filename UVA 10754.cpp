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
typedef vector< vector<ll> >matrix;
/* int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction
ll mod;
int K;
ll c[25];
ll b[25];
//    for(int i=1; i<=K+1; i++)
//    {
//        for(int j=1; j<=K+1; j++)
//            cout<<T[i][j]<<" ";
//        cout<<endl;
//    }
/*
1
2 10 10
1 1 0
1 1
*/
matrix mul(matrix A,matrix B)
{
    matrix c(K+2,vector<ll>(K+2,0));
    for(int i=0; i<=K; i++)
        for(int j=0; j<=K; j++)
            for(int k=0; k<=K; k++)
                c[i][j]=(c[i][j]+A[i][k]*B[k][j])%mod;
    return c;
}
matrix pow(matrix A,int p)
{
    if(p==1)
        return A;
    if(p%2)
        return mul(A,pow(A,p-1));
    matrix x=pow(A,p/2);
    return mul(x,x);
}
ll solve(ll n)
{
    if(n<K)
        return b[n];
    matrix T(K+2,vector<ll>(K+2));
    for(int i=0; i<K; i++)
        T[0][i]=c[i+1];
    for(int i=1; i<K; i++)
        T[i][i-1]=1;
    T[0][K]=1;
    T[K][K]=1;
    T=pow(T,n-K+1);
    ll res=0;
    for(int i=0; i<K; i++)
        res=(res+T[0][i]*b[K-1-i])%mod;
    res=(res+T[0][K]*c[K+1])%mod;
    return res;
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int T=1; T<=test; T++)
    {
        if(T!=1)
            puts("");
        ll n;
        scanf("%d %lld %lld",&K,&mod,&n);
        for(int i=1; i<=K+1; i++)
        {
            sl(c[i]);
            c[i]=((c[i]%mod)+mod)%mod;
        };
        for(int i=0;i<K;i++)
        {
            sl(b[i]);
            b[i]=((b[i]%mod)+mod)%mod;
        }
        printf("%lld\n",solve(n));
    }
}
