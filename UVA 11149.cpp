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
matrix I,zero;
int mod=10;
int K;
matrix mul(matrix A,matrix B)
{
    matrix c(K+1,vector<ll>(K+1));
    for(int i=1; i<=K; i++)
        for(int j=1; j<=K; j++)
            for(int k=1; k<=K; k++)
                c[i][j]=(c[i][j]+A[i][k]*B[k][j])%mod;
    return c;
}
matrix pow(matrix A,int p)
{
    if(p==0)return I;
    if(p==1)
        return A;
    if(p%2)
        return mul(A,pow(A,p-1));
    matrix x=pow(A,p/2);
    return mul(x,x);
}
matrix sum(matrix A,matrix B)
{
    matrix c(K+1,vector<ll>(K+1));
    for(int i=1; i<=K; i++)
        for(int j=1; j<=K; j++)
            c[i][j]=(A[i][j]+B[i][j])%mod;
    return c;
}
//def evaluate(x, n):
//    if(n==0):
//        return 0
//    if(n==1):
//        return 1
//    ret = 0
//    if(n%2==1):
//        ret = ret + int(math.pow(x, n-1))
//    n = n/2
//    return ret + evaluate(x, n)*(1 + int(math.pow(x, n)))
matrix base;
matrix bigsum(int p)
{
    if(p==0)
        return zero;
    if(p%2==1)
        return sum(mul(bigsum(p/2),sum(I,pow(base,p/2))),pow(base,p));
    p/=2;
    return mul(bigsum(p),sum(I,pow(base,p)));
}
int main()
{
    int p;
    bool f=0;
    while(scanf("%d %d",&K,&p)==2 and (K+p))
    {
        if(f)
            puts("");
        f=1;
        I=matrix(K+1,vector<ll>(K+1,0));
        zero=matrix(K+1,vector<ll>(K+1,0));
        for(int i=1;i<=K;i++)
            I[i][i]=1;
        base=matrix(K+1,vector<ll>(K+1));
        for(int i=1; i<=K; i++)
            for(int j=1; j<=K; j++)
            {
                scanf("%lld",&base[i][j]);
                base[i][j]=((base[i][j]%mod)+mod)%mod;
            }
        matrix ans=bigsum(p);
        for(int i=1; i<=K; i++,puts(""))
        {
            for(int j=1; j<=K; j++)
            {
                printf("%d",ans[i][j]);
                if(j!=K)
                    printf(" ");
            }
        }
    }
}
