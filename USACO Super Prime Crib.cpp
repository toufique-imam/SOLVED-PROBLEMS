/*
ID: sabertooth9
LANG:C++11
TASK: sprime
*/
#include <bits/stdc++.h>
using namespace std;
bool checkBit(int n,int pos)
{
    return n&(1<<pos);
}
int setBit(int n,int pos)
{
    return n=n|(1<<pos);
}
const int N=100000;
int prime[9592+3];
int isprime[N/32+2];
int prmsz;
void seive(int n)
{
    int i,j;
    for(i=3; i*i<=n; i+=2)if(!checkBit(isprime[i/32],i%32))for(j=i*i; j<=n; j+=i+i)isprime[j/32]=setBit(isprime[j/32],j%32);
    prime[prmsz++]=2;
    for(i=3; i<=n; i+=2)if(!checkBit(isprime[i/32],i%32))prime[prmsz++]=i;
}
bool is_prime(int n)
{
    for(int i=0;i<prmsz and prime[i]*prime[i]<=n;i++)
    {
        if(n%prime[i]==0)
            return 0;
    }
    return 1;
}
int n;
int head[]={2,3,5,7};
int hand[]={1,2,3,5,7,9};
void dfs(int num,int len)
{
    if(len>=n)
    {
        printf("%d\n",num);
        return;
    }
    for(int i=0;i<6;i++)
    {
        int now=num*10+hand[i];
        if(now%2==0 and now!=2)
            continue;
        if(now<=N and !checkBit(isprime[now/32],now%32))
            dfs(now,len+1);
        else if (is_prime(now))
            dfs(now,len+1);
    }
}
int main()
{
    seive(N);
    freopen("sprime.in","r",stdin);
    freopen("sprime.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<4;i++)
        dfs(head[i],1);
}
