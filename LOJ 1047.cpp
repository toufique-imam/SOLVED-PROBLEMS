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
#define gcd(A,B)    __gcd(A,B)
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
ll dp[30][3];
ll ara[30][3];
int n;
//0-red-1-Green-2-blue
ll recur(int idx,int color)
{
    if(idx>=n)
        return 0;
    if(dp[idx][color]!=-1)return dp[idx][color];
    return dp[idx][color]=ara[idx][color]+min(recur(idx+1,(color+1)%3),recur(idx+1,(color+2)%3));
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int T=1;T<=test;T++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<3;j++)
                sl(ara[i][j]);
        //memset(dp,-1,sizeof dp);
        ll ans=1e18;
        for(int i=0;i<3;i++)
        {
           memset(dp,-1,sizeof dp);
           ans=min(ans,recur(0,i));
        }
        printf("Case %d: %lld\n",T,ans);
    }
}
