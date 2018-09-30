/*
ID: sabertooth
LANG: C++11
TASK: SPOJ NUMTSN
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define eps             1e-9
#define inf             0x3f3f3f3f
#define INF             2e18
#define PI              acos(-1.0)
#define ff              first
#define ss              second
#define all(v)          v.begin(),v.end()
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(min(a,b),min(c,d))
#define max4(a,b,c,d)   max(max(a,b),max(c,d))
#define max5(a,b,c,d,e) max(max3(a,b,c),max(d,e))
#define min5(a,b,c,d,e) min(min3(a,b,c),min(d,e))
#define Iterator(a)     __typeof__(a.begin())
#define read            freopen("in.txt","r",stdin);
#define write           freopen("out.txt","w",stdout);
#define TEST            int test;scanf("%d",&test);for(int T=1;T<=test;T++)
#define PCAS            printf("Case %d:",T);
#define lead_zero(x)    __builtin_clzll(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
#define reunique(v)     v.resize(std::unique(all(v)) - v.begin())
#define MP              make_pair
#define PB              push_back
#define EB              emplace_back
#define segtree         int mid=(st+en)/2,lt=node*2,rg=node*2+1
#define MERGE(v1,v2,v)  merge(all(v1),all(v2),back_inserter(v))
//n! ~ sqrt(2*pi*n)*n^n*e^-n

int myLog2(int x)
{
    return __builtin_clz(1) - __builtin_clz(x);
}
/*
* Main thing in this problem is that it has many test case and big number 10^15
* so calculating F(X) in range L-R every time will cost TLE as Time limit is strict (0.391s)
* In digit DP what we do is calculate the sum of value of F(x) in range (1-R) and subtract this value from the sum value of F(x) 1-(L-1) in range
* So in every test case it can so happen that we are calculating the sum of f(x) what we have done before like if we calculate sum of f(x) in range 1-9
  then if we need sum of f(x) in 1-6 we can get it from DP table without calculating it again
* So our DP table is [POS][CNT_3][CNT_4][CNT_5] and without clearing it every time we call Recursion we will check if the DP table contains the value
  whether we can take the value according to the Is_Small #This Is_Small is Crucial as its filter what we should take and not and also if we take this in DP table
  this will cause WA as Then the DP table will become dependent to range
*/
int bit[51];
const int mod=1000000007;
ll dp[51][51][51][51];
int len;
ll recur(int pos,int num3,int num6,int num9,bool isSml)
{
    if(pos==0)
    {
        return (num3==num6 && num6==num9 && num3>0)?1:0;
    }
    ll &ans=dp[pos][num3][num6][num9];
    if(isSml and ans>=0)return ans;
    ll cnt=0;
    int limit=(isSml==1?9:bit[pos]);
    for(int i=0; i<=limit; i++)
    {
        cnt+=recur(pos-1,num3+(i==3?1:0),num6+(i==6?1:0),num9+(i==9?1:0),isSml|(i<(bit[pos])));
        cnt%=mod;
    }
    if(isSml)ans=cnt;
    return cnt;
}
bool is_369(char *a)
{
    int len=strlen(a);
    int cnt3,cnt6,cnt9;
    cnt3=cnt6=cnt9=0;
    for(int i=0; i<len; i++)
    {
        if(a[i]=='3')
            cnt3++;
        if(a[i]=='6')
            cnt6++;
        if(a[i]=='9')
            cnt9++;
    }
    if(cnt3==cnt6 and cnt6==cnt9 and cnt3!=0)
    {
        return 1;
    }
    return 0;
}
int main()
{
    char a[51],b[51];
    memset(dp,-1,sizeof dp);
    TEST
    {
        scanf("%s%s",a,b);
        len=strlen(b);
        for(int i=1;i<=len;i++)
            bit[i]=b[len-i]-'0';
        ll ans=recur(len,0,0,0,0);

        len=strlen(a);
        for(int i=1;i<=len;i++)
            bit[i]=a[len-i]-'0';
        ans-=recur(len,0,0,0,0);

        ans+=is_369(a);
        ans=(ans+mod)%mod;
        printf("%lld\n",ans);
    }
}
