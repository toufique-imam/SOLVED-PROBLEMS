#include<bits/stdc++.h>
using namespace std;

/*
#include<unordered_map>
#include<unordered_set>
*/

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
/* int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction
int len;
ll dp[20][20][20][20];
int v[20];
int l;
ll recur(int i,int lo,int hi,int zero)
{
    if(len-1-i+zero<i)
        return lo<=hi;
    ll &ans=dp[i][lo][hi][zero];
    if(ans!=-1)return ans;
    ans=0;
    int nlo,nhi;
    for(int d=0;d<=9;d++)
    {
        nlo=lo;
        nhi=hi;
        if(d<v[i] and i<nlo)
            nlo=i;
        if(d<v[len-i-1+zero] and len-i-1+zero<nlo)
            nlo=len-i-1+zero;
        if(d>v[i] and i<nhi)
            nhi=i;
        if(d>v[len-i-1+zero] and i<nhi)
            nhi=len-i-1+zero;
        ans+=recur(i+1,nlo,nhi,zero+(i==zero&&!d));
    }
    return ans;
}
void toarray(ll x)
{
    len=0;
    while(x>0)
    {
        v[len++]=x%10;
        x/=10;
    }
    for(int i=0;i<len/2;i++)
        swap(v[i],v[len-i-1]);
}
ll getcnt(ll xx)
{
    memset(dp,-1,sizeof dp);
    if(xx<0)
        return 0;
    if(xx<10)
        return xx+1;
    toarray(xx);
    return recur(0,len,len,0);
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int T=1; T<=test; T++)
    {
        ll a,b;
        sll(b,a);
        if(a<b)
            swap(a,b);
        b-=1;
        ll ans1=getcnt(a);
        ll ans2=getcnt(b);
        printf("Case %d: %lld\n",T,ans1-ans2);
    }
}
