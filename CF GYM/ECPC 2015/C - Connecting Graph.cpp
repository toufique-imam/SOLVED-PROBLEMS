#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
#define pul pair<ull, ull>
#define ff first
#define ss second
#define MERGE(v1, v2, v) merge(all(v1), all(v2), back_inserter(v))
#define MP make_pair
#define EB emplace_back
#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)
#define in_range(v, r, l) upper_bound(all(v), r) - lower_bound(all(v), l)
#define LCM(a, b) (a / __gcd(a, b)) * b;
#define SEGMENT_TREE int mid = (st + en) / 2, lt = node * 2, rg = lt + 1
template <typename T1, typename T2>
ostream& operator<<(ostream& fout, const pair<T1, T2>& ps) {
    fout << ps.ff << " " << ps.ss;
    return fout;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& fout, const map<T1, T2>& mp) {
    for (pair<T1, T2> i : mp)
        fout << i.first << " : " << i.second << "\n";
    return fout;
}
template <typename T>
ostream& operator<<(ostream& fout, const vector<T>& v) {
    for (T i : v)
        fout << i << " ";
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
const int N = 1e5 + 9;
vector<pii> v[N];
int level[N];
int sparse_table[N][20];
int cost_table[N][20];
void dfs(int x, int par,int d) {
    level[x]=d;
    sparse_table[x][0]=par;
    for (pii i : v[x]) {
        if (i.ff == par)
            continue;
        cost_table[i.ff][0] = i.ss;
        dfs(i.ff, x ,d+1);
    }
}
void create_sparse() {
    memset(sparse_table, -1, sizeof sparse_table);
    memset(cost_table, 0, sizeof cost_table);
    memset(level,-1,sizeof level);
    for(int i=0;i<N;i++){
        if(level[i]==-1){
            dfs(i,-1,0);
        }
    }

    for (int j = 1; (1 << j) <N; j++) {
        for (int i = 0; i < N; i++) {
            if (sparse_table[i][j - 1] != -1) {
                sparse_table[i][j] = sparse_table[sparse_table[i][j - 1]][j - 1];
                cost_table[i][j] = max(cost_table[i][j - 1], cost_table[sparse_table[i][j - 1]][j - 1]);
            }
        }
    }
}

int find_lca(int v1, int v2) {
    if (level[v1] < level[v2])
        swap(v1, v2);
    int lg = 1;
    int nxt = lg + 1;
    while ((1 << nxt) <= level[v1]) {
        lg++;
        nxt = lg + 1;
    }
    int ans = -1;
    for (int i = lg; i > -1; i--) {
        if (level[v1] - (1 << i) >= level[v2]) {
            ans = max(ans, cost_table[v1][i]);
            v1 = sparse_table[v1][i];
        }
    }
    if (v1 == v2)
        return ans;
    for (int i = lg; i > -1; i--) {
        if (sparse_table[v1][i] != sparse_table[v2][i]) {
            ans = max(ans, cost_table[v1][i]);
            ans = max(ans, cost_table[v2][i]);
            v1 = sparse_table[v1][i];
            v2 = sparse_table[v2][i];
        }
    }
    ans = max(ans, cost_table[v1][0]);
    ans = max(ans, cost_table[v2][0]);
    return ans;
}
int par[N];
int hight[N];
int find_(int x) {
    while (x != par[x]) {
        par[x] = par[par[x]];
        x = par[x];
    }
    return x;
}
bool UNION(int x, int y) {
    x = find_(x);
    y = find_(y);
    if (x != y) {
        if (hight[x] < hight[y])
            swap(x, y);
        par[y] = x;
        hight[x] += hight[y];
        return 1;
    }
    return 0;
}
bool same(int x,int y) {
    x=find_(x);
    y=find_(y);
    return x==y;
}
void dsu_reset(){
    for(int i=0;i<N;i++){
        par[i]=i;
        hight[i]=1;
    }
}
void clear_() {
    for (int i = 0; i < N; i++) {
        v[i].clear();
    }
}
pair<pii,int> vp[N];
int main() {
    QUERY {
        int idx=0;
        clear_();
        int n, m;
        scanf("%d %d", &n, &m);
        int x, y, z;
        dsu_reset();
        for (int i = 1; i <= m; i++) {
            scanf("%d %d %d", &x, &y, &z);
            if (x == 1) {
                if (!same(y,z)) {
                    UNION(y,z);
                    v[y].EB(MP(z, i));
                    v[z].EB(MP(y, i));
                }
            }
            vp[idx++]=(MP(MP(y, z),x));
        }
        create_sparse();
        dsu_reset();
        int ans;
        for (int i = 0; i < idx; i++) {
            x = vp[i].ff.ff;
            y = vp[i].ff.ss;
            z = vp[i].ss;
            if (z == 1)
                UNION(x, y);
            else {
                if (!same(x,y)) {
                    puts("-1");
                    continue;
                }
                ans = find_lca(x, y);
                printf("%d\n", ans);
            }
        }
    }
}
