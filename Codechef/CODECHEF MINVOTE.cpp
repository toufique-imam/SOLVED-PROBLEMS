/*
ID:sabertooth9
TASK:CChef MINVOTE
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;
#define ll              long long
#define pb              push_back
#define read(s)         freopen(#s,"r",stdin)
#define write(s)        freopen(#s,"w",stdout)
#define lead_zero(x)    __builtin_clzll(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
#define mod             1000000007
#define all(v)          v.begin(),v.end()
#define maxx            100000

ll ara[maxx+9];
ll cum[maxx+9];
ll cnt[maxx+9];

int bin_left(int h,int l,int pos)
{
    int mid,ans=-1;
    while(h>=l)
    {
        mid=(h+l)/2;
        if(cum[pos]-cum[mid]-ara[pos]<=ara[pos])
        {
            ans=mid;
            h=mid-1;
        }
        else
            l=mid+1;
    }
    return ans;
}
int bin_right(int h,int l,int pos)
{
    int mid,ans=-1;
    while(h>=l)
    {
        mid=(h+l)/2;
        if(cum[mid]-cum[pos]-ara[mid]<=ara[pos])
        {
            ans=mid;
            l=mid+1;
        }
        else
            h=mid-1;
    }
    return ans;
}
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        ll n;
        scanf("%lld",&n);
        for(ll i=0; i<n; i++)
        {
            scanf("%lld",&ara[i]);
            if(!i)
                cum[i]=ara[i];
            else
                cum[i]=cum[i-1]+ara[i];
        }
        memset(cnt,0,sizeof(cnt));
        for(int i=0; i<n; i++)
        {
            int x=bin_left(i-1,0,i);
            int y=bin_right(n-1,i+1,i);
            if(x!=-1){
                cnt[x]++;
                cnt[i-1]--;
            }
            if(y!=-1){
                cnt[i]++;
                cnt[y+1]--;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i)
                cnt[i]+=cnt[i-1];
        }
        for(int i=0; i<n; i++)
            printf("%lld ",cnt[i]);
        printf("\n");
    }
}

