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
const int N1 = 50009, N2 = 1009;
int n, m;
vector<pair<int, pii>> vp;
int supersource = 0, supersink = 1001;
ll grid[N2][N2];
vector<int> edge[N2];
int valsofar[N2];
int cnt;
void addedge(int from, int to, ll value) {
    if (grid[from][to] == 0) {
        edge[from].EB(to);
        if (grid[to][from] == 0)
            edge[to].EB(from);
    }
    grid[from][to] += value;
}
void clear() {
    vp.clear();
    memset(valsofar, 0, sizeof valsofar);
    memset(grid, 0, sizeof grid);
    for (int i = 0; i < N2; i++) {
        edge[i].clear();
    }
}
void debug(int N = N2) {
    for (int i = 0; i < N; i++) {
        if (edge[i].empty()) continue;
        cerr << i << " : ";
        for (int j : edge[i]) {
            cerr << "(" << j << "," << grid[i][j] << ")";
        }
        cerr << ";\n";
    }
}
int par[N2];
ll mini[N2];
ll bfs() {
    queue<int> q;
    q.push(supersource);
    memset(par, -1, sizeof par);
    memset(mini, inf, sizeof mini);
    par[supersource] = supersource;
    int p;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        if (t == supersink) break;
        for (int i = 0; i < (int)edge[t].size(); i++) {
            p = edge[t][i];
            if (grid[t][p] > 0 && par[p] == -1) {
                q.push(p);
                mini[p] = min(grid[t][p], mini[t]);
                par[p] = t;
            }
        }
    }
    if (par[supersink] == -1) return 0;
    return mini[supersink];
}
void update_path(int now, ll val) {
    if (par[now] == -1 || par[now] == now) return;
    grid[par[now]][now] -= val;
    grid[now][par[now]] += val;
    update_path(par[now], val);
}
ll maxflow() {
    ll ans = 0;
    ll mf = bfs();
    while (mf > 0) {
        ans += mf;
        update_path(supersink, mf);
        mf = bfs();
    }
    return ans;
}
int main() {
    int cas = 1;
    while (scanf("%d", &n) == 1) {
        if (n == 0) break;
        scanf("%d", &m);
        clear();
        vector<int> segments;
        int vx, a, b;
        cnt = n + 1;
        ll sum = 0;
        segments.EB(-1);
        for (int i = 1; i <= n; i++) {
            scanf("%d %d %d", &vx, &a, &b);
            sum += vx;
            segments.EB(a);
            segments.EB(b);
            vp.EB(MP(vx, MP(a, b)));
        }
        //supersource -> monkey with need(v) ->edges(m) -> supersink
        sort(all(segments));
        reunique(segments);
        int len = segments.size();
        for (int i = 1; i <= n; i++) {
            addedge(supersource, len + i, vp[i - 1].first);
            int lx = lower_bound(all(segments), vp[i - 1].second.first) - segments.begin();
            int rx = lower_bound(all(segments), vp[i - 1].second.second) - segments.begin();
            for (int j = lx; j < rx; j++) {
                addedge(len + i, j, segments[j + 1] - segments[j]);
            }
        }
        for (int i = 1; i + 1 < len; i++) {
            addedge(i, supersink, (segments[i + 1] - segments[i]) * m);
        }
        for (int i = 0; i < len; i++) {
            valsofar[i] = segments[i];
        }
        //  debug();
        ll ans = maxflow();
        printf("Case %d: ", cas++);
        if (ans == sum) {
            printf("Yes\n");
            ll tmp = 0;
            for (int i = len + 1; i <= len + n; i++) {
                vector<pii> sv;
                for (int j : edge[i]) {
                    if (grid[j][i] > 0) {
                        if (segments[j] + grid[j][i] < segments[j + 1]) {
                            if (grid[j][i] + valsofar[j] <= segments[j + 1]) {
                                sv.EB(MP(valsofar[j], valsofar[j] + grid[j][i]));
                                valsofar[j] += grid[j][i];
                                if (valsofar[j] == segments[j + 1]) valsofar[j] = segments[j];
                            } else {
                                int x = grid[j][i] - (segments[j + 1] - valsofar[j]);
                                sv.EB(MP(valsofar[j], segments[j + 1]));
                                valsofar[j] = segments[j] + x;
                                sv.EB(MP(segments[j], valsofar[j]));
                            }
                        } else {
                            sv.EB(MP(segments[j], segments[j + 1]));
                        }
                    }
                }
                sort(all(sv));
                for (int j = 0; j + 1 < sv.size();) {
                    if (sv[j].second == sv[j + 1].first) {
                        sv[j].second = sv[j + 1].second;
                        sv.erase(sv.begin() + j + 1);
                    } else
                        ++j;
                }
                assert(!sv.empty());
                printf("%d", (int)sv.size());
                for (vector<pii>::iterator itr = sv.begin(); itr != sv.end(); itr++) {
                    printf(" (%d,%d)", itr->first, itr->second);
                }
                printf("\n");
            }
        } else {
            printf("No\n");
        }
    }
}
