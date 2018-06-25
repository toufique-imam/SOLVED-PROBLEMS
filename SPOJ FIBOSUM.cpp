#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
/*
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fbo         find_by_order
#define ook         order_of_key
*/
typedef long long ll;
typedef unsigned long long ull;
typedef vector< vector<ll> >matrix;
#define gcd(A,B)        __gcd(A,B)
#define PQ              priority_queue< ll,vector<ll>,greater<ll> >pq
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
#define seg_tree        lt=2*par,rg=2*par+1,mid=(st+en)/2
#define read            freopen("input.txt","r",stdin)
#define write           freopen("output.txt","w",stdout)
#define fast            ios_base::sync_with_stdio(0),cin.tie(0)
#define lead_zero(x)    __builtin_clzll(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
#define max_ull         18446744073709551615
#define max_ll          9223372036854775807;
#define set(N,cur)      N=(N|(1<<cur))
#define reset(N,cur)    N=(N&(~(1<<cur)))
#define check(N,cur)    ((N&(1<<cur))==0)
#define all(v)          v.begin(),v.end()
#define reunique(v)     v.resize(std::unique(all(v)) - v.begin())
#define loop            int test;scanf("%d",&test);for(int _T=1;_T<=test;_T++)
/*int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};   */// 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction
const ll mod=1000000007;
matrix mul(matrix A,matrix B)
{
    matrix c(4,vector<ll>(4));
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            for(int k=0; k<3; k++)
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
ll solve(int n)
{
    matrix T(4,vector<ll>(4));
    T[0][0]=T[0][1]=T[1][2]=T[2][1]=T[2][2]=1;
    ll b[]={0,0,1};
    if(n<1)return 0ll;
    T=pow(T,n+1);
    ll res=0;
    for(int i=0;i<3;i++)
        res=(res+T[0][i]*b[i])%mod;
    return res;
}
int main()
{
    int n,m;
    loop{
        scanf("%d %d",&n,&m);
        ll ans=((solve(m)-solve(n-1))%mod+mod)%mod;
        cout<<ans<<endl;
    }
}
