#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll a,b,t;
    scanf("%lld %lld",&a,&b);
    vector<ll>v;
    for(ll i=1;i*i<=a;i++){
        if(a%i==0){
            if(i%b==0){
                v.emplace_back(i);
            }
            t=a/i;
            if(i!=t && t%b==0){
                v.emplace_back(t);
            }
        }
    }
    sort(v.begin(),v.end());
    for(ll i:v){
        printf("%lld ",i);
    }
    printf("\n");
}