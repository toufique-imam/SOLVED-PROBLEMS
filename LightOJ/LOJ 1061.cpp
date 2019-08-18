#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_set_rev = tree<T, null_type, greater<T>, rb_tree_tag,
    tree_order_statistics_node_update>;
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
#define QUERY           \
    int test;           \
    scanf("%d", &test); \
    for (int _T = 1; _T <= test; _T++)
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
#define LCM(a, b) (a / __gcd(a, b)) * b;
#define SEGMENT_TREE int mid = (st + en) / 2, lt = node * 2, rg = lt + 1
template <typename T1, typename T2>
ostream& operator<<(ostream& fout, const pair<T1, T2>& ps)
{
    fout << ps.ff << " " << ps.ss;
    return fout;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& fout, const map<T1, T2>& mp)
{
    for (pair<T1, T2> i : mp)
        fout << i.first << " : " << i.second << endl;
    return fout;
}
template <typename T>
ostream& operator<<(ostream& fout, const vector<T>& v)
{
    for (T i : v)
        fout << i << "\n";
    return fout;
}
template <typename T>
ostream& operator<<(ostream& fout, const set<T>& v)
{
    for (T i : v)
        fout << i << " ";
    return fout;
}
template <typename T>
ostream& operator<<(ostream& fout, const ordered_set<T>& v)
{
    for (T i : v)
        fout << i << " ";
    return fout;
}
ll rdn(int y, int m, int d)
{
    /* Rata Die day one is 0001-01-01 */
    if (m < 3)
        y--, m += 12;
    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}
/* Direction arrays */
/*int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};                             */ // 4Direction
int dx[] = { 1, -1, 0, 0, 1, 1, -1, -1 }, dy[] = { 0, 0, 1, -1, 1, -1, 1, -1 }; // 8Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1};     */ // KnightDirection
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1};                */ // HexagonalDirection
/* int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; */
pii grid[9];
int n = 8, sz = 92;
vector<int> v[109]; //pre cal valid queen formation
int nowidx, cas; // nowidx pointing to valid queen formation , cas for memorization of dp
int dp[(1 << 8) + 2]; //mask tsp
int visited[(1 << 8) + 2];

