#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define QUERY int test;scanf("%d", &test); for (int _T = 1; _T <= test; _T++)
const ll mod=1e9+7;
map<ll,ll>mp;
ll bigmod(ll base,ll power) {
    if(mp[power])
        return mp[power];
    ll res=1,x=base%mod;
    while(power>0) {
        if(power &1) {
            res*=x;
            if(res>mod)
                res%=mod;
        }
        x=(x*x)%mod;
        power=power>>1;
    }
    return mp[power]=res;
}
int main() {
    ll base,ans;
    int test;
    scanf("%d", &test);
    for (int _T = 1; _T <= test; _T++) {
        scanf("%lld",&base);
        int x=base%3;
        if(base==1){
            ans=1;
        }
        else if(x==0)
            ans=bigmod(3,base/3);
        else if(x==1) {
            ans=bigmod(3,(base-4)/3);
            ans*=4;
        } else {
            ans=bigmod(3,(base-2)/3);
            ans*=2;
        }
        if(ans>mod)ans%=mod;
        printf("%lld\n",ans);
    }
}


