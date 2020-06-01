/*ID: sabertooth
LANG: C++11
TASK: lamps
*/
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
int n, c;
int light[109];
int tempLight[109];
bool ok(int mask) {
    int odd = ((mask & 1) == 1), even = ((mask & 2) == 2), other = ((mask & 4) == 4);
    fill(tempLight, tempLight + n + 1, 1);
    if (odd) {
        for (int i = 1; i <= n; i += 2) {
            tempLight[i] = (tempLight[i] == -1 ? 1 : -1);
        }
    }
    if (even) {
        for (int i = 2; i <= n; i += 2) {
            tempLight[i] = (tempLight[i] == -1 ? 1 : -1);
        }
    }
    if (other) {
        for (int i = 0; (3 * i + 1) <= n; i++) {
            tempLight[3 * i + 1] = (tempLight[3 * i + 1] == -1 ? 1 : -1);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (light[i] == 0)
            continue;
        if (light[i] != tempLight[i])
            return 0;
    }
    return 1;
}
int ansx, mask;

int main() {
    freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w", stdout);
    scanf("%d %d", &n, &c);
    int x;
    while (scanf("%d", &x) == 1 && x != -1) {
        light[x] = 1;
    }
    while (scanf("%d", &x) == 1 && x != -1) {
        light[x] = -1;
    }
    bool f = 0;
    bool pr = 1;
    set<string> ans;
    memset(tempLight, -1, sizeof tempLight);
    if (c > 0) {
        for (int i = 1; i <= n; i++) {
            if (!light[i])
                continue;
            if (light[i] != tempLight[i]) {
                pr = 0;
                break;
            }
        }
        if (pr) {
            f = 1;
            string s;
            for (int i = 1; i <= n; i++) {
                s += '0';
            }
            ans.insert(s);
        }
    }
    for (int i = 0; i < 8; i++) {
        if (total_1s(i) <= c && ok(i)) {
            f = 1;
            string s;
            for (int j = 1; j <= n; j++) {
                s += (tempLight[j] == -1 ? '0' : '1');
                //printf("%c", (tempLight[j] == -1 ? '0' : '1'));
            }
            ans.insert(s);
            // printf("\n");
        }
    }
    if (!f) {
        printf("IMPOSSIBLE\n");
    } else {
        for (set<string>::iterator itr = ans.begin(); itr != ans.end(); itr++) {
            cout << *itr << "\n";
        }
    }
}
