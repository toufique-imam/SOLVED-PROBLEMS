#include<bits/stdc++.h>
using namespace std;
#define read        freopen("input.txt","r",stdin)
#define write       freopen("output.txt","w",stdout)
#define ll          long long int

int main()
{
    ll test,i,j;
    scanf("%lld",&test);
    for(j=1; j<=test; j++)
    {
        ll n;
        vector<ll>v;
        ll x,m=-1,res,d;
        scanf("%lld",&n);
        v.push_back(0);
        for(i=0; i<n; i++)
        {
            scanf("%lld",&x);
            v.push_back(x);
        }
        for(i=1; i<=n; i++)
        {
            d=v[i]-v[i-1];
            if(d>m)
                m=d;
        }
        res=m;
        for(i=1; i<=n; i++)
        {
            d=v[i]-v[i-1];
            if(d==m)
                m--;
            else if(d>m)
            {
                res++;
                break;
            }
        }
        printf("Case %lld: %lld\n",j,res);
    }
}
