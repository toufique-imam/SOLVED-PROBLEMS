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
const int N = 509, INF = 1e9;
int lft[N + 2], rgt[N + 2], dist[N + 2];
vector<int> adj[N + 2];
int a, b;
void clear() {
    for (int i = 1; i <= a; i++) {
        lft[i] = 0, adj[i].clear();
    }
    for (int i = 1; i <= b; i++) {
        rgt[i] = 0;
    }
}
bool bfs() {
    queue<int> q;
    for (int i = 1; i <= a; i++) {
        if (!lft[i]) {
            q.push(i);
            dist[i] = 0;
        } else {
            dist[i] = INF;
        }
    }
    dist[0] = INF;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[rgt[v]] <= dist[u] + 1) continue;
            dist[rgt[v]] = dist[u] + 1;
            if (rgt[v]) {
                q.push(rgt[v]);
            }
        }
    }
    return dist[0] != INF;
}
bool dfs(int u) {
    if (!u) return true;
    for (int v : adj[u]) {
        if (dist[u] + 1 == dist[rgt[v]]) {
            if (dfs(rgt[v])) {
                lft[u] = v;
                rgt[v] = u;
                return true;
            }
        }
    }
    return false;
}
int hopkroft() {
    int match = 0;
    while (bfs()) {
        for (int i = 1; i <= a; i++) {
            if (dist[i]) continue;
            if (dfs(i)) match++;
        }
    }
    return match;
}
int aa[N], bb[N], cc[N], dd[N], tim[N];
int main() {
   // read;
    QUERY {
        int n;
        scanf("%d", &n);
        a = n, b = n;
        string s;
        int x, y, tx, ty, px, py;
        for (int i = 0; i < n; i++) {
            cin >> s;
            x = ((s[0] - '0') * 10) + (s[1] - '0');
            y = ((s[3] - '0') * 10) + (s[4] - '0');
            scanf("%d %d %d %d", &aa[i], &bb[i], &cc[i], &dd[i]);
            tim[i] = x * 60 + y;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (i == j) continue;
                if (tim[i] + abs(aa[i] - cc[i]) + abs(bb[i] - dd[i]) +
                        abs(aa[j] - cc[i]) + abs(bb[j] - dd[i]) <
                    tim[j]) {
                    //   hk.add_edge(i + 1, j + 1);
                    adj[i + 1].EB(j + 1);
                }
            }
        }
        int ans = hopkroft();
        printf("Case %d: %d\n", _T, n - ans);
        clear();
    }
}