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
ll coin[202];
ll dp[202][30][12],ans;
int n,m,d;

ll recur(int idx,int sum,int taken)
{
    if(idx>=n)
    {
        if(taken==m and sum==0)
            return 1;
        else
            return 0;
    }
    if(taken==m)
    {
        if(sum==0)
            return 1;
        return 0;
    }
    if(dp[idx][sum][taken]!=-1)
        return dp[idx][sum][taken];
    int x=sum+coin[idx];
    x%=d;
    if(x<0)
        x+=d;
    dp[idx][sum][taken]=recur(idx+1,x,taken+1)+recur(idx+1,sum,taken);
    return dp[idx][sum][taken];
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int T=1;T<=test;T++)
    {
        int q;
        scanf("%d %d",&n,&q);
        for(int i=0;i<n;i++)scanf("%lld",coin+i);
        printf("Case %d:\n",T);
        for(int i=0;i<q;i++)
        {
            memset(dp,-1,sizeof dp);
            scanf("%d %d",&d,&m);
            recur(0,0,0);
            printf("%lld\n",dp[0][0][0]);
        }
    }
}
