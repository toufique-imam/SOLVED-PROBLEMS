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
ll dp[1009][1009];
pii ara[1009];
int main()
{
    int test;
    scanf("%d",&test);
    for(int T=1; T<=test; T++)
    {
        memset(dp,0,sizeof dp);
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d %d",&ara[i].ss,&ara[i].ff);
        sort(ara+1,ara+n+1);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=1000; j++)
            {
                if(ara[i].ff<=j)
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-ara[i].ff]+ara[i].ss);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        int q,w;
        scanf("%d",&q);
        ll res=0;
        for(int i=0; i<q; i++)
        {
            scanf("%d",&w);
            res+=dp[n][w];
        }
        printf("%lld\n",res);
    }
}
