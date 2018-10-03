/*
ID: sabertooth
LANG: C++11
TASK:
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
#define TEST            int test;scanf("%lld",&test);for(int T=1;T<=test;T++)
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
#define int ll
//n! ~ sqrt(2*pi*n)*n^n*e^-n

int myLog2(int x)
{
    return __builtin_clz(1) - __builtin_clz(x);
}
bool is_vowel(char x)
{
    x=tolower(x);
    return (x=='a' || x=='e' || x=='i' || x=='o' || x=='u');
}
int ara[1009];
int n;
int check(int sum,int k)
{
    int cnt=1,s=0;
    for(int i=n-1; i>-1; i--)
    {
        if(k-cnt==(i+1))
            return k;
        if(s+ara[i]>sum)
        {
            cnt++;
            s=0;
        }
        s+=ara[i];
    }
    return cnt;
}
bool mark[1009];
void print_ans(int sum,int k)
{
    memset(mark,0,sizeof mark);
    int s=0,cnt=1;
    for(int i=n-1; i>-1; i--)
    {
        if(k-cnt==(i+1))
        {
            cnt++;
            mark[i]=1;
            continue;
        }
        if(s+ara[i]>sum)
        {
            mark[i]=1;
            cnt++;
            s=0;
        }
        s+=ara[i];
    }
    for(int i=0;i<n;i++)
    {
        printf("%lld",ara[i]);
        if(i!=n-1)printf(" ");
        if(mark[i])
            printf("/ ");
    }
    printf("\n");
}
int32_t main()
{
    TEST
    {
        int k,lo=0,hi=0;
        scanf("%lld %lld",&n,&k);
        for(int i=0; i<n; i++)
        {
            scanf("%lld",&ara[i]);
            lo=max(ara[i],lo);
            hi+=ara[i];
        }
        int mid,ans=-1;
        while(lo<=hi)
        {
            mid=(lo+hi)/2;
            int t=(check(mid,k));
            if(t==k)
            {
                ans=mid;
                hi=mid-1;
            }
            else if(t<k)
            {
                hi=mid-1;
            }
            else
            {
                lo=mid+1;
            }
        }
        print_ans(ans,k);

    }
}
