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
using namespace std;
/* int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction
int dp[12][12];
int ara[12];
int n,m;
/*
//RECURSION//
int number[12];
ll recur(int pos)
{
    if(pos==n)
        return 1;
    ll r=0;
    for(int i=0; i<m; i++)
    {
        if(pos!=0)
        {
            if(abs(number[pos-1]-ara[i])<3)
            {
                number[pos]=ara[i];
                r+=recur(pos+1);
            }
        }
        else
        {
            number[pos]=ara[i];
            r+=recur(pos+1);
        }
    }
    return r;
}
*/
int main()
{
    int test;
    scanf("%d",&test);
    for(int T=1; T<=test; T++)
    {
        scanf("%d %d",&m,&n);
        for(int i=1; i<=m; i++)
        {
            scanf("%d",&ara[i]);
            dp[1][i]=1;
        }
        int prev=2,now=1;
        for(int i=2; i<=n; i++)
        {
            swap(prev,now);
            for(int j=1; j<=m; j++)
            {
                dp[now][j]=0;
                for(int k=1; k<=m; k++)
                    if(abs(ara[j]-ara[k])<3)
                        dp[now][j]+=dp[prev][k];
            }
        }
        int ans=0;
        for(int i=1; i<=m; i++)
            ans+=dp[now][i];
        printf("Case %d: %d\n",T,ans);
    }
}
