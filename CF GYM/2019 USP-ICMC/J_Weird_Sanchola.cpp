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
/*no of prime in range
1e9=50847534
1e8=5761455
1e7=664579
1e6=78498
1e5=9592*/
const int N=1e5;
int isprime[N/32+2];
int prime[9592+3];
int prmsz;
void seive()
{
    prmsz=0;
	prime[prmsz++]=2;
	for(int i=3;i*i<=N;i+=2)
	{
		if(!_check(isprime[i/32],i%32))
		for(int j=i*i;j<=N;j+=i+i)
		{
			isprime[j/32]=_set(isprime[j/32],j%32);
		}
	}
	for(int i=3;i<=N;i+=2)
	{
		if(!_check(isprime[i/32],i%32))
			prime[prmsz++]=i;
	}
	return;
}

ll ara[N+9];
int n;
ll calc(ll x){
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=abs(ara[i]-x);
    }
    return ans;
}
ll ternary_search(ll l,ll r) {
    ll mid;
    while (l<=r) {
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;
        ll f1 = calc(m1);      //evaluates the function at m1
        ll f2 = calc(m2);      //evaluates the function at m2
        if (f1 < f2)
            r=m2-1;
        else
            l=m1+1;
    }
    return l;
}

bool check_prime(ll x) {
    if(x<2)
        return 0;
    if(x==2)
        return 1;
    if(x%2==0)
        return 0;
    if(x<N) !_check(isprime[x/32],x%32);
    for(int i=0;i<prmsz && prime[i]*prime[i]<=x;i++){
        if(x%prime[i]==0)return 0;
    }
    return 1;
}
int main() {
    seive();
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&ara[i]);
    }
    ll x=ternary_search(2,1e9+7);
    ll ans=1e18,y;
    ll id=-1;
    for(ll i=max(2ll,x-1000);i<=x+1000;i++){
        if(check_prime(i)){
            y=calc(i);
            if(y<ans){
                ans=y;
            }
        }
    }
    printf("%lld\n",ans);
}