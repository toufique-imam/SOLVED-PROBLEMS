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
ll dp[109][109];
const ll mod=1000000;
int n,k;
ll recur(int rem,int taken)
{
    if(taken==k)
    {
        if(rem==0)return 1;
        return 0;
    }
    ll cur=0,x;
    if(dp[rem][taken]!=-1)return dp[rem][taken];
    for(int i=0;i<=n;i++)
    {
        x=rem-i;
        if(x<0)break;
        cur+=recur(x,taken+1);
        cur%=mod;
    }
    return dp[rem][taken]=cur;
}
int main()
{
    while(scanf("%d %d",&n,&k)==2 and (n+k)>0)
    {
        memset(dp,-1,sizeof dp);
        printf("%lld\n",recur(n,0));
    }
}
