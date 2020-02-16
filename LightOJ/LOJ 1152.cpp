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
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};                             // 4Direction
/*int dx[] = {1,-1,0,0,1,1,-1,-1}, dy[] = {0,0,1,-1,1,-1,1,-1};         */  // 8Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1};     */  // KnightDirection
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1};                */  // HexagonalDirection
/* int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; */

string ara[30];
int id[409][409];
#define max_node 200005
struct HOPCROFT_KARP {
    vector<int> G[max_node];
    int matching;
    int match[max_node];
    int dist[max_node];
    int n, m;
    void init(int n, int m) {
        this->n = n;
        this->m = m;
        for (int i = 0; i < n + m; i++) G[i].clear();
    }
    void add_edge(int x, int y) {
        G[x].EB(y + n);
        G[y + n].EB(x);
    }
    bool bfs() {
        int i, u, v, len;
        queue<int> Q;
        for (i = 1; i <= n; i++) {
            if (match[i] == 0) {
                dist[i] = 0;
                Q.push(i);
            } else
                dist[i] = INT_MAX;
        }
        dist[0] = INT_MAX;
        while (!Q.empty()) {
            u = Q.front();
            Q.pop();
            if (u != 0) {
                len = G[u].size();
                for (i = 0; i < len; i++) {
                    v = G[u][i];
                    if (dist[match[v]] == INT_MAX) {
                        dist[match[v]] = dist[u] + 1;
                        Q.push(match[v]);
                    }
                }
            }
        }
        return (dist[0] != INT_MAX);
    }
    bool dfs(int u) {
        int i, v, len;
        if (u != 0) {
            len = G[u].size();
            for (int i = 0; i < len; i++) {
                v = G[u][i];
                if (dist[match[v]] == dist[u] + 1) {
                    if (dfs(match[v])) {
                        match[v] = u;
                        match[u] = v;
                        return true;
                    }
                }
            }
            dist[u] = INT_MAX;
            return false;
        }
        return true;
    }
    int find_maximum_matching() {
        matching = 0;
        memset(match, 0, sizeof match);
        while (bfs()) {
            for (int i = 1; i <= n; i++) {
                if (match[i] == 0 && dfs(i)) {
                    matching++;
                }
            }
        }
        return matching;
    }
    void show_match() {
        for (int i = 1; i <= n; i++) {
            cerr << "(" << i << "," << match[i] - n << ")\n";
        }
    }
}hk;

int main() {
    read;
    QUERY {
        int n, m;
        string s;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            cin >> ara[i];
        }
        vector<pii> vq[2];
        int gold = 0, odd = 0, even = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ara[i][j] == '*') {
                    id[i][j] = ++gold;
                    if ((i + j) % 2 == 0) {
                        even++;
                        vq[1].EB(MP(i,j));
                    } else {
                        odd++;
                        vq[0].EB(MP(i,j));
                    }
                }
            }
        }
        hk.init(vq[0].size(),vq[1].size());
        for(int i=0;i<vq[0].size();i++){
            for(int j=0;j<vq[1].size();j++){
                int dif = abs(vq[0][i].ff - vq[1][j].ff) + abs(vq[0][i].ss - vq[1][j].ss);
                if(dif==1){
                    hk.add_edge(i+1,j+1);
                }
            }
        }
        int ans = hk.find_maximum_matching();
        printf("Case %d: %d\n", _T, gold - ans);
    }
}