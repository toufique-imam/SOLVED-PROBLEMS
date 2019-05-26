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
const double pi = acos(-1.0);
const double eps = 1e-8;

typedef double T;
struct pt
{
    T x, y;
    pt() {}
    pt(T _x, T _y) : x(_x), y(_y) {}
    pt operator+(const pt &p) const
    {
        return pt(x + p.x, y + p.y);
    }
    pt operator-(const pt &p) const
    {
        return pt(x - p.x, y - p.y);
    }
    pt operator*(const T &d) const
    {
        return pt(x * d, y * d);
    }
    pt operator/(const T &d) const
    {
        return pt(x / d, y / d);
    }
    bool operator==(const pt &p) const
    {
        return (x == p.x and y == p.y);
    }
    bool operator!=(const pt &p) const
    {
        return !(x == p.x and y == p.y);
    }
    bool operator<(const pt &p) const
    {
        if (x != p.x)
            return x < p.x;
        return y < p.y;
    }
    void input()
    {
        scanf("%lf %lf", &x, &y);
    }
};

T sq(pt p)
{
    return p.x * p.x + p.y * p.y;
}

double abs(pt p)
{
    return sqrt(sq(p));
}

pt translate(pt v, pt p)
{
    return p + v;
}

pt scale(pt c, double factor, pt p)
{
    return c + (p - c) * factor;
}

pt rot(pt p, double a)
{
    return pt(p.x * cos(a) - p.y * sin(a), p.x * sin(a) + p.y * cos(a));
}

pt perp(pt p)
{
    return pt(-p.y, p.x);
}

T dot(pt v, pt w)
{
    return v.x * w.x + v.y * w.y;
}

bool isPerp(pt v, pt w)
{
    return dot(v, w) == 0;
}

double smallAngle(pt v, pt w)
{
    double cosTheta = dot(v, w) / abs(v) / abs(w);
    if (cosTheta < -1)
        cosTheta = -1;
    if (cosTheta > 1)
        cosTheta = 1;
    return acos(cosTheta);
}

T cross(pt v, pt w)
{
    return v.x * w.y - v.y * w.x;
}

T orient(pt a, pt b, pt c)
{
    return cross(b - a, c - a);
}

bool inAngle(pt a, pt b, pt c, pt x)
{
    assert(orient(a, b, c) != 0);
    if (orient(a, b, c) < 0)
        swap(b, c);
    return orient(a, b, x) >= 0 and orient(a, c, x) <= 0;
}

//Line
struct line
{
    pt v;
    T c;
    line() {}
    //From points P and Q
    line(pt p, pt q)
    {
        v = (q - p);
        c = cross(v, p);
    }
    //From equation ax + by = c
    line(T a, T b, T c)
    {
        v = pt(b, -a);
        c = c;
    }
    //From direction vector v and offset c
    line(pt v, T c)
    {
        v = v;
        c = c;
    }

    //These work with T = int / double
    T side(pt p);
    double dist(pt p);
    double sqDist(pt p);
    line perpThrough(pt p);
    bool cmpProj(pt p, pt q);
    line translate(pt t);

    //These require T = double
    line shiftLeft(double dist);
    pt proj(pt p);
    pt refl(pt p);
};

T line ::side(pt p)
{
    return cross(v, p) - c;
}

double line ::dist(pt p)
{
    return abs(side(p)) / abs(v);
}

double line ::sqDist(pt p)
{
    return side(p) * side(p) / (double)sq(v);
}

line line ::perpThrough(pt p)
{
    return line(p, p + perp(v));
}

bool line ::cmpProj(pt p, pt q)
{
    return dot(v, p) < dot(v, q);
}

line line ::translate(pt t)
{
    return line(v, c + cross(v, t));
}

line line ::shiftLeft(double dist)
{
    return line(v, c + dist * abs(v));
}

bool areParallel(line l1, line l2)
{
    return (l1.v.x * l2.v.y == l1.v.y * l2.v.x);
}

bool areSame(line l1, line l2)
{
    return areParallel(l1, l2) and (l1.v.x * l2.c == l2.v.x * l1.c) and (l1.v.y * l2.c == l2.v.y * l1.c);
}

bool inter(line l1, line l2, pt &out)
{
    T d = cross(l1.v, l2.v);
    if (d == 0)
        return false;
    out = (l2.v * l1.c - l1.v * l2.c) / d;
    return true;
}

pt line ::proj(pt p)
{
    return p - perp(v) * side(p) / sq(v);
}

pt line ::refl(pt p)
{
    return p - perp(v) * 2 * side(p) / sq(v);
}

line intBisector(line l1, line l2, bool interior)
{
    assert(cross(l1.v, l2.v) != 0);
    double sign = interior ? 1 : -1;
    return line(l2.v / abs(l2.v) + l1.v * sign / abs(l1.v),
                l2.c / abs(l2.v) + l1.c * sign / abs(l1.v));
}

//Segment
bool inDisk(pt a, pt b, pt p)
{
    return dot(a - p, b - p) <= 0;
}

bool onSegment(pt a, pt b, pt p)
{
    return orient(a, b, p) == 0 and inDisk(a, b, p);
}

bool properInter(pt a, pt b, pt c, pt d, pt &i)
{
    double oa = orient(c, d, a),
           ob = orient(c, d, b),
           oc = orient(a, b, c),
           od = orient(a, b, d);

    //Proper intersection exists iff opposite signs
    if (oa * ob < 0 and oc * od < 0)
    {
        i = (a * ob - b * oa) / (ob - oa);
        return true;
    }
    return false;
}

bool inters(pt a, pt b, pt c, pt d)
{
    pt out;
    if (properInter(a, b, c, d, out))
        return true;
    if (onSegment(c, d, a))
        return true;
    if (onSegment(c, d, b))
        return true;
    if (onSegment(a, b, c))
        return true;
    if (onSegment(a, b, d))
        return true;
    return false;
}

double segPoint(pt a, pt b, pt p)
{
    if (a != b)
    {
        line l(a, b);
        if (l.cmpProj(a, p) and l.cmpProj(p, b))
            return l.dist(p);
    }
    return min(abs(p - a), abs(p - b));
}

double segSeg(pt a, pt b, pt c, pt d)
{
    pt dummy;
    if (properInter(a, b, c, d, dummy))
        return 0;
    return min(min(min(segPoint(a, b, c), segPoint(a, b, d)), segPoint(c, d, a)), segPoint(c, d, b));
}
pair<pt, pt> ara[100009];
int taken[10009];
int main()
{
    pt x, y;
    int n;
    while (scanf("%d", &n) == 1 && n)
    {
        for (int i = 0; i < n; i++)
        {
            ara[i].ff.input();
            ara[i].ss.input();
        }
        int sz = 0;
        for (int i = n - 1; i > -1; i--)
        {
            bool f = 1;
            for (int j = i + 1; j < n; j++)
            {
                int idx = j;
                if (inters(ara[idx].ff, ara[idx].ss, ara[i].ff, ara[i].ss))
                {
                    f = 0;
                    break;
                }
            }
            if (f)
            {
                taken[sz++] = i;
            }
        }
        printf("Top sticks:");
        for (int i = sz - 1; i > -1; i--)
        {
            printf(" %d", taken[i] + 1);
            if (i == 0)
                printf(".");
            else
                printf(",");
        }
        printf("\n");
    }
}
