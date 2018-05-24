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
const int mod=100000007;
int n;
bool isvowel(char s)
{
    return s=='A' or s=='E' or s=='I' or s=='O' or s=='U';
}
ll dp[55][7][7];
string s;
ll recur(int idx,int vow,int con)
{
    if(vow>=3 or con>=5)return 1;
    if(idx>=n)return 0;
    if(dp[idx][vow][con]!=-1)return dp[idx][vow][con];
    if(isvowel(s[idx]))dp[idx][vow][con]=recur(idx+1,vow+1,0);
    else if(s[idx]!='?')dp[idx][vow][con]=recur(idx+1,0,con+1);
    else
    {
        ll r1=recur(idx+1,vow+1,0);
        ll r2=recur(idx+1,0,con+1);
        if(r1==r2) dp[idx][vow][con]=r1;
        else dp[idx][vow][con]=2;
    }
    return dp[idx][vow][con];
}
int main()
{
    int test;
    scanf("%d",&test);
    getchar();
    for(int T=1; T<=test; T++)
    {
        cin>>s;
        memset(dp,-1,sizeof dp);
        n=s.size();
        printf("Case %d: ",T);
        ll x=recur(0,0,0);
        if(x==0)printf("GOOD\n");
        else if(x==1)printf("BAD\n");
        else printf("MIXED\n");
    }
}
