#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using dijkstra = priority_queue<T, vector<T>, greater<T>>;

typedef long long ll;
#define fbo find_by_order // k th index
#define ook order_of_key // strictly smaller than k
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define FAST ios_base::sync_with_stdio(0), cin.tie(0)
#define all(v) v.begin(), v.end()
#define reunique(v) v.resize(std::unique(all(v)) - v.begin())
#define MERGE(v1, v2, v) merge(all(v1), all(v2), back_inserter(v))
#define SEGMENT_TREE int mid = (st + en) / 2, lt = node * 2, rg = lt + 1
#define MP make_pair
#define EB emplace_back
#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)
#define in_range(v, r, l) upper_bound(all(v), r) - lower_bound(all(v), l)
#define LCM(a, b) (a / __gcd(a, b)) * b;
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
const int N = 1e5 + 9;

struct update {
    int a, k, en, t;
    char c;
    update() {}
    update(int _a, int _k, char _c, int _en, int _t)
    {
        a = _a;
        k = _k;
        c = _c;
        en = _en;
        t = _t;
    }
};

vector<update> v[N];
int ma[N];
int main()
{
    FAST;
    string s;
    cin >> s;
    int n = s.size();
    s = "*" + s;
    int q;
    update tmp;
    cin >> q;
    int ii, len;
    int can = sqrt(n);
    can=max(400,can);
    for (int i = 1; i <= q; i++) {
        cin >> ii >> tmp.a >> tmp.k >> tmp.c;
        tmp.en = (ii + tmp.a * tmp.k);
        tmp.t = i;
        if (tmp.k <= can) {
            for (int j = ii; j <= tmp.en; j += tmp.a) {
                ma[j] = i;
                s[j] = tmp.c;
            }
        } else {
            v[ii].EB(tmp);
        }
    }
    for (int i = 1; i <= n; i++) {
        sort(all(v[i]), [](update& aa, update& bb) {
            if (aa.a != bb.a) {
                return aa.a < bb.a;
            }
            return aa.t > bb.t;
        });
        tmp = update(-1, -1, s[i], -1, ma[i]);
        for (update xx : v[i]) {
            if (xx.a == tmp.a) {
                if (xx.en >= tmp.en + tmp.a) {
                    v[tmp.en + tmp.a].EB(xx);
                    tmp.en = xx.en;
                }
            } else {
                tmp.a = xx.a;
                tmp.en = xx.en;
                if (xx.en >= i + tmp.a) {
                    v[i + tmp.a].EB(xx);
                }
            }
            if (xx.t > tmp.t) {
                tmp.t = xx.t;
                tmp.c = xx.c;
            }
            s[i] = tmp.c;
        }
        v[i].clear();
        cout << s[i];
    }
    cout << "\n";
}