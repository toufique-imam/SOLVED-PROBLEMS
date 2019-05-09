#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef unsigned long long ull;
#define fbo find_by_order //k th index
#define ook order_of_key  // strictly smaller than k
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
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
#define SEGTREE int mid = (st + en) / 2, lt = node * 2, rg = node * 2 + 1
template <typename T1, typename T2>
ostream &operator<<(ostream &fout, const map<T1, T2> &mp)
{
    for (pair<T1, T2> i : mp)
        fout << i.first << " : " << i.second << endl;
    return fout;
}
template <typename T>
ostream &operator<<(ostream &fout, const vector<T> &v)
{
    for (T i : v)
        fout << i << " ";
    return fout;
}
template <typename T>
ostream &operator<<(ostream &fout, const set<T> &v)
{
    for (T i : v)
        fout << i << " ";
    return fout;
}
template <typename T>
ostream &operator<<(ostream &fout, const ordered_set<T> &v)
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
/* int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1}; */                        // 4 Direction
/*int dx[] = {1,-1,0,0,1,1,-1,-1}, dy[] = {0,0,1,-1,1,-1,1,-1};   */   // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */            // Hexagonal Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */            // Hexagonal Direction
/* int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; */
typedef pair<double, double> pt;
istream &operator>>(istream &fin, pt &a)
{
    fin >> a.ff >> a.ss;
    return fin;
}
ostream &operator<<(ostream &fout, pt &a)
{
    fout << a.ff << " " << a.ss << "\n";
    return fout;
}
class equation
{
public:
    double a, b, c;
    equation(){};
    equation(double x, double y, double z)
    {
        a = x;
        b = y;
        c = z;
    }
    equation(pt a, pt b)
    {
        double x1 = a.ff, y1 = a.ss, x2 = b.ff, y2 = b.ss;
        this->a = (y1 - y2);
        this->b = (x2 - x1);
        this->c = -1.0 * x1 * (y1 - y2) + y1 * (x1 - x2);
    }
    equation(equation x, pt y)
    {
        this->a = x.a;
        this->b = x.b;
        double val = -1.0 * x.valpt(y);
        this->c = val;
    }
    double valpt(pt x)
    {
        return a * x.ff + b * x.ss;
    }
    void print()
    {
        printf("(%f %f %f)\n", a, b, c);
    }
};

//ax+by+c=0;
pt equation_solve(equation p, equation q)
{
    double x, y;
    x = (p.b * q.c - q.b * p.c) / (p.a * q.b - q.a * p.b);
    y = (p.c * q.a - q.c * p.a) / (p.a * q.b - q.a * p.b);
    return pt(x, y);
}
int main()
{
    //read;
    //write;
    pt ta, tb, tc, td, a, b, c;
    while (cin >> ta >> tb >> tc >> td)
    {
        if (ta == tc)
        {
            b = ta;
            a = tb;
            c = td;
        }
        else if (ta == td)
        {
            b = ta;
            a = tb;
            c = tc;
        }
        else if (tb == tc)
        {
            b = tb;
            a = ta;
            c = td;
        }
        else if (tb == td)
        {
            b = tb;
            a = ta;
            c = tc;
        }
        pt ans;
        ans.ff = c.ff - (b.ff - a.ff);
        ans.ss = c.ss - (b.ss - a.ss);
        cout << fixed << setprecision(3);
        cout << ans.ff << " " << ans.ss << "\n";
    }
}
