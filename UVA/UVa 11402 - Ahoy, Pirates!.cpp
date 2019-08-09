#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_set_rev = tree<T, null_type, greater<T>, rb_tree_tag,
      tree_order_statistics_node_update>;
template <typename T>
using dijkstra = priority_queue<T, vector<T>, greater<T>>;

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define fbo find_by_order // k th index
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
template <typename T1, typename T2>
ostream& operator<<(ostream& fout, const pair<T1, T2>& ps) {
    fout << ps.ff << " " << ps.ss;
    return fout;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& fout, const map<T1, T2>& mp) {
    for (pair<T1, T2> i : mp)
        fout << i.first << " : " << i.second << endl;
    return fout;
}
template <typename T>
ostream& operator<<(ostream& fout, const vector<T>& v) {
    for (T i : v)
        fout << i << "\n";
    return fout;
}
template <typename T>
ostream& operator<<(ostream& fout, const set<T>& v) {
    for (T i : v)
        fout << i << " ";
    return fout;
}
template <typename T>
ostream& operator<<(ostream& fout, const ordered_set<T>& v) {
    for (T i : v)
        fout << i << " ";
    return fout;
}
ll rdn(int y, int m, int d) {
    /* Rata Die day one is 0001-01-01 */
    if (m < 3)
        y--, m += 12;
    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}
/* Direction arrays */
/*int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};                             */ // 4Direction
/*int dx[] = {1,-1,0,0,1,1,-1,-1}, dy[] = {0,0,1,-1,1,-1,1,-1};         */ // 8Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1};     */ // KnightDirection
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1};                */ // HexagonalDirection
/* int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; */

int test, n, t, m,qidx;
string s,ms;
const int N = 1024003;
int segtree[4 * N];
int lazy[4 * N];
int apply_flip(int x){
    if(x==1)return 2;
    if(x==2)return 1;
    if(x==3)return 0;
    return 3;
}
inline void free_lazy(int node,int st,int en) {
    if(lazy[node]==0)return;
    if(lazy[node]==1){
        segtree[node]=(en-st+1);
    }
    else if(lazy[node]==2){
        segtree[node]=0;
    }
    else if(lazy[node]==3){
        segtree[node]=(en-st+1)-segtree[node];
    }
    if(st!=en){
        int lt=node*2,rg=lt+1;
        if(lazy[node]==1 || lazy[node]==2){
            lazy[lt]=lazy[rg]=lazy[node];
        }
        else if(lazy[node]==3){
            lazy[lt]=apply_flip(lazy[lt]);
            lazy[rg]=apply_flip(lazy[rg]);
        }
    }
    lazy[node]=0;
}
void update(int node, int st, int en, int l, int r, int val) {
    free_lazy(node, st, en);
    if (r < st || l > en)
        return;
    if(st>=l && en<=r) {
        lazy[node]=val;
        free_lazy(node,st,en);
        return;
    }
    int mid = (st + en) / 2, lt = node * 2, rg = lt + 1;
    update(lt,st,mid,l,r,val);
    update(rg,mid+1,en,l,r,val);
    segtree[node]=segtree[lt]+segtree[rg];
}
int query(int node,int st,int en,int l,int r) {
    free_lazy(node,st,en);
    if(r<st || l>en)
        return 0;
    if(st>=l && en<=r)
        return segtree[node];
    int mid = (st + en) / 2, lt = node * 2, rg = lt + 1;
    int s1=query(lt,st,mid,l,r);
    int s2=query(rg,mid+1,en,l,r);
    return s1+s2;
}
void build(int node,int st,int en) {
    lazy[node]=0;
    if(st==en) {
        segtree[node]=ms[st-1]-'0';
        return;
    }
    int mid=(st+en)/2;
    int lt=node*2,rg=lt+1;
    build(lt,st,mid);
    build(rg,mid+1,en);
    segtree[node]=segtree[lt]+segtree[rg];
}
int main() {
    FAST;
    cin >> test;
    for (int _T = 1; _T <= test; _T++) {
        qidx=0;
        cin >> m;
        int cnt, cnt1, cnt2, sum = 0;
        int idx = 1;
        ms="";
        for (int i = 0; i < m; i++) {
            cin >> t >> s;
            for(int j=0; j<t; j++)
                ms+=s;
        }
        n=ms.size();
        build(1,1,n);
        char tp;
        int a,b;
        int q;
        cin>>q;
        cout<<"Case "<<_T<<":\n";
        int j=1;
        for(int i=1; i<=q; i++) {
            qidx++;
            cin>>tp>>a>>b;
            a++;
            b++;
            if(tp=='F')
                update(1,1,n,a,b,1);
            else if(tp=='E')
                update(1, 1, n, a, b,2);
            else if(tp=='I')
                update(1,1,n,a,b,3);
            else if(tp=='S')
                cout<<"Q"<<j++<<": "<<query(1,1,n,a,b)<<"\n";
        }
    }
}
