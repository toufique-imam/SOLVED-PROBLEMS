#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    vector<ll>coins;
    for(int i=1;i*i*i<=10000;i++)
        coins.push_back(i*i*i);
    vector<ll>v(10009,0);
    v[0]=1;
    for(int i=0;i<(int)coins.size();i++)
    {
        for(int j=coins[i];j<=10000;j++)
            v[j]+=v[j-coins[i]];
    }
    ll n;
    while(scanf("%lld",&n)==1)
    {
        printf("%lld\n",v[n]);
    }
}
