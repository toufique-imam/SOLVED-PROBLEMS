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
#define fbo find_by_order  // k th index
#define ook order_of_key   // strictly smaller than k
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

ll rdn(int y, int m, int d) {
    /* Rata Die day one is 0001-01-01 */
    if (m < 3)
        y--, m += 12;
    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}
/* Direction arrays */
/*int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};                             */  // 4Direction
/*int dx[] = {1,-1,0,0,1,1,-1,-1}, dy[] = {0,0,1,-1,1,-1,1,-1};         */  // 8Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1};     */  // KnightDirection
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1};                */  // HexagonalDirection
/* int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; */
const int N = 100000 + 9;
const int M = 40005;
int ara[M];
int level[M], fin_time[M], intime[M << 1], _time, st_time[M];
vector<int> v[M];
int sparse_table[M][19];
int _sz;
int valcnt[M];
bool visited[M];
int cur_ans = 0;
const int mod = 1e9 + 7;
int bl[M << 1];
struct query {
    int id, l, r, lc;
    bool operator<(const query& rhs) {
        return (bl[l] == bl[rhs.l]) ? (r < rhs.r) : (bl[l] < bl[rhs.l]);
    }
} Qara[N];

void dfs(int x, int par) {
    st_time[x] = ++_time;
    intime[_time] = x;
    for (int i = 0; i < v[x].size(); i++) {
        int p = v[x][i];
        if (p == par)
            continue;
        sparse_table[p][0] = x;
        level[p] = level[x] + 1;
        dfs(p, x);
    }
    fin_time[x] = ++_time;
    intime[_time] = x;
}
void create_sparse(int n) {
    _time = 0;
    dfs(1, 1);
    for (int i = 1; (1 << i) <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (sparse_table[j][i - 1] != -1)
                sparse_table[j][i] = sparse_table[sparse_table[j][i - 1]][i - 1];
        }
    }
}

int find_lca(int u, int v) {
    if (level[u] > level[v])
        swap(u, v);
    int lv1 = 1;
    int nxt = lv1 + 1;
    while ((1 << nxt) <= level[v])  //highest depth for 2^i
    {
        lv1++;
        nxt = lv1 + 1;
    }

    for (int i = lv1; i > -1; i--) {
        if (level[v] - (1 << i) >= level[u]) {
            v = sparse_table[v][i];
        }
    }
    if (v == u)
        return v;
    for (int i = lv1; i > -1; i--) {
        if (sparse_table[v][i] != -1 && sparse_table[u][i] != sparse_table[v][i]) {
            v = sparse_table[v][i];
            u = sparse_table[u][i];
        }
    }
    return sparse_table[v][0];
}
void check(int x) {
    if (visited[x] && (--valcnt[ara[x]] == 0)) {
        cur_ans--;
    } else if (visited[x] == 0 && (valcnt[ara[x]]++ == 0)) {
        cur_ans++;
    }
    visited[x] ^= 1;
}
int ans[N];
int ara1[N];
int main() {
    int n, a, b, q;
    while (scanf("%d %d", &n, &q) == 2) {
        memset(visited, 0, sizeof visited);
        memset(valcnt, 0, sizeof valcnt);
        for (int i = 0; i <= n; i++)
            v[i].clear();
        memset(sparse_table, -1, sizeof sparse_table);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &ara[i]);
            ara1[i] = ara[i];
        }
        int val = 0;
        unordered_map<int, int> mp;
        for (int i = 1; i <= n; i++) {
            if (mp.find(ara1[i]) == mp.end()) {
                mp[ara1[i]] = ++val;
            }
            ara[i] = mp[ara1[i]];
        }
        for (int i = 1; i < n; i++) {
            scanf("%d %d", &a, &b);
            v[a].EB(b);
            v[b].EB(a);
        }

        int x = 0;
        create_sparse(n);
        _sz = sqrt(_time);
        for (int i = 1; i <= _time; i++) {
            bl[i] = (i - 1) / _sz + 1;
        }
        for (int i = 0; i < q; i++) {
            scanf("%d %d", &a, &b);
            Qara[i].lc = find_lca(a, b);
            if (level[a] > level[b])
                swap(a, b);
            if (Qara[i].lc == a) {
                Qara[i].l = st_time[a];
                Qara[i].r = st_time[b];
            } else {
                Qara[i].l = fin_time[a];
                Qara[i].r = st_time[b];
            }
            Qara[i].id = i;
        }
        sort(Qara, Qara + q);
        int cur_l = Qara[0].l, cur_r = Qara[0].l - 1;
        cur_ans = 0;
        for (int i = 0; i < q; i++) {
            while (cur_l < Qara[i].l) {
                check(intime[cur_l]);
                cur_l++;
            }
            while (cur_l > Qara[i].l) {
                cur_l--;
                check(intime[cur_l]);
            }
            while (cur_r < Qara[i].r) {
                cur_r++;
                check(intime[cur_r]);
            }
            while (cur_r > Qara[i].r) {
                check(intime[cur_r]);
                cur_r--;
            }
            a = intime[cur_l];
            b = intime[cur_r];
            if (Qara[i].lc != a && Qara[i].lc != b) {
                check(Qara[i].lc);
            }
            ans[Qara[i].id] = cur_ans;
            if (Qara[i].lc != a && Qara[i].lc != b) {
                check(Qara[i].lc);
            }
        }
        for (int i = 0; i < q; i++) {
            printf("%d\n", ans[i]);
        }
    }
}
