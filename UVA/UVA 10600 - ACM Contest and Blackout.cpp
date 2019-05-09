#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_set_rev = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using dijkstra = priority_queue<T, vector<T>, greater<T>>;

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define fbo find_by_order //k th index
#define ook order_of_key // strictly smaller than k
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define max5(a, b, c, d, e) max(max3(a, b, c), max(d, e))
#define min5(a, b, c, d, e) min(min3(a, b, c), min(d, e))
#define lead_zero(x) __builtin_clzll(x)
#define trail_zero(x) __builtin_ctzll(x)
#define total_1s(x) __builtin_popcountll(x)
#define first_1(x) __builtin_ffsll(x)
#define log2_(x) __builtin_clz(1) - __builtin_clz(x)
#define isLeap(x) ((x % 400 == 0) || (x % 100 ? x % 4 == 0 : false))
#define QUERY int test;scanf("%d", &test);for (int _T = 1; _T <= test; _T++)
#define FAST ios_base::sync_with_stdio(0), cin.tie(0)
#define all(v) v.begin(), v.end()
#define reunique(v) v.resize(std::unique(all(v)) - v.begin())
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
#define MERGE(v1, v2, v) merge(all(v1), all(v2), back_inserter(v))
#define MP make_pair
#define EB emplace_back
#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)
#define in_range(v, r, l) upper_bound(all(v), r) - lower_bound(all(v), l)
#define LCM(a,b) (a/__gcd(a,b))*b;
#define SEGTREE int mid=(st+en)/2,lt=node*2,rg=node*2+1
ll rdn(int y, int m, int d) {
    /* Rata Die day one is 0001-01-01 */
    if (m < 3)
        y--, m += 12;
    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}
/* Direction arrays */
/* int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1}; */                         // 4 Direction
/*int dx[] = {1,-1,0,0,1,1,-1,-1}, dy[] = {0,0,1,-1,1,-1,1,-1};   */    // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */            // Hexagonal Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */            // Hexagonal Direction
/* int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; */

int par[109];
int sz[109];
struct node {
    int cost;
    int t1,t2;
    node(int a,int b,int c) {
        cost=c;
        t1=a;
        t2=b;
    }
};
vector<node>edge;
int find_(int x) {
    while(x!=par[x]) {
        par[x]=par[par[x]];
        x=par[x];
    }
    return x;
}
bool UNION(int x,int y) {
    x=find_(x);
    y=find_(y);
    if(x!=y) {
        if(sz[x]<sz[y])
            swap(x,y);
        sz[x]+=sz[y];
        par[y]=x;
        return 1;
    }
    return 0;
}
int n,m;
void reset_() {
    for(int i=1; i<=n; i++) {
        par[i]=i;
        sz[i]=1;
    }
}
bool f=0;
int used[10009];
int mst(int taken=-1){
    reset_();
    f=1;
    int ans=0,a,b,c;
    for(int i=0;i<m;i++){
        if(taken==i)continue;
        a=edge[i].t1;
        b=edge[i].t2;
        c=edge[i].cost;
        if(UNION(a,b)){
            if(taken==-1)used[i]=1;
            ans+=c;
        }
    }
    int idx=-1;
    for(int i=1;i<=n;i++){
        a=find_(i);
        if(idx==-1){
            idx=a;
        }
        else if(idx==a)continue;
        else {
            f=0;
            return 1e9;
        }
    }
    return ans;
}
int main() {
    QUERY{
        memset(used,0,sizeof used);
        scanf("%d %d",&n,&m);
        edge.clear();
        int a,b,c;
        for(int i=0; i<m; i++) {
            scanf("%d %d %d",&a,&b,&c);
            node x=node(a,b,c);
            edge.emplace_back(x);
        }
        sort(all(edge),[](node& a,node& b) {
            return a.cost<b.cost;
        });
        int ans=mst();
        int ans1=1e9;
        for(int i=0;i<m;i++){
            if(used[i]){
                ans1=min(ans1,mst(i));
            }
        }
        if(ans1>=1e9)ans1=ans;
        printf("%d %d\n",ans,ans1);
    }
}
