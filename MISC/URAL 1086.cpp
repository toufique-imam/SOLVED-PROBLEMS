#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 10000
#define all(v) v.begin() v.end()
#define maxx 2000000
bool isprime[maxx+9];
vector<ll>prime;

void sieve()
{
    memset(isprime,0,sizeof(isprime));
    for(int i=3; i*i<=maxx; i+=2)
        if(!isprime[i])
            for(int j=i*i; j<=maxx; j+=i)
                isprime[j]=1;
    prime.push_back(2);
    for(int i=3; i<=maxx; i+=2)
        if(!isprime[i])
            prime.push_back(i);
}

int main()
{
    sieve();
    int test;
    long long x;
    scanf("%d",&test);
    for(int i=0;i<test;i++)
    {
        scanf("%lld",&x);
        printf("%lld\n",prime[x-1]);
    }
}
