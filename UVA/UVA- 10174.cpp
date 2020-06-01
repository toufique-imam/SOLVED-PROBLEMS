#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using dijkstra = priority_queue<T, vector<T>, greater<T>>;

typedef long long ll;
typedef unsigned long long ull;
#define fbo find_by_order  // k th index
#define ook order_of_key   // strictly smaller than k
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
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
mt19937 R(chrono::system_clock().now().time_since_epoch().count());

/* Direction arrays */
/*int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};                             */  // 4Direction
/*int dx[] = {1,-1,0,0,1,1,-1,-1}, dy[] = {0,0,1,-1,1,-1,1,-1};         */  // 8Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1};     */  // KnightDirection
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1};                */  // HexagonalDirection
/* int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; */
pair<bool, pll> couple_number(ll x) {
    if(x==0)return MP(true,MP(1,1));
    if (x % 2 == 1) {
        return MP(true, MP((x + 1) / 2, x - (x + 1) / 2));
    } else {
        if ((x / 2) % 2) {
            return MP(false, MP(-1, -1));
        } else {
            return MP(true, MP((x / 2 + 2) / 2, x / 2 - (x / 2 + 2) / 2));
        }
    }
}
int main() {
    string s;
    while (getline(cin, s)) {
        ll x[2];
        int cnt = 0;
        stringstream ss(s);
        while (ss >> x[cnt]) {
            cnt++;
        }
        if (cnt == 1) {
            bool neg = 0;
            if(x[0]<0){
                x[0] = -x[0];
                neg = 1;
            }
            pair<bool, pll> ans = couple_number(x[0]);
            if (ans.ff == 0) {
                puts("Bachelor Number.");
            } else {
                if (neg) {
                    swap(ans.second.first, ans.second.second);
                }
                printf("%lld %lld\n", ans.ss.ff, ans.ss.ss);
            }
        } else {
            int ans = 0;
            for (ll i = x[0]; i <= x[1]; i++) {
                ans = (ans + (couple_number(i).ff==false));
            }
            printf("%d\n", ans);
        }
    }
}
