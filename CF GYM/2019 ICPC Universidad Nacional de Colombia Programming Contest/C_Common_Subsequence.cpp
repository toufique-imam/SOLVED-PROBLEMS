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
int dp[3][N];
int main() {
    string s,t;
    cin>>s>>t;
    int l1=s.size();
    int l2=t.size();
    s="#"+s;
    t="$"+t;
    int now=0;
    int prev=1;
    for(int i=1; i<=l1; i++) {
        for(int j=max(i-1000,1); j<=min(i+1000,l2); j++) {
            if(s[i]==t[j]) {
                dp[now][j]=max(dp[now][j],dp[prev][j-1]+1);
            }
            dp[now][j]=max(dp[now][j],dp[prev][j]);
            dp[now][j]=max(dp[now][j],dp[now][j-1]);
        }
        swap(now,prev);
    }
    int need=l1-l1/100;
    if(dp[prev][l2]>=need) {
        puts("Long lost brothers D:");
    } else {
        puts("Not brothers :(");
    }
}
