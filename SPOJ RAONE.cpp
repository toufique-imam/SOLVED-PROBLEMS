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
string x;
int n;
ll dp[9][2][2][73][73];
ll recurOdd(int pos,bool isStrt,bool isSml,int evensum,int oddsum)
{
    if(pos>=n)
        return evensum-oddsum==1;
    ll &ans=dp[pos][isStrt][isSml][evensum][oddsum];
    if(ans!=-1)
        return ans;
    ans=0;
    int es,os;
    int limit=isSml==1?9:x[pos]-'0';
    if(isStrt)
    {
        for(int i=1; i<=limit; i++)
        {
            es=evensum;
            os=oddsum;
            if(pos&1)
                ans+=recurOdd(pos+1,0,(isSml|(i<x[pos]-'0')),es+i,os);
            else
                ans+=recurOdd(pos+1,0,(isSml|(i<x[pos]-'0')),es,os+i);
        }
        ans+=recurOdd(pos+1,1,1,0,0);
    }
    else
        for(int i=0; i<=limit; i++)
        {
            es=evensum;
            os=oddsum;
            if(pos&1)
                ans+=recurOdd(pos+1,0,(isSml|(i<x[pos]-'0')),es+i,os);
            else
                ans+=recurOdd(pos+1,0,(isSml|(i<x[pos]-'0')),es,os+i);
        }
    return ans;
}
ll recureven(int pos,bool isStrt,bool isSml,int evensum,int oddsum)
{
    if(pos>=n)
        return evensum-oddsum==1;
    ll &ans=dp[pos][isStrt][isSml][evensum][oddsum];
    if(ans!=-1)
        return ans;
    ans=0;
    int es,os;
    int limit=isSml==1?9:x[pos]-'0';
    if(isStrt)
    {
        for(int i=1; i<=limit; i++)
        {
            es=evensum;
            os=oddsum;
            if(pos&1)
                ans+=recureven(pos+1,0,(isSml|(i<x[pos]-'0')),es,os+i);
            else
                ans+=recureven(pos+1,0,(isSml|(i<x[pos]-'0')),es+i,os);
        }
        ans+=recureven(pos+1,1,1,0,0);
    }
    else
        for(int i=0; i<=limit; i++)
        {
            es=evensum;
            os=oddsum;
            if(pos&1)
                ans+=recureven(pos+1,0,(isSml|(i<x[pos]-'0')),es,os+i);
            else
                ans+=recureven(pos+1,0,(isSml|(i<x[pos]-'0')),es+i,os);
        }
    return ans;
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int T=1; T<=test; T++)
    {
        memset(dp,-1,sizeof dp);
        ll p,q;
        sll(p,q);
        x=to_string(q);
        n=x.size();
        ll ans;
        if(n&1)
            ans=recurOdd(0,1,0,0,0);
        else
            ans=recureven(0,1,0,0,0);
        memset(dp,-1,sizeof dp);
        p--;
        if(p>0)
        {
            x=to_string(p);
            n=x.size();
            memset(dp,-1,sizeof dp);
            if(n&1)ans-=recurOdd(0,1,0,0,0);
            else ans-=recureven(0,1,0,0,0);
        }
        printf("%lld\n",ans);
    }
}
