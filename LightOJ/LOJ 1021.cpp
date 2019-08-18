#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include <iomanip>
using namespace std;
//#include<unordered_map>
//#include<unordered_set>
typedef long long ll;
typedef unsigned long long ull;
#define gcd(A,B)        __gcd(A,B)
#define PQ 			    priority_queue
#define ii 			    int,int
#define pll             pair<ll,ll>
#define PI              2*acos(0.0)
#define all(v)          v.begin(),v.end()
#define pii 		    pair<ii>
#define pb              push_back
#define sf(x) 		    scanf("%I64d",&x)
#define sff(x,y) 	    scanf("%I64d %I64d",&x,&y)
#define sl(x)   	    scanf("%lld",&x)
#define sll(x,y)   	    scanf("%lld %lld",&x,&y)
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
#define set_(n,pos)     (n|(1<<pos))
#define check(n,pos)    (n &(1<<pos))
#define toggle(n,pos)   (n ^(1<<pos))
#define off(n,pos)      if(!check(n,pos))toggle(n,pos)
using namespace std;
ll get_digit(char x)
{
    if(x>='0' and x<='9')
        return (x-'0');
    else
        return (x-'A')+10;
}
ll limit,sz;
ll dp[65540][20];
ll base,k;
string s;
ll calc(ll so_far,char xy)
{
    return (so_far*base+get_digit(xy))%k;
}
ll recur(int mask,int so_far)
{
    if(mask>=limit)
        return so_far==0;
    if(dp[mask][so_far]!=-1)
        return dp[mask][so_far];
    ll r=0;
    for(int i=0; i<sz; i++)
        if(!(mask&(1<<i)))
            r+=recur(mask|(1<<i),calc(so_far,s[i]));

    return dp[mask][so_far]=r;
}
int main()
{
    fast;
    int test;
    cin>>test;
    for(int T=1; T<=test; T++)
    {
        cin>>base>>k>>s;
        memset(dp,0,sizeof dp);
        sz=s.size();
        limit=(1<<sz);
        dp[0][0]=1;
        for(int mask=0; mask<limit; mask++)
            for(int rem=0; rem<k; rem++)
                for(int i=0; i<sz; i++)
                    if(!check(mask,i))
                        dp[mask|(1<<i)][(rem*base+get_digit(s[i]))%k]+=dp[mask][rem];
        cout<<"Case "<<T<<": "<<dp[limit-1][0]<<endl;
    }
}
