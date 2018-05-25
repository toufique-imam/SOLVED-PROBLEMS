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
#define fast            ios_base::sync_with_stdio(0);cin.tie(0);
#define lead_zero(x)    __builtin_clzll(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
using namespace std;

int ara[52];
int dp[52][52];
int recur(int lt,int rg,int len1,int len2)
{
    if(lt>rg)return 0;
    if(dp[lt][rg]!=-1)return dp[lt][rg];
    int r1=1e9;
    for(int i=lt; i<=rg; i++)r1=min(r1,len2-len1+1+recur(lt,i-1,len1,ara[i])+recur(i+1,rg,ara[i]+1,len2));
    return dp[lt][rg]=r1;
}
int main()
{
    int l;
    while(scanf("%d",&l)==1 and l)
    {
        int n;
        scanf("%d",&n);
        memset(dp,-1,sizeof dp);
        for(int i=0; i<n; i++)scanf("%d",ara+i);
        int x=recur(0,n-1,1,l);
        printf("The minimum cutting is %d.\n",x);
    }
}
