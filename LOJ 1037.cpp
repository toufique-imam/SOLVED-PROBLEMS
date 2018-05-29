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
#define check(N,cur)    ((N&(1LL<<cur))==0)
#define all(v)          v.begin(),v.end()
using namespace std;
/* int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction
int n,limit;
const int N=(1<<16);
int dp[16][N+1];
int ara[16];
vector<string>v;
int bullet_cnt(int x,int mask)
{
    int best=1;
    for(int i=0;i<n;i++)
    {
        if(i!=x and (mask&(1<<i)))
            best=max(best,v[i][x]-'0');
    }
    int cnt=ara[x]/best;
    if(ara[x]%best)cnt++;
    return cnt;
}
int recur(int pos,int mask)
{
    if(mask==limit)
        return 0;
    if(dp[pos][mask]!=-1)return dp[pos][mask];
    int ans=1e9;
    for(int i=0;i<n;i++)
    {
        if(!(mask &(1<<i)))
        {
            ans=min(ans,bullet_cnt(i,mask)+recur(i,mask|(1<<i)));
        }
    }
    return dp[pos][mask]=ans;
}
int main()
{
    fast;
    int test;
    cin>>test;
    for(int T=1; T<=test; T++)
    {
        memset(dp,-1,sizeof dp);
        v.clear();
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>ara[i];
        string s;
        limit=(1<<(n))-1;
        for(int i=0; i<n; i++)
        {
            cin>>s;
            v.pb(s);
        }
        int ans=recur(0,0);
        printf("Case %d: %d\n",T,ans);
    }
}
