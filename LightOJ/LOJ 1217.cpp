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
#define set(N,cur)      N=(N|(1LL<<cur))
#define reset(N,cur)    N=(N&(~(1LL<<cur)))
#define check(N,cur)    (!((N&(1LL<<cur))==0))
#define all(v)          v.begin(),v.end()
using namespace std;
int n;
const int N= 1000;
int ara[N+3];
int dp[N+3][2];
int recur(int pos,int taken)
{
    if(pos>=n){return 0;}
    if(dp[pos][taken]!=-1)return dp[pos][taken];
    int r1=0;
    if(pos==n-1){
        if(!taken)
            return dp[pos][taken]=ara[pos]+recur(pos+1,taken);
        else
            return dp[pos][taken]=recur(pos+1,taken);
    }
    else if(pos==0)
    {
        r1=ara[pos]+recur(pos+2,1);
        r1=max(r1,recur(pos+1,0));
    }
    else
    {
        r1=ara[pos]+recur(pos+2,taken);
        r1=max(r1,recur(pos+1,taken));
    }
    return dp[pos][taken]=r1;
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int T=1; T<=test; T++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&ara[i]);
        memset(dp,-1,sizeof dp);
        printf("Case %d: %d\n",T,recur(0,0));
    }
}
