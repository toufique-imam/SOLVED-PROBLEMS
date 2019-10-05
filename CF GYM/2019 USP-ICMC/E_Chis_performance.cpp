#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ff first
#define ss second
map< ll,vector<ll> >mp;
const int N=1e6+9;
vector< vector<ll> >v;
ll dp[N][5];
int n;
int main()
{
    ll V,p;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&V,&p);
        mp[V].emplace_back(p);
    }
    int cnt=0;
    vector<ll>tmp;
    for(map< ll,vector<ll> >::iterator itr=mp.begin();itr!=mp.end();itr++){
        tmp.clear();
        sort(itr->ss.begin(),itr->ss.end());
        tmp.emplace_back(itr->ss[0]);
        if(itr->ss.size()>1){
            tmp.emplace_back(itr->ss[1]);
        }
        if(itr->ss.size()>2){
            tmp.emplace_back(itr->ss.back());
            itr->ss.pop_back();
        }
        if(itr->ss.size()>2){
            tmp.emplace_back(itr->ss.back());
        }
        v.emplace_back(tmp);
    }
    ll ans=0;
    cnt=v.size()-2;
    for(int i=cnt;i>-1;i--){
        for(int j=0;j<v[i].size();j++){
            for(int k=0;k<v[i+1].size();k++){
                for(int l=0;l<v[i+1].size();l++){
                    if(v[i+1].size()!=1 && k==l)continue;
                    dp[i][j]=max(dp[i][j],abs(v[i][j]-v[i+1][k])+dp[i+1][l]);
                    ans=max(ans,dp[i][j]);
                }
            }
        }
    }
    printf("%lld\n",ans);
}