#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool _check(int n,int pos)
{
    return (n & (1<<pos));
}
int _set(int n,int pos)
{
    return n=n|(1<<pos);
}
//1e9=50847534
//1e8=5761455
//1e7=664579
//1e6=78498
//1e5=9592
const int N=1e5;
int isprime[N/32+2];
int prime[9592+3];
int prmsz;
//int nod[100000+10];
pair<int,ll>ans[100000+10];
void seive()
{
    prmsz=0;
    prime[prmsz++]=2;
    for(int i=3; i*i<=N; i+=2)
    {
        if(!_check(isprime[i/32],i%32))
            for(int j=i*i; j<=N; j+=i+i)
            {
                isprime[j/32]=_set(isprime[j/32],j%32);
            }
    }
    for(int i=3; i<=N; i+=2)
    {
        if(!_check(isprime[i/32],i%32))
            prime[prmsz++]=i;
    }
    return;
}

ll factor_num(ll n)
{
    int cnt;
    ll res=1;
    for(int i=0; i<prmsz and prime[i]*prime[i]<=n ; i++)
    {
        if(n%prime[i]==0)
        {
            cnt=0;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                cnt++;
            }
            res*=(2*cnt+1);
        }
    }
    if(n!=1)
    {
        cnt=1;
        res*=(2*cnt+1);
    }
    return res;
}
bool comp(pair<int,ll>p1,pair<int,ll>p2)
{
    if(p1.first<p2.first)
        return 1;
    else if(p1.first==p2.first)
        return p1.second<p2.second;
    return 0;
}
void PRE()
{
    memset(ans,0,sizeof ans);
    ans[1]= {1,1};
    for(ll i=2; i<=100000; i++)
    {
        ans[i]= {factor_num(i),i*i};
    }
    sort(ans,ans+100001,comp);

}
ll bin_low(int key)
{
    ll hi=100000,lo=1,mid,res=-1;
    while(hi>=lo)
    {
        mid=(hi+lo)/2;
        if(ans[mid].first==key)
        {
            res=mid;
            hi=mid-1;
        }
        else if(ans[mid].first>key)
        {
            hi=mid-1;
        }
        else
            lo=mid+1;
    }
    return res;
}
ll bin_high(int key)
{
    ll hi=100000,lo=1,mid,res=-1;
    while(hi>=lo)
    {
        mid=(hi+lo)/2;
        if(ans[mid].first==key)
        {
            res=mid;
            lo=mid+1;
        }
        else if(ans[mid].first>key)
        {
            hi=mid-1;
        }
        else
            lo=mid+1;
    }
    return res;
}
ll bin_l(ll lo,ll hi,ll key)
{
    ll mid,res=-1;
    while(hi>=lo)
    {
        mid=(hi+lo)/2;
        if(ans[mid].second>=key)
        {
            hi=mid-1;
            res=mid;
        }
        else
            lo=mid+1;
    }
    return res;
}
ll bin_h(ll lo,ll hi,ll key)
{
    ll mid,res=-1;
    while(hi>=lo)
    {
        mid=(hi+lo)/2;
        if(ans[mid].second<=key)
        {
            lo=mid+1;
            res=mid;
        }
        else
            hi=mid-1;
    }
    return res;
}
int main()
{
    seive();
    PRE();
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int k;
        ll a,b;
        scanf("%d %lld %lld",&k,&a,&b);
        ll pos1=bin_low(k);
        ll pos2=bin_high(k);
        if(pos1==-1 || pos2==-1)
        {
            printf("0\n");
            continue;
        }
        ll posx=bin_l(pos1,pos2,a);
        ll posy=bin_h(pos1,pos2,b);
        if(posx==-1 or posy==-1)
        {
            printf("0\n");
            continue;
        }
        printf("%lld\n",posy-posx+1);
    }
}
