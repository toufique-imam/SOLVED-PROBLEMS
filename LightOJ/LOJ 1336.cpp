#include <bits/stdc++.h>
#define ll long long
#define M 4000002
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    for(int T=1; T<=test; T++)
    {
        ll n;
        scanf("%lld",&n);
        ll odd=(ll)sqrt(n)+(ll)sqrt(n/2.0);
        printf("Case %d: %lld\n",T,n-odd);
    }
}
