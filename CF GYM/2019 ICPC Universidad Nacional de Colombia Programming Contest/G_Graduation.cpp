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
#define MP make_pair
#define EB emplace_back
#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)
#define in_range(v, r, l) upper_bound(all(v), r) - lower_bound(all(v), l)
#define LCM(a, b) (a / __gcd(a, b)) * b;
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
const int N=1e4+9;
int visited[N];
int edge[N];
vector<int>v[N];
int dfs(int x){
    if(visited[x])return visited[x];
    visited[x]=1;
    for(int i:v[x]){
        visited[x]+=dfs(i);
    }
    return visited[x];
}
int main(){
    int x,n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        if(x){
            v[x].EB(i);
            edge[i]++;
        }
    }
    priority_queue<pii>pq;
    for(int i=1;i<=n;i++){
        if(edge[i]==0){
            dfs(i);
            pq.push(MP(visited[i],i));
        }
    }
    int ans=0;
    while (pq.empty()==false)
    {
        ans++;
        queue<int>qq;
        int pp=0;
        while (pq.empty()==false && pp<k)
        {
            pp++;
            int t=pq.top().ss;
            pq.pop();
            for(int i:v[t]){
                qq.push(i);
            }
        }
        while (qq.empty()==false)
        {
            pq.push(MP(visited[qq.front()],qq.front()));
            qq.pop();
        }
    }
    cout<<ans<<"\n";
}
