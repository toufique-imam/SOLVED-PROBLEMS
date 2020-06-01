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

const int N = 3 * 1e5 + 9;
int parent[N], depth[N], heavy[N], head[N], pos[N];
int cur_pos;
vector<int> v[N];
int gene[N];

struct BIT {
    int n;
    ll b[N];
    void init(int _n) {
        n = _n;
        for (int i = 0; i <= n; i++) {
            b[i] = 0;
        }
    }
    inline int lowbit(int x) {
        return x & (-x);
    }
    ll query(int x) {
        if (x == 0)
            return 0;
        ll sum = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            sum += b[i];
        }
        return sum;
    }
    void update(int x, ll val) {
        for (int i = x; i <= n; i += lowbit(i)) {
            b[i] += val;
        }
    }
} bit;

int dfs(int x) {
    int size = 1;
    int max_c_size = 0;
    for (int i : v[x]) {
        if (i != parent[x]) {
            parent[i] = x;
            depth[i] = depth[x] + 1;
            int c_size = dfs(i);
            size += c_size;
            if (c_size > max_c_size) {
                max_c_size = c_size, heavy[x] = i;
            }
        }
    }
    return size;
}
int decompose(int x, int h) {
    head[x] = h;
    pos[x] = cur_pos++;
    if (heavy[x] != -1)
        decompose(heavy[x], h);
    for (int i : v[x]) {
        if (i != parent[x] && i != heavy[x]) {
            decompose(i, i);
        }
    }
}
void init() {
    memset(parent, 0, sizeof parent);
    memset(heavy, -1, sizeof heavy);
    cur_pos = 1;
    depth[1]=0;
    dfs(1);
    decompose(1, 1);
}

ll query(int a, int b) {
    ll res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]]) {
            swap(a, b);
        }
        res -= bit.query(pos[head[b]] - 1);
        res += bit.query(pos[b]);
    }
    if (depth[a] > depth[b])
        swap(a, b);
    res -= bit.query(pos[a] - 1);
    res += bit.query(pos[b]);
    return res;
}
int main() {
    QUERY {
        int n;
        scanf("%d", &n);
        int a, b;
        bit.init(n + 5);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &gene[i]);
        }
        for (int i = 1; i < n; i++) {
            scanf("%d %d", &a, &b);
            a++;
            b++;
            v[a].EB(b);
            v[b].EB(a);
        }
        init();
        for (int i = 1; i <= n; i++) {
            bit.update(pos[i], gene[i]);
        }
        int q;
        scanf("%d", &q);
        int c;
        printf("Case %d:\n", _T);
        while (q--) {
            scanf("%d %d %d", &a, &b, &c);
            b++;
            if (a == 0) {
                c++;
                ll ans = query(b, c);
                printf("%lld\n", ans);
            } else {
                bit.update(pos[b], -gene[b]);
                gene[b] = c;
                bit.update(pos[b], gene[b]);
            }
        }
        for(int i=1;i<=n;i++)v[i].clear();
    }
}