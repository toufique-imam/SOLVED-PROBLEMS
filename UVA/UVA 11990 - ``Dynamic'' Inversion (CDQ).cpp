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
const int BN = 2 * 1e5 + 9;
typedef long long bittype;
struct BIT {
    int n;
    bittype B[BN];
    void init(int _n) {
        n = _n;
        for (int i = 0; i <= n; i++)
            B[i] = 0;
    }
    inline bittype lowbit(int x) {
        return x & (-x);
    }
    void update(int pos, bittype val) {
        for (int i = pos; i <= n; i += lowbit(i)) {
            B[i] += val;
        }
    }
    bittype query(int pos) {
        bittype sum = 0;
        for (int i = pos; i > 0; i -= lowbit(i)) {
            sum += B[i];
        }
        return sum;
    }
} bit;
const int N = 2 * 1e5 + 9;
const int M = N;
ll ans[M];
int ID[N], ara[N], rb[N];
struct qnode {
    int t, val, id, qid;
    bool operator<(const qnode& x) const {
        return t > x.t;
    }
} query[M], tmp[M];

void cdq(int l, int r, int op) {
    if (l + 1 == r)
        return;
    int m = (l + r) >> 1;
    cdq(l, m, op);
    cdq(m, r, op);
    // val_left may contribute to right if val_left<val_right and pos_left>pos_right
    // or val_left>val_right and pos_left<pos_right
    int tmpidx = 0, rbidx = 0, a = l, b = m, sum = 0;
    while (a < m && b < r) {
        if ((op && query[a].val < query[b].val) || (!op && query[a].val > query[b].val)) {
            bit.update(query[a].id, 1);
            sum++;
            rb[rbidx++] = query[a].id;
            tmp[tmpidx++] = query[a++];
        } else {
            if (op) {
                ans[query[b].qid] += sum - bit.query(query[b].id);
            } else {
                ans[query[b].qid] += bit.query(query[b].id);
            }
            tmp[tmpidx++] = query[b++];
        }
    }
    while (a < m) {
        tmp[tmpidx++] = query[a++];
    }
    while (b < r) {
        if (op) {
            ans[query[b].qid] += sum - bit.query(query[b].id);
        } else {
            ans[query[b].qid] += bit.query(query[b].id);
        }
        tmp[tmpidx++] = query[b++];
    }
    for (int i = l; i < r; i++) {
        query[i] = tmp[i - l];
    }
    for (int i = 0; i < rbidx; i++) {
        bit.update(rb[i], -1);
    }
}
int n, m;
ll invcnt;
void reset() {
    memset(ans, 0, sizeof ans);
}
void input() {
    invcnt = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ara[i]);
        ID[ara[i]] = i;
    }
    bit.init(n);
    for (int i = n; i >= 1; i--) {
        invcnt += bit.query(ara[i]);
        bit.update(ara[i], 1);
    }
    int x;
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        query[i].val = x;
        query[i].id = ID[x];
        query[i].qid = i + 1;
        query[i].t = i;
        ID[x] = -1;
    }
}
void solve() {
    bit.init(n);
    int queryid = m;
    for (int i = 1; i <= n; i++) {
        if (ID[i] != -1) {
            query[queryid].t = m;
            query[queryid].val = i;
            query[queryid].id = ID[i];
            query[queryid].qid = 0;
            queryid++;
        }
    }
    sort(query, query + queryid);
    cdq(0, queryid, 0);
    sort(query, query + queryid);
    cdq(0, queryid, 1);
    for (int i = 1; i <= m; i++) {
        printf("%lld\n", invcnt);
        invcnt -= ans[i];
    }
}
int main() {
    while (scanf("%d %d", &n, &m) == 2) {
        reset();
        input();
        solve();
    }
}
