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
using namespace std;
//#include<unordered_map>
typedef long long ll;
typedef unsigned long long ull;
//#define gcd(A,B)    __gcd(A,B)
#define PQ 			priority_queue
#define ii 			int,int
#define pll         pair<ll,ll>
#define PI          2*acos(0.0)
#define all(v)      v.begin(),v.end()
#define pii 		pair<ii>
#define sf(x) 		scanf("%I64d",&x)
#define sff(x,y) 	scanf("%I64d %I64d",&x,&y)
#define sl(x)   	scanf("%lld",&x)
#define sll(x,y)   	scanf("%lld %lld",&x,&y)
#define ff          first
#define ss          second
#define segtree     lt=2*par,rg=2*par+1,mid=(st+en)/2
#define read        freopen("input.txt","r",stdin)
#define write       freopen("output.txt","w",stdout)
using namespace std;
int coin[100],cnt[100],n;
ll dp[1009][1009];
const ll mod=100000007;
ll recur(int idx,int rem)
{
    if(idx>=n)
    {
        if(rem==0)return 1;
        return 0;
    }

    if(dp[idx][rem]!=-1)return dp[idx][rem];
    ll cur=0;
    for(int i=0;i<=cnt[idx];i++)
    {
        ll x=rem-coin[idx]*i;
        if(x<0)break;
        cur+=recur(idx+1,x);
        cur%=mod;
    }
    return dp[idx][rem]=cur;
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int T=1;T<=test;T++)
    {
        int k;
        scanf("%d %d",&n,&k);
        memset(dp,-1,sizeof dp);
        for(int i=0;i<n;i++)scanf("%d",coin+i);
        for(int i=0;i<n;i++)scanf("%d",cnt+i);
        printf("Case %d: %lld\n",T,recur(0,k));
    }
}
