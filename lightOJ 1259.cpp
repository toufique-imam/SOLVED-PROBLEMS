#include<bits/stdc++.h>
using namespace std;
const long long N=1e7;
bool isprime[N+9];
vector<long long>prime;
void seive()
{
    for(int i=4;i<=N;i+=2)
        isprime[i]=1;
    for(int i=3;i*i<=N;i+=2)
        if(!isprime[i])
            for(int j=i*i;j<=N;j+=i)
                isprime[j]=1;
    prime.push_back(2);
    for(int i=3;i<=N;i+=2)
        if(!isprime[i])
            prime.push_back(i);
}

int main()
{
    memset(isprime,0,sizeof(isprime));
    seive();
    int test;
    scanf("%d",&test);
    for(int t=1;t<=test;t++)
    {
        int n,cnt=0;
        scanf("%d",&n);
        for(int i=0;i<prime.size() && prime[i]<=n/2;i++)
        {
            int x=prime[i];
            if(isprime[n-prime[i]]==0)
                cnt++;
        }
        printf("Case %d: %d\n",t,cnt);
    }
}