void precal()
{
    v[0] = { 0, 4, 7, 5, 2, 6, 1, 3 };
    v[1] = { 0, 5, 7, 2, 6, 3, 1, 4 };
    v[2] = { 0, 6, 3, 5, 7, 1, 4, 2 };
    v[3] = { 0, 6, 4, 7, 1, 3, 5, 2 };
    v[4] = { 1, 3, 5, 7, 2, 0, 6, 4 };
    v[5] = { 1, 4, 6, 0, 2, 7, 5, 3 };
    v[6] = { 1, 4, 6, 3, 0, 7, 5, 2 };
    v[7] = { 1, 5, 0, 6, 3, 7, 2, 4 };
    v[8] = { 1, 5, 7, 2, 0, 3, 6, 4 };
    v[9] = { 1, 6, 2, 5, 7, 4, 0, 3 };
    v[10] = { 1, 6, 4, 7, 0, 3, 5, 2 };
    v[11] = { 1, 7, 5, 0, 2, 4, 6, 3 };
    v[12] = { 2, 0, 6, 4, 7, 1, 3, 5 };
    v[13] = { 2, 4, 1, 7, 0, 6, 3, 5 };
    v[14] = { 2, 4, 1, 7, 5, 3, 6, 0 };
    v[15] = { 2, 4, 6, 0, 3, 1, 7, 5 };
    v[16] = { 2, 4, 7, 3, 0, 6, 1, 5 };
    v[17] = { 2, 5, 1, 4, 7, 0, 6, 3 };
    v[18] = { 2, 5, 1, 6, 0, 3, 7, 4 };
    v[19] = { 2, 5, 1, 6, 4, 0, 7, 3 };
    v[20] = { 2, 5, 3, 0, 7, 4, 6, 1 };
    v[21] = { 2, 5, 3, 1, 7, 4, 6, 0 };
    v[22] = { 2, 5, 7, 0, 3, 6, 4, 1 };
    v[23] = { 2, 5, 7, 0, 4, 6, 1, 3 };
    v[24] = { 2, 5, 7, 1, 3, 0, 6, 4 };
    v[25] = { 2, 6, 1, 7, 4, 0, 3, 5 };
    v[26] = { 2, 6, 1, 7, 5, 3, 0, 4 };
    v[27] = { 2, 7, 3, 6, 0, 5, 1, 4 };
    v[28] = { 3, 0, 4, 7, 1, 6, 2, 5 };
    v[29] = { 3, 0, 4, 7, 5, 2, 6, 1 };
    v[30] = { 3, 1, 4, 7, 5, 0, 2, 6 };
    v[31] = { 3, 1, 6, 2, 5, 7, 0, 4 };
    v[32] = { 3, 1, 6, 2, 5, 7, 4, 0 };
    v[33] = { 3, 1, 6, 4, 0, 7, 5, 2 };
    v[34] = { 3, 1, 7, 4, 6, 0, 2, 5 };
    v[35] = { 3, 1, 7, 5, 0, 2, 4, 6 };
    v[36] = { 3, 5, 0, 4, 1, 7, 2, 6 };
    v[37] = { 3, 5, 7, 1, 6, 0, 2, 4 };
    v[38] = { 3, 5, 7, 2, 0, 6, 4, 1 };
    v[39] = { 3, 6, 0, 7, 4, 1, 5, 2 };
    v[40] = { 3, 6, 2, 7, 1, 4, 0, 5 };
    v[41] = { 3, 6, 4, 1, 5, 0, 2, 7 };
    v[42] = { 3, 6, 4, 2, 0, 5, 7, 1 };
    v[43] = { 3, 7, 0, 2, 5, 1, 6, 4 };
    v[44] = { 3, 7, 0, 4, 6, 1, 5, 2 };
    v[45] = { 3, 7, 4, 2, 0, 6, 1, 5 };
    v[46] = { 4, 0, 3, 5, 7, 1, 6, 2 };
    v[47] = { 4, 0, 7, 3, 1, 6, 2, 5 };
    v[48] = { 4, 0, 7, 5, 2, 6, 1, 3 };
    v[49] = { 4, 1, 3, 5, 7, 2, 0, 6 };
    v[50] = { 4, 1, 3, 6, 2, 7, 5, 0 };
    v[51] = { 4, 1, 5, 0, 6, 3, 7, 2 };
    v[52] = { 4, 1, 7, 0, 3, 6, 2, 5 };
    v[53] = { 4, 2, 0, 5, 7, 1, 3, 6 };
    v[54] = { 4, 2, 0, 6, 1, 7, 5, 3 };
    v[55] = { 4, 2, 7, 3, 6, 0, 5, 1 };
    v[56] = { 4, 6, 0, 2, 7, 5, 3, 1 };
    v[57] = { 4, 6, 0, 3, 1, 7, 5, 2 };
    v[58] = { 4, 6, 1, 3, 7, 0, 2, 5 };
    v[59] = { 4, 6, 1, 5, 2, 0, 3, 7 };
    v[60] = { 4, 6, 1, 5, 2, 0, 7, 3 };
    v[61] = { 4, 6, 3, 0, 2, 7, 5, 1 };
    v[62] = { 4, 7, 3, 0, 2, 5, 1, 6 };
    v[63] = { 4, 7, 3, 0, 6, 1, 5, 2 };
    v[64] = { 5, 0, 4, 1, 7, 2, 6, 3 };
    v[65] = { 5, 1, 6, 0, 2, 4, 7, 3 };
    v[66] = { 5, 1, 6, 0, 3, 7, 4, 2 };
    v[67] = { 5, 2, 0, 6, 4, 7, 1, 3 };
    v[68] = { 5, 2, 0, 7, 3, 1, 6, 4 };
    v[69] = { 5, 2, 0, 7, 4, 1, 3, 6 };
    v[70] = { 5, 2, 4, 6, 0, 3, 1, 7 };
    v[71] = { 5, 2, 4, 7, 0, 3, 1, 6 };
    v[72] = { 5, 2, 6, 1, 3, 7, 0, 4 };
    v[73] = { 5, 2, 6, 1, 7, 4, 0, 3 };
    v[74] = { 5, 2, 6, 3, 0, 7, 1, 4 };
    v[75] = { 5, 3, 0, 4, 7, 1, 6, 2 };
    v[76] = { 5, 3, 1, 7, 4, 6, 0, 2 };
    v[77] = { 5, 3, 6, 0, 2, 4, 1, 7 };
    v[78] = { 5, 3, 6, 0, 7, 1, 4, 2 };
    v[79] = { 5, 7, 1, 3, 0, 6, 4, 2 };
    v[80] = { 6, 0, 2, 7, 5, 3, 1, 4 };
    v[81] = { 6, 1, 3, 0, 7, 4, 2, 5 };
    v[82] = { 6, 1, 5, 2, 0, 3, 7, 4 };
    v[83] = { 6, 2, 0, 5, 7, 4, 1, 3 };
    v[84] = { 6, 2, 7, 1, 4, 0, 5, 3 };
    v[85] = { 6, 3, 1, 4, 7, 0, 2, 5 };
    v[86] = { 6, 3, 1, 7, 5, 0, 2, 4 };
    v[87] = { 6, 4, 2, 0, 5, 7, 1, 3 };
    v[88] = { 7, 1, 3, 0, 6, 4, 2, 5 };
    v[89] = { 7, 1, 4, 2, 0, 6, 3, 5 };
    v[90] = { 7, 2, 0, 5, 1, 4, 6, 3 };
    v[91] = { 7, 3, 0, 2, 5, 1, 6, 4 };
}

int cost(int x, int y, int tx, int ty)
{
    if (x == tx && y == ty)
        return 0;
    if (x == tx || y == ty)
        return 1;
    if (abs(x - tx) == abs(y - ty))
        return 1;
    return 2;
}
int recur(int mask, int idx)
{
    if (idx >= 8)
        return 0;
    int& ans = dp[mask];
    int& vis = visited[mask];
    if (vis == cas)
        return ans;
    ans = 1e9;
    vis = cas;
    int tx, ty, px, py, cc;
    for (int i = 0; i < 8; i++) {
        if ((mask & (1 << i)) == 0) {
            tx = grid[idx].ff;
            ty = grid[idx].ss;
            px = i;
            py = v[nowidx][i];
            cc = cost(tx, ty, px, py);
            ans = min(ans, cc + recur(mask | (1 << i), idx + 1));
        }
    }
    return ans;
}

void clear_()
{
    memset(visited, 0, sizeof visited);
    nowidx = cas = 0;
}

int main()
{
    precal();
    QUERY
    {
        clear_();
        string s;
        getchar();
        int gg = 0;
        for (int i = 0; i < n; i++) {
            cin >> s;
            for (int j = 0; j < n; j++) {
                if (s[j] == 'q')
                    grid[gg++] = MP(i, j);
            }
        }
        int ans = 1e9;
        for (int i = 0; i < sz; i++) {
            nowidx = i;
            cas++;
            ans = min(ans, recur(0, 0));
        }
        printf("Case %d: %d\n", _T, ans);
    }
}
