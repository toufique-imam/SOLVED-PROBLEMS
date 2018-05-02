/*
ID: sabertooth9
LANG:C++11
TASK: pprime
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
int isprime[100000/32+2];
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
    for(int i=0;i<prmsz and prime[i]*prime[i]<=n;i++)if(n%prime[i]==0)return 0;
    return 1;
}
int palinsize;
int palin[1000];
int createPalindrome(int input, int b, bool isOdd)
{
    int n = input;
    int palin = input;
    if (isOdd)n /= b;
    while (n > 0)
    {
        palin = palin * b + (n % b);
        n /= b;
    }
    return palin;
}

void generatePaldindromes(int n)
{
    int number;
    for (int j = 0; j < 2; j++)
    {
        int i = 1;
        while ((number = createPalindrome(i, 10, j % 2)) < n)
        {
            if(is_prime(number))palin[palinsize++]=number;
            i++;
        }
    }
}
int main()
{
    seive(N);
    generatePaldindromes(100000000);
    sort(palin,palin+palinsize);
    freopen("pprime.out","w",stdout);
    freopen("pprime.in","r",stdin);
    int a,b;
    scanf("%d %d",&a,&b);
    int pos=lower_bound(palin,palin+palinsize,a)-palin;
    for(int i=pos;i<palinsize and palin[i]<=b;i++)printf("%d\n",palin[i]);
    return 0;
}
