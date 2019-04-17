#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<unordered_map>
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
#define max_ull 18446744073709551615
#define max_ll 9223372036854775807
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
#define SEGTREE int mid=(st+en)/2,lt=node*2,rg=node*2+1;
const int N=1e5+9;
int ara[N+N];
pair<int,int> tree_[8*N];
ll cnttree[8*N];
void build(int node,int st,int en) {
    if(st==en) {
        if(ara[st]==0){
            tree_[node]=MP(-1,1e9);
            cnttree[node]=0;
        }
        else{
            tree_[node]=MP(ara[st],ara[en]);
            cnttree[node]=1;
        }return;
    }
    SEGTREE;
    build(lt,st,mid);
    build(rg,mid+1,en);
    tree_[node].ff=max(tree_[lt].ff,tree_[rg].ff);
    tree_[node].ss=min(tree_[lt].ss,tree_[rg].ss);
    cnttree[node]=cnttree[lt]+cnttree[rg];
}
//ber korbe l-r er modhe koeta value ase jara <=val
ll query_min(int node,int st,int en,int l,int r,int val) {
    if(st>r || en<l)return 0;
    if(st==en){
        if(tree_[node].ff==-1)return 0;
        return tree_[node].ff<=val;
    }
    if(st>=l && en<=r && tree_[node].ff<=val){
        return cnttree[node];
    }
    if(st>=l && en<=r && tree_[node].ss>val){
        return 0;
    }
    SEGTREE;
    ll t1=query_min(lt,st,mid,l,r,val);
    ll t2=query_min(rg,mid+1,en,l,r,val);
    return t1+t2;
}

//ber korbe l-r er modhe koeta value ase jara >=val
ll query_max(int node,int st,int en,int l,int r,int val) {
    if(st>r || en<l)return 0;
    if(st==en){
        if(tree_[node].ff==-1)return 0;
        return tree_[node].ff>=val;
    }
    if(st>=l && en<=r && tree_[node].ss>=val){
        return cnttree[node];
    }
    if(st>=l && en<=r && tree_[node].ff<val)return 0;
    SEGTREE;
    ll t1=query_max(lt,st,mid,l,r,val);
    ll t2=query_max(rg,mid+1,en,l,r,val);
    return t1+t2;
}
int main() {
    QUERY{
        memset(cnttree,0,sizeof cnttree);
        memset(tree_,0,sizeof tree_);
        memset(ara,0,sizeof ara);
        int n,m;
        scanf("%d %d",&n,&m);
        int a,b;
        for(int i=1; i<=n; i++) {
            scanf("%d %d",&a,&b);
            ara[a]=b;
        }
        build(1,1,n+m);
        ll ans=0;
        for(int i=1; i<=m; i++) {
            scanf("%d %d",&a,&b);
            ans+=query_min(1,1,n+m,a+1,n+m,b);
            ans+=query_max(1,1,n+m,1,a-1,b);
        }
        printf("Case %d: %lld\n",_T,ans);
    }
}
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <unordered_map>
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
#define ook order_of_key  // strictly smaller than k
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define max_ull 18446744073709551615
#define max_ll 9223372036854775807
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
#define QUERY           \
    int test;           \
    scanf("%d", &test); \
    for (int _T = 1; _T <= test; _T++)
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
#define LCM(a, b) (a / __gcd(a, b)) * b;
ll rdn(int y, int m, int d)
{
    /* Rata Die day one is 0001-01-01 */
    if (m < 3)
        y--, m += 12;
    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}
/* Direction arrays */
/* int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1}; */                        // 4 Direction
/*int dx[] = {1,-1,0,0,1,1,-1,-1}, dy[] = {0,0,1,-1,1,-1,1,-1};   */   // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */            // Hexagonal Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */            // Hexagonal Direction
/* int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; */
#define SEGTREE int mid = (st + en) / 2, lt = node * 2, rg = node * 2 + 1;
const int N = 1e5 + 9;
int ara[N + N];
pair<int, int> tree_[8 * N];
ll cnttree[8 * N];
void build(int node, int st, int en)
{
    if (st == en)
    {
        if (ara[st] == 0)
        {
            tree_[node] = MP(-1, 1e9);
            cnttree[node] = 0;
        }
        else
        {
            tree_[node] = MP(ara[st], ara[en]);
            cnttree[node] = 1;
        }
        return;
    }
    SEGTREE;
    build(lt, st, mid);
    build(rg, mid + 1, en);
    tree_[node].ff = max(tree_[lt].ff, tree_[rg].ff);
    tree_[node].ss = min(tree_[lt].ss, tree_[rg].ss);
    cnttree[node] = cnttree[lt] + cnttree[rg];
}
//ber korbe l-r er modhe koeta value ase jara <=val
ll query_min(int node, int st, int en, int l, int r, int val)
{
    if (st > r || en < l)
        return 0;
    if (st == en)
    {
        if (tree_[node].ff == -1)
            return 0;
        return tree_[node].ff <= val;
    }
    if (st >= l && en <= r && tree_[node].ff <= val)
    {
        return cnttree[node];
    }
    if (st >= l && en <= r && tree_[node].ss > val)
    {
        return 0;
    }
    SEGTREE;
    ll t1 = query_min(lt, st, mid, l, r, val);
    ll t2 = query_min(rg, mid + 1, en, l, r, val);
    return t1 + t2;
}

//ber korbe l-r er modhe koeta value ase jara >=val
ll query_max(int node, int st, int en, int l, int r, int val)
{
    if (st > r || en < l)
        return 0;
    if (st == en)
    {
        if (tree_[node].ff == -1)
            return 0;
        return tree_[node].ff >= val;
    }
    if (st >= l && en <= r && tree_[node].ss >= val)
    {
        return cnttree[node];
    }
    if (st >= l && en <= r && tree_[node].ff < val)
        return 0;
    SEGTREE;
    ll t1 = query_max(lt, st, mid, l, r, val);
    ll t2 = query_max(rg, mid + 1, en, l, r, val);
    return t1 + t2;
}
int main()
{
    QUERY
    {
        memset(cnttree, 0, sizeof cnttree);
        memset(tree_, 0, sizeof tree_);
        memset(ara, 0, sizeof ara);
        int n, m;
        scanf("%d %d", &n, &m);
        int a, b;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d %d", &a, &b);
            ara[a] = b;
        }
        build(1, 1, n + m);
        ll ans = 0;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d %d", &a, &b);
            ans += query_min(1, 1, n + m, a + 1, n + m, b);
            ans += query_max(1, 1, n + m, 1, a - 1, b);
        }
        printf("Case %d: %lld\n", _T, ans);
    }
}
