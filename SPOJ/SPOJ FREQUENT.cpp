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

typedef long long ll;
typedef unsigned long long ull;
#define fbo find_by_order
#define ook order_of_key
#define PI acos(-1.0)
#define eps 1e-10
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
#define trail_zero(x) __builtin_ctz(x)
#define total_1s(x) __builtin_popcount(x)
#define first_1(x) __builtin_ffs(x)
#define log2_(x) __builtin_clz(1) - __builtin_clz(x)
#define isLeap(x) ((x % 400 == 0) || (x % 100 ? x % 4 == 0 : false))
#define set(N, cur) N = (N | (1 << cur))
#define reset(N, cur) N = (N & (~(1 << cur)))
#define check(N, cur) ((N & (1 << cur)) == 0)
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
#define what_is(x) cerr << #x << " is " << x << endl;
#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
#define in_range(v, r, l) upper_bound(all(v), r) - lower_bound(all(v), l)
void err(istream_iterator<string> it) {
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
ll rdn(int y, int m, int d) {
    /* Rata Die day one is 0001-01-01 */
    if (m < 3)
        y--, m += 12;
    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}
/* Direction arrays */
/* int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1}; */                        // 4 Direction
/*int dx[] = {1,-1,0,0,1,1,-1,-1}, dy[] = {0,0,1,-1,1,-1,1,-1};     */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */            // Hexagonal Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */            // Hexagonal Direction
/* int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; */
struct node {
    pii l,r,m;
    node() {
        l=r=m= {-1,1};
    }
    node(int val) {
        l.ff=r.ff=m.ff=val;
        l.ss=r.ss=m.ss=1;
    }
};
const int N=1e5+9;
node tree__[4*N];
int ara[N];
map<int,int>mp;
void merge__(node &a,node &b,node &c) {
    a.l=b.l;
    a.r=c.r;
    if(b.l.ff==b.m.ff)
        a.l=b.m;
    if(c.r.ff==c.m.ff)
        a.r=c.m;
    a.m.ss=0;
    if(b.m.ff==c.m.ff)
        a.m= {b.m.ff,b.m.ss+c.m.ss};
    if(b.m.ff==c.l.ff) {
        if(b.m.ss+c.l.ss>a.m.ss) {
            a.m= {b.m.ff,b.m.ss+c.l.ss};
        }
    }
    if(b.r.ff==c.m.ff) {
        if(b.r.ss+c.m.ss>a.m.ss) {
            a.m= {b.r.ff,b.r.ss+c.m.ss};
        }
    }
    if(b.r.ff==c.l.ff) {
        if(b.r.ss+c.l.ss>a.m.ss) {
            a.m= {b.r.ff,b.r.ss+c.l.ss};
        }
    }
    if(b.m.ss>=c.m.ss && b.m.ss>a.m.ss)
        a.m=b.m;
    if(b.m.ss<c.m.ss && c.m.ss>a.m.ss)
        a.m=c.m;
}
void build__(int idx,int st,int en) {
    if(st==en) {
        tree__[idx]=node(ara[en]);
        return;
    }
    int mid=(st+en)/2;
    int lt=idx*2;
    int rg=idx*2+1;
    build__(lt,st,mid);
    build__(rg,mid+1,en);
    merge__(tree__[idx],tree__[lt],tree__[rg]);
}
int maxi;
void query__(int idx,int st,int en,int l,int r) {
    if(st>=l && en<=r)
        {
            mp[tree__[idx].m.ff]+=tree__[idx].m.ss;
            if(tree__[idx].m.ff!=tree__[idx].l.ff){
                mp[tree__[idx].l.ff]+=tree__[idx].l.ss;
            }
            if(tree__[idx].m.ff!=tree__[idx].r.ff){
                mp[tree__[idx].r.ff]+=tree__[idx].r.ss;
            }
            maxi=max4(maxi,mp[tree__[idx].l.ff],mp[tree__[idx].r.ff],mp[tree__[idx].m.ff]);
            return;
        }
    if(r< st || l>en)
        return;
    int mid=(st+en)/2;
    int lt=idx*2;
    int rg=idx*2+1;
    query__(lt,st,mid,l,r);
    query__(rg,mid+1,en,l,r);
    return;
}
int main() {
    int n,q;
    while(scanf("%d",&n)==1 && n){
        scanf("%d",&q);
        for(int i=1;i<=n;i++)scanf("%d",&ara[i]);
        build__(1,1,n);
        int a,b;
        while(q--){

            mp.clear();
            scanf("%d%d",&a,&b);
            maxi=-1e9;
            query__(1,1,n,a,b);
            printf("%d\n",maxi);
        }
    }
}
