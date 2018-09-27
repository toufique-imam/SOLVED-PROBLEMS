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
const ll mod=100000007;
ll dp[10009][1009];
int ara[10009];
int n,k;
ll recur(int idx,int sum)
{
    if(idx>=n)
    {
        if(sum==0)return 1;
        return 0;
    }
    if(dp[idx][sum]!=-1)return dp[idx][sum];
    int r1=(((sum+ara[idx])%k+k)%k);
    int r2=(((sum-ara[idx])%k+k)%k);
    return dp[idx][sum]=recur(idx+1,r1) | recur(idx+1,r2);
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int T=1; T<=test; T++)
    {
        memset(dp,-1,sizeof dp);
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++)scanf("%d",ara+i);
        ll x=recur(1,((ara[0]%k)+k)%k);
        if(x) printf("Divisible\n");
        else printf("Not divisible\n");
    }
}
