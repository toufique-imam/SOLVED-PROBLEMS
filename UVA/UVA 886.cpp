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
typedef long long ll;
typedef unsigned long long ull;
#define fbo find_by_order
#define ook order_of_key
#define PI acos(-1.0)
#define eps 1e-10
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
#define trail_zero(x) __builtin_ctz(x)
#define total_1s(x) __builtin_popcount(x)
#define first_1(x) __builtin_ffs(x)
#define log2_(x) __builtin_clz(1) - __builtin_clz(x)
#define isLeap(x) ((x % 400 == 0) || (x % 100 ? x % 4 == 0 : false))
#define set(N, cur) N = (N | (1 << cur))
#define reset(N, cur) N = (N & (~(1 << cur)))
#define check(N, cur) ((N & (1 << cur)) == 0)
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
#define what_is(x) cerr << #x << " is " << x << endl;
#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
#define in_range(v, r, l) upper_bound(all(v), r) - lower_bound(all(v), l)
void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
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
/*int dx[] = {1,-1,0,0,1,1,-1,-1}, dy[] = {0,0,1,-1,1,-1,1,-1};     */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */            // Hexagonal Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */            // Hexagonal Direction
/* int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; */

struct node
{
    node *next[10];
    vector<string> v;
    node()
    {
        for (int i = 0; i < 10; i++)
            next[i] = NULL;
        v.clear();
    }
};
int make_int(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    c = tolower(c);
    if (c == 'a' || c == 'b' || c == 'c')
        return 2;
    if (c == 'd' || c == 'e' || c == 'f')
        return 3;
    if (c == 'g' || c == 'h' || c == 'i')
        return 4;
    if (c == 'j' || c == 'k' || c == 'l')
        return 5;
    if (c == 'm' || c == 'n' || c == 'o')
        return 6;
    if (c == 'p' || c == 'q' || c == 'r' || c == 's')
        return 7;
    if (c == 't' || c == 'u' || c == 'v')
        return 8;
    if (c == 'w' || c == 'x' || c == 'y' || c == 'z')
        return 9;
}
node *root;
void insert_(char c, string t, string x)
{
    node *now = root;
    int id = make_int(c);
    if (now->next[id] == NULL)
        now->next[id] = new node();
    now = now->next[id];
    for (int i = 0; i < t.size(); i++)
    {
        id = make_int(t[i]);
        if (now->next[id] == NULL)
            now->next[id] = new node();
        now = now->next[id];
        now->v.push_back(x);
    }
}
string x;
set<pair<int, string>> ss;
bool dfs(node *now, int pos)
{
    if (pos >= x.size())
    {
        for (int i = 0; i < now->v.size(); i++)
            ss.insert(MP(0, now->v[i]));
        return true;
    }
    int id = make_int(x[pos]);
    if (now->next[id] != NULL)
        return dfs(now->next[id], pos + 1);
    return false;
}
int main()
{
    FAST;
    vector<string> ms;
    string s, t;
    root = new node();
    while (cin >> s)
    {
        if (isalpha(s[0]))
        {
            cin >> t >> x;
            ms.push_back(x);
            insert_(s[0], t, x);
        }
        else
        {
            if (find(all(ms), s) != ms.end())
                cout << s << "\n";
            else
            {
                ss.clear();
                x = s;
                //cerr<<x<<"\n";
                bool f = dfs(root, 0);
                if (ss.empty())
                {
                    cout << "0\n";
                    continue;
                }
                vector<pair<int, string>> ans(all(ss));
                for (int i = 0; i < ans.size(); i++)
                    ans[i].ff = find(all(ms), ans[i].ss) - ms.begin();
                sort(all(ans));
                for (int i = 0; i < ans.size(); i++)
                {
                    cout << ans[i].ss;
                    if (i == ans.size() - 1)
                        cout << '\n';
                    else
                        cout << ' ';
                }
            }
        }
    }
}
