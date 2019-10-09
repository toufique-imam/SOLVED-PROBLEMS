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
const int N=1e5+9;
int fib[N];
ll dp[N];
int main(){
    fib[1]=fib[2]=1;
    for(int i=3;i<N;i++){
        fib[i]=(fib[i-1]+fib[i-2])%2;
    }
    dp[3]=1;
    for(int i=3;i<N;i++){
        dp[i]+=dp[i-1];
        dp[i]+=(fib[i]+fib[i-1])%2;
    }
    int n,x;
    scanf("%d",&n);
    while (n--)
    {
        scanf("%d",&x);
        cout<<dp[x]<<"\n";
    }
}