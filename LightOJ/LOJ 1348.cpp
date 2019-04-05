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
/* int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1}; */                        // 4 Direction
/*int dx[] = {1,-1,0,0,1,1,-1,-1}, dy[] = {0,0,1,-1,1,-1,1,-1};       */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */            // Hexagonal Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */            // Hexagonal Direction
/* int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; */
#define SEGTREE int lt=node*2,rg=node*2+1,mid=(st+en)/2
const int N=30009;
int dfslow[N];
ll ara[N];
ll seg[9*N];
int dfsHigh[N];
int level[N];
int sparse_table[N][17];
int tim=0;
vector<int>v[N];
void dfs(int x,int par) {
    dfslow[x]=++tim;
    for(int i=0; i<v[x].size(); i++) {
        int nextt=v[x][i];
        if(nextt==par)
            continue;
        sparse_table[nextt][0]=x;
        level[nextt]=level[x]+1;
        dfs(nextt,x);
    }
    dfsHigh[x]=++tim;
}
void create_sparse(int n) {
    memset(sparse_table,-1,sizeof sparse_table);
    level[0]=0;
    dfs(0,-1);
    for(int j=1; (1<<j)<n; j++) {
        for(int i=0; i<n; i++) {
            if(sparse_table[i][j-1]!=-1)
                sparse_table[i][j]=sparse_table[sparse_table[i][j-1]][j-1];
        }
    }
}
int LCA(int v1,int v2) {
    if(level[v1]<level[v2])
        swap(v1,v2);
    int lg=1;
    int nxt=lg+1;
    while((1<<nxt)<=level[v1]) { //highest depth for 2^i
        lg++;
        nxt=lg+1;
    }
    for(int i=lg; i>-1; i--)
        if(level[v1]-(1<<i)>=level[v2])
            v1=sparse_table[v1][i];
    if(v1==v2)
        return v1;
    for(int i=lg; i>=0; i--)
        if(sparse_table[v1][i]!=-1 and sparse_table[v1][i]!=sparse_table[v2][i])
            v1=sparse_table[v1][i],v2=sparse_table[v2][i];
    return sparse_table[v1][0];
}
void update(int node,int st,int en,int l,int r,ll val) {
    if(st>r || en<l)
        return;
    if(st>=l && en<=r) {
        seg[node]=val;
        return;
    }
    SEGTREE;
    update(lt,st,mid,l,r,val);
    update(rg,mid+1,en,l,r,val);
    seg[node]=seg[lt]+seg[rg];
}
ll query(int node,int st,int en,int l,int r) {
    if(st>r || en<l)
        return 0;
    if(st>=l && en<=r)
        return seg[node];
    SEGTREE;
    return query(lt,st,mid,l,r)+query(rg,mid+1,en,l,r);
}
int main() {
    QUERY{
        memset(seg,0,sizeof seg);
        tim=0;
        for(int i=0;i<N;i++){
            v[i].clear();
        }
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%lld",&ara[i]);
        int a,b,c;
        for(int i=1; i<n; i++) {
            scanf("%d %d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        create_sparse(n);
        for(int i=0; i<n; i++) {
            update(1,1,tim,dfslow[i],dfslow[i],ara[i]);
            update(1,1,tim,dfsHigh[i],dfsHigh[i],-1ll*ara[i]);
        }
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",_T);
        while(q--) {
            scanf("%d %d %d",&a,&b,&c);
            if(a) {
                update(1,1,tim,dfslow[b],dfslow[b],-1ll*ara[b]);
                update(1,1,tim,dfsHigh[b],dfsHigh[b],ara[b]);
                ara[b]=c;
                update(1,1,tim,dfslow[b],dfslow[b],ara[b]);
                update(1,1,tim,dfsHigh[b],dfsHigh[b],-1ll*ara[b]);
            } else {
                ll x1,x2,x3,x4;
                x1=x2=x3=x4=0;
                int x=LCA(b,c);
                int y=sparse_table[x][0];
                x1=query(1,1,tim,dfslow[x],dfslow[b]);
                x2=query(1,1,tim,dfslow[x],dfslow[c]);
                x3=query(1,1,tim,dfslow[x],dfslow[x]);
                printf("%lld\n",x1+x2-x3);

            }
        }
    }
}
