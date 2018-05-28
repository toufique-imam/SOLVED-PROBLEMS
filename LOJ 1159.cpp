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
string a,b,c,fin1,fin2;
int dp[60][60][60];
int l1,l2,l3,l4;
int recur(int pos1,int pos2,int pos3)
{
    if(pos1>=l1 or pos2>=l2 or pos3>=l3)
        return 0;
    if(dp[pos1][pos2][pos3]!=-1)return dp[pos1][pos2][pos3];
    int r6=0,r=0,r1=0,r2=0,r3=0,r4=0,r5=0;
    if(a[pos1]==b[pos2] and b[pos2]==c[pos3])
        r=1+recur(pos1+1,pos2+1,pos3+1);
    else
    {
        r1=recur(pos1+1,pos2,pos3);
        r3=recur(pos1+1,pos2+1,pos3);
        r5=recur(pos1+1,pos2,pos3+1);
        r2=recur(pos1,pos2+1,pos3);
        r4=recur(pos1,pos2+1,pos3+1);
        r6=recur(pos1,pos2,pos3+1);
        r=max(r1,r);
        r=max(r2,r);
        r=max(r3,r);
        r=max(r4,r);
        r=max(r5,r);
        r=max(r6,r);
    }
    return dp[pos1][pos2][pos3]=r;
}
int main()
{
    fast;
    int test;
    cin>>test;
    for(int T=1; T<=test; T++)
    {
        cin>>a>>b>>c;
        l1=a.size(),l2=b.size(),l3=c.size();
        memset(dp,-1,sizeof dp);
        printf("Case %d: %d\n",T,recur(0,0,0));
    }
}
