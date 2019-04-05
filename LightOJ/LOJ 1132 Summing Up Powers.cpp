#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_set_rev = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using dijkstra = priority_queue<T, vector<T>, greater<T>>;

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define fbo find_by_order //k th index
#define ook order_of_key  // strictly smaller than k
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
ll rdn(int y, int m, int d)
{
    /* Rata Die day one is 0001-01-01 */
    if (m < 3)
        y--, m += 12;
    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}
/* Direction arrays */
/* int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1}; */                          // 4 Direction
/*int dx[] = {1,-1,0,0,1,1,-1,-1}, dy[] = {0,0,1,-1,1,-1,1,-1};       */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */   // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */              // Hexagonal Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */              // Hexagonal Direction
/* int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; */
const ll mod = (1ll << 32);
typedef vector<vector<ll>> matrix;
matrix base, I, zero;
int K;
ll ncr[55][55];
matrix mul(matrix A, matrix B)
{
    matrix c(K + 3, vector<ll>(K + 3));
    for (int i = 1; i <= K + 2; i++)
        for (int j = 1; j <= K + 2; j++)
            for (int k = 1; k <= K + 2; k++)
                c[i][j] = (c[i][j] + A[i][k] * B[k][j]) % mod;
    return c;
}
matrix pow(matrix A, int p)
{
    if (p == 0)
        return I;
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p - 1));
    matrix x = pow(A, p / 2);
    return mul(x, x);
}
matrix bigmod(matrix T, ll power)
{
    matrix res = I, x = T;
    while (power)
    {
        if (power % 2ll)
        {
            res = mul(res, x);
        }
        //res*=x,res%=mod;
        x = mul(x, x);
        //x=(x*x)%mod;
        power /= 2;
    }
    return res;
}
matrix sum(matrix A, matrix B)
{
    matrix c(K + 1, vector<ll>(K + 1));
    for (int i = 1; i <= K; i++)
        for (int j = 1; j <= K; j++)
            c[i][j] = (A[i][j] + B[i][j]) % mod;
    return c;
}
matrix bigsum(int p)
{
    if (p == 0)
        return zero;
    if (p % 2 == 1)
        return sum(mul(bigsum(p / 2), sum(I, pow(base, p / 2))), pow(base, p));
    p /= 2;
    return mul(bigsum(p), sum(I, pow(base, p)));
}
ll bigmod(ll base, ll power, ll mod)
{
    ll res = 1, x = base % mod;
    while (power)
    {
        if (power & 1)
            res *= x, res %= mod;
        x = (x * x) % mod;
        power >>= 1;
    }
    return res;
}
ll solve(ll N)
{
    matrix T(K + 3, vector<ll>(K + 3));
    T[1][1] = 1;
    int j = 0;
    for (int i = 2; j <= K; j++, i++)
        T[2][i] = T[1][i] = ncr[K][j];
    int t;
    int tt = 1;
    for (int i = 3; tt <= K; i++, tt++)
    {
        t = 0;
        for (int j = i; t <= K - tt; t++, j++)
            T[i][j] = ncr[K - tt][t];
    }
    if (N == 1)
        return 1;
    T = bigmod(T, N - 1);
    ll res = 0;
    for (int i = 1; i <= K + 2; i++)
        res = (res + T[1][i]) % mod;
    return res;
}
int main()
{
    ncr[0][0] = 1;
    ncr[1][0] = 1;
    ncr[1][1] = 1;
    for (int i = 2; i <= 54; i++)
    {
        ncr[i][0] = 1;
        for (int j = 1; j <= i; j++)
            ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
    }
    QUERY
    {
        ll n;
        scanf("%lld %d", &n, &K);

        I = matrix(K + 3, vector<ll>(K + 3));
        for (int i = 1; i <= K + 2; i++)
            I[i][i] = 1;
        ll ans = solve(n);
        printf("Case %d: %lld\n", _T, ans);
    }
}