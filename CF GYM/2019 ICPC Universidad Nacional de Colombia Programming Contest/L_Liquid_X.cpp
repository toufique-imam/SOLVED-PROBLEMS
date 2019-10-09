#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using dijkstra = priority_queue<T, vector<T>, greater<T>>;

typedef long long ll;
#define fbo find_by_order // k th index
#define ook order_of_key // strictly smaller than k
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ff first
#define ss second
#define FAST ios_base::sync_with_stdio(0), cin.tie(0)
#define all(v) v.begin(), v.end()
#define reunique(v) v.resize(std::unique(all(v)) - v.begin())
#define MERGE(v1, v2, v) merge(all(v1), all(v2), back_inserter(v))
#define SEGMENT_TREE int mid=(st+en)/2,lt=node*2,rg=lt+1
#define MP make_pair
#define EB emplace_back
#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)
#define in_range(v, r, l) upper_bound(all(v), r) - lower_bound(all(v), l)
#define LCM(a, b) (a / __gcd(a, b)) * b;
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
const int N=1e6;
bool pre[N+2];
int par[N+2];
int ara[120];
int cnt[120];
vector<int>v;
int n;
void init(){
    pre[0]=1;
    par[0]=-1;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=n;j++){
            if(ara[j]<=i){
                if(pre[i-ara[j]]){
                    par[i]=j;
                    pre[i]=true;
                }
            }
        }
        if(pre[i]==true)v.EB(i);
    }
}
int query(int x){
    cout<<1<<endl;
    memset(cnt,0,sizeof cnt);
    for(int i=x;i!=0;){
        cnt[par[i]]++;
        i=i-ara[par[i]];
    }
    for(int i=1;i<=n;i++){
        cout<<cnt[i]<<" ";
    }
    cout<<endl;
    string tmp;
    cin>>tmp;
    if(tmp[0]=='r')return 1;
    if(tmp[0]=='y')return 0;
    if(tmp[0]=='g')return -1;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ara[i];
    }
    init();
    int cnt=0;
    int lo=0,hi=v.size()-1;
    int mid,ans=-1;
    while (cnt<30 && lo<=hi)
    {
        cnt++;
        mid=(lo+hi)/2;
        int mov=query(v[mid]);
        if(mov==-1){
            lo=mid+1;
        }
        else if(mov==1){
            ans=mid;
            hi=mid-1;
        }
        else{
            cout<<2<<endl<<v[mid]<<endl;
            return 0;
        }
    }
    if(ans==-1){
        cout<<2<<endl<<-1<<endl;
        return 0;
    }
    if(v[ans]==2){
        cout<<2<<endl<<1<<endl;
        return 0;
    }
    if(ans==0){
        cout<<2<<endl<<-1<<endl;
        return 0;
    }
    if(v[ans]-v[ans-1]==2){
        cout<<2<<endl<<v[ans]-1<<endl;
        return 0;
    }
    cout<<2<<endl<<-1<<endl;
    return 0;
}
