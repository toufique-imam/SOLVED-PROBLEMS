/*
ID: sabertooth
LANG: C++11
TASK:
*/
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
using namespace std;
typedef long long ll;
#define eps 1e-9
#define inf 0x3f3f3f3f
#define INF 2e18
#define PI acos(-1.0)
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define max5(a, b, c, d, e) max(max3(a, b, c), max(d, e))
#define min5(a, b, c, d, e) min(min3(a, b, c), min(d, e))
#define Iterator(a) __typeof__(a.begin())
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define TEST            \
    int test;           \
    scanf("%d", &test); \
    for (int T = 1; T <= test; T++)
#define lead_zero(x) __builtin_clzll(x)
#define trail_zero(x) __builtin_ctz(x)
#define total_1s(x) __builtin_popcount(x)
#define reunique(v) v.resize(std::unique(all(v)) - v.begin())
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define segtree int mid = (st + en) / 2, lt = node * 2, rg = node * 2 + 1
#define MERGE(v1, v2, v) merge(all(v1), all(v2), back_inserter(v))
#define pll pair<ll, ll>

#define MH 1009
#define Base1 10000019
#define Base2 10000079
#define MOD1 1000000007
#define MOD2 1000000009
ll B1[MH], B2[MH];
map<pll, int> mp[1009];
int maxii[1009];
string s;
void init_hash()
{
    B1[0] = B2[0] = 1;
    for (int i = 1; i < MH; i++)
    {
        B1[i] = (B1[i - 1] * Base1) % MOD1;
        B2[i] = (B2[i - 1] * Base2) % MOD2;
    }
}
struct Hash
{
    pll *H;
    int *digit;
    int len;
    Hash()
    {
        H = new pll[MH];
        digit = new int[MH];
        len = 0;
        H[0] = pll(0, 0);
    }
    void clear()
    {
        len = 0;
        H[0] = pll(0, 0);
    }
    ~Hash()
    {
        delete (H);
        delete (digit);
    }
    void insert(char ch)
    {
        len++;
        digit[len] = ch - 'a' + 1;
        H[len].ff = (((H[len - 1].ff * Base1) % MOD1) + digit[len]) % MOD1;
        H[len].ss = (((H[len - 1].ss * Base2) % MOD2) + digit[len]) % MOD2;
    }
    pll substr(int l, int r)
    {
        if (l > len || r < 1 || r < l)
            return pll(0, 0);
        int sub_len = r - l + 1;
        pll ans;
        ans.ff = (H[r].ff - ((H[l - 1].ff * B1[sub_len]) % MOD1) + MOD1) % MOD1;
        ans.ss = (H[r].ss - ((H[l - 1].ss * B2[sub_len]) % MOD2) + MOD2) % MOD2;
        return ans;
    }
    pll concate(pll h, int l, int r)
    {
        pll x = substr(l, r);
        int sub_len = r - l + 1;
        h.ff = (((h.ff * B1[sub_len]) % MOD1) + x.ff) % MOD1;
        h.ss = (((h.ss * B2[sub_len]) % MOD2) + x.ss) % MOD2;
        return h;
    }
    bool operator==(const Hash &p) const
    {
        return len == p.len && H[len] == p.H[len];
    }
    pll &operator[](int index)
    {
        return H[index];
    }
};

int main()
{
    //read;
    init_hash();
    Hash *h1 = new Hash();
    while (getline(cin, s))
    {
        h1->clear();
        memset(maxii, 0, sizeof maxii);
        string nn;
        for (int i = 0; i < 1009; i++)
            mp[i].clear();
        for (int i = 0; i < s.size(); i++)
        {
            if (!isalpha(s[i]))
                continue;
            h1->insert(s[i]);
            nn += s[i];
        }
        pll x;
        int n = nn.size(), len;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                len = j - i + 1;
                x = h1->substr(i, j);
                mp[len][x]++;
                maxii[len] = max(maxii[len], mp[len][x]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (maxii[i] > 1)
            {
                printf("%d\n", maxii[i]);
            }
        }
        printf("\n");
    }
}
