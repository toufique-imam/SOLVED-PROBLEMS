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

/*-----------Hash-------------*/
string s;
#define Base1 10000019
#define Base2 10000079
#define MOD1 1000000007
#define MOD2 1000000009
pll calc_hash()
{
    int len = s.size();
    ll ans1 = 0;
    ll ans2 = 0;
    for (int i = 0; i < len; i++)
    {
        ll x = s[i] - 'a' + 1;
        ans1 = ((ans1 * Base1) % MOD1 + x) % MOD1;
        ans2 = ((ans2 * Base2) % MOD2 + x) % MOD2;
    }
    return MP(ans1, ans2);
}
/*---------------------------*/

vector<string> v;
bool comp(const vector<int> &v1, const vector<int> &v2)
{
    if (v1.size() != v2.size())
        return v1.size() > v2.size();
    else if (!v1.empty())
    {
        return v[v1[0]] < v[v2[0]];
    }
}
int main()
{
    map<pll, vector<int>> mp;
    while (cin >> s)
        v.push_back(s);
    sort(all(v));
    for (int i = 0; i < v.size(); i++)
    {
        s = v[i];
        sort(all(s));
        pll x = calc_hash();
        mp[x].push_back(i);
    }
    vector<vector<int>> ans;
    for (map<pll, vector<int>>::iterator itr = mp.begin(); itr != mp.end(); itr++)
    {
        ans.push_back(itr->ss);
    }
    sort(all(ans), comp);
    for (int i = 0; i < 5; i++)
    {
        if (ans[i].empty())
            break;
        printf("Group of size %d: ", (int)ans[i].size());
        for (int j = 0; j < (int)ans[i].size(); j++)
        {
            if (j == 0 || v[ans[i][j]] != v[ans[i][j - 1]])
                cout << v[ans[i][j]] << " ";
        }
        printf(".\n");
    }
}
