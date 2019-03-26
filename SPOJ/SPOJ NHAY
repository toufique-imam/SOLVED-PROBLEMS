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
/*
const int N=1e5+9;
int seg[4*N];
int ara[N];
void build(int node,int st,int en){
    if(st==en){
        seg[node]=ara[st];
        return;
    }
    int mid=(st+en)/2;
    int lt=node*2;
    int rg=node*2+1;
    build(lt,st,mid);
    build(rg,mid+1,en);
    seg[node]=__gcd(seg[lt],seg[rg]);
}
int query(int node,int st,int en,int l,int r){
    if(st>=l && en<=r)return seg[node];
    if(st>r || en<l)return 0;
    int mid=(st+en)/2;
    int lt=node*2;
    int rg=node*2+1;
    return __gcd(query(lt,st,mid,l,r),query(rg,mid+1,en,l,r));
}
map<ll,ll>mp;
int bs(int l,int n){
    int hi=n;
    int lo=l;
    int mid;
    int ans=l;
    int gg=ara[l];
    while(lo<=hi){
        mid=(lo+hi)/2;
        int xx=query(1,1,n,l,mid);
        if(xx%gg!=0)
            hi=mid-1;
        else{
            ans=mid;
            lo=mid+1;
        }
    }
    return ans;
}
void pre(int n){
    for(int i=1;i<=n;i++){
        int xx=bs(i,n);
        mp[ara[i]]+=(xx-i);
    }
}
*/
const int N=1e5+9;
string t,p;
int b[N];
void kmpPreprocess() {
    int m=p.size();
    int i=0,j=-1;
    b[0]=-1;
    while(i<m) {
        while(j>-1 && p[i]!=p[j])
            j=b[j];
        i++;
        j++;
        b[i]=j;
    }
}
int kmpSearch() {
    int c=0;
    int i=0,j=0;
    int m=p.size();
    int n=t.size();
    while(i<n) {
        while(j>-1 && t[i]!=p[j])
            j=b[j];
        i++;
        j++;
        if(j==m) {
            c++;
            printf("%d\n",i-j);
            j=b[j];
        }
    }
    return c;
}
int main() {
    int n;
    while(cin>>n>>p>>t) {
        kmpPreprocess();
        n=kmpSearch();
        if(!n)puts("");
    }
}