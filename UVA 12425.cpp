#include <bits/stdc++.h>
#define ll long long
#define M 4000002
using namespace std;
const int N=1e6;
int isprime[N/32+2];
int prime[78498+3];
int prmsz;
bool check(int n,int pos)
{
    return n&(1<<pos);
}
int set_(int n,int pos)
{
    return n=n|(1<<pos);
}
void seive()
{
    prime[prmsz++]=2;
    for(int i=3;i*i<=N;i+=2)if(!check(isprime[i/32],i%32))for(int j=i*i;j<=N;j+=i+i)isprime[j/32]=set_(isprime[j/32],j%32);
    for(int i=3;i<=N;i+=2)if(!check(isprime[i/32],i%32))prime[prmsz++]=i;
}
ll phi(ll n)
{
    ll ans=n,cnt=0,p;
    for(int i=0;i<prmsz and prime[i]*prime[i]<=n;i++)
    {
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)n/=prime[i];
            ans/=prime[i];
            ans*=(prime[i]-1);
        }
    }
    if(n!=1)
    {
        ans/=n;
        ans*=(n-1);
    }
    return ans;
}
vector<ll>v;
vector< pair<ll,ll> >cum;
ll bin_sch(ll x)
{
    ll a=40,lo=0,mid,hi=cum.size()-1;
    while(a--)
    {
        mid=(hi+lo)/2;
        if(cum[mid].second==x)
            return mid;
        else if(cum[mid].second<x)
            lo=mid+1;
        else
            hi=mid-1;
    }
    return mid;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    seive();
    int test;
    scanf("%d",&test);
    for(int T=1; T<=test; T++)
    {
        cum.clear();
        v.clear();
        ll n,q;
        scanf("%lld %lld",&n,&q);
        for(ll i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                v.push_back(i);
                if(n/i!=i)
                    v.push_back(n/i);
            }
        }
        sort(v.begin(),v.end());
        ll ans=0;
        for(int i=0;i<v.size();i++)
        {
            ans+=phi(n/v[i]);
            cum.push_back(make_pair(ans,v[i]));
        }
        ll x;
        printf("Case %d\n",T);
        while(q--)
        {
            scanf("%lld",&x);
            if(x<=0){
                puts("0");
                continue;
            }
            printf("%lld\n",cum[bin_sch(x)].first);
        }
    }
}
