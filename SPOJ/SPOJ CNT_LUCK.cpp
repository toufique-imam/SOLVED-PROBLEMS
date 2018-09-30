/*
ID: sabertooth
LANG: C++11
TASK:SPOJ CNT_LUCK
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

int myLog2(int x)
{
    return __builtin_clz(1) - __builtin_clz(x);
}
string x;
int len;
ll dp[100][100][2];
bool check(int x)
{
    if(x<10)
        return x==4|| x==7;
    while(x>0)
    {
        if((x%10==4 || x%10==7))
            x/=10;
        else return 0;
    }
    return 1;
}
ll recur(int pos,int cnt,bool isSml)
{
    if(pos>=len)
        return check(cnt);
    ll &ans=dp[pos][cnt][isSml];
    if(ans!=-1)
        return ans;
    ans=0;
    ans+=recur(pos+1,cnt,isSml|(0<(x[pos]-'0')));
    if(isSml)
    {
        ans+=recur(pos+1,cnt+1,isSml|(1<x[pos]-'0'));
    }
    else if(x[pos]-'0'>=1)
    {
        ans+=recur(pos+1,cnt+1,isSml|(1<x[pos]-'0'));
    }
    return ans;
}
void convert(unsigned long long n)
{
    x="";
    while(n>0)
    {
        x+=((n%2)+'0');
        n/=2;
    }
    reverse(all(x));
}
ll solve(unsigned long long a,unsigned long long b)
{
    memset(dp,-1,sizeof dp);
    convert(b);
    len=x.size();
    //cout<<x<<endl;
    ll ans=recur(0,0,0);
    if(a>0)
    {
        convert(a-1);
        len=x.size();
        //cout<<x<<endl;
        memset(dp,-1,sizeof dp);
        ans-=recur(0,0,0);
    }
    return ans;
}
int main()
{
    TEST
    {
        unsigned long long a,b;
        scanf("%llu %llu",&a,&b);
        if(a>b)swap(a,b);
        printf("%lld\n",solve(a,b));
    }
}
