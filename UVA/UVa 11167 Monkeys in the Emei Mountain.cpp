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
#define pul pair<ull,ull>
#define ff first
#define ss second
#define MERGE(v1, v2, v) merge(all(v1), all(v2), back_inserter(v))
#define MP make_pair
#define EB emplace_back
#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)
#define in_range(v, r, l) upper_bound(all(v), r) - lower_bound(all(v), l)
#define LCM(a, b) (a / __gcd(a, b)) * b;
#define SEGMENT_TREE int mid=(st+en)/2,lt=node*2,rg=lt+1
template <typename T1, typename T2>
ostream& operator<<(ostream& fout, const pair<T1, T2>& ps) {
    fout << ps.ff << " " << ps.ss;
    return fout;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& fout, const map<T1, T2>& mp) {
    for (pair<T1, T2> i : mp)
        fout << i.first << " : " << i.second << "\n";
    return fout;
}
template <typename T>
ostream& operator<<(ostream& fout, const vector<T>& v) {
    for (T i : v)
        fout << i << "\n";
    return fout;
}
template <typename T>
ostream& operator<<(ostream& fout, const set<T>& v) {
    for (T i : v)
        fout << i << " ";
    return fout;
}
template <typename T>
ostream& operator<<(ostream& fout, const ordered_set<T>& v) {
    for (T i : v)
        fout << i << " ";
    return fout;
}
ll rdn(int y, int m, int d) {
    /* Rata Die day one is 0001-01-01 */
    if (m < 3)
        y--, m += 12;
    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}
/* Direction arrays */
/*int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};                             */ // 4Direction
/*int dx[] = {1,-1,0,0,1,1,-1,-1}, dy[] = {0,0,1,-1,1,-1,1,-1};         */ // 8Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1};     */ // KnightDirection
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1};                */ // HexagonalDirection
/* int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; */
const int N1 = 50309;
const int N = 509;
int par[N], mini[N];
int node_[N1], idx[N1], tracker[N1];
vector<int>edge[N];
int grid[N][N];
int supersource = 0, supersink = 1;
vector< pair<pii, pii> >vv;
vector<pii>print[N];
int bfs() {
    memset(par, -1, sizeof par);
    memset(mini, inf, sizeof mini);
    queue<int>q;
    int p;
    q.push(supersource);
    par[supersource] = supersource;
    while(!q.empty()) {
        int t = q.front();
        q.pop();
        if(t == supersink)
            return mini[t];
        for(int i = 0; i < edge[t].size(); i++) {
            p = edge[t][i];
            if(par[p] == -1 && grid[t][p] > 0) {
                par[p] = t;
                mini[p] = min(mini[t], grid[t][p]);
                q.push(p);
            }
        }
    }
    return 0;
}
void update_path(int now, int cc) {
    if(now == -1 || par[now] == now)
        return;
    grid[par[now]][now] -= cc;
    grid[now][par[now]] += cc;
    update_path(par[now], cc);
}
int maxflow() {
    int ans = 0;
    int mf = bfs();
    while(mf > 0) {
        update_path(supersink, mf);
        ans += mf;
        mf = bfs();
    }
    return ans;
}

inline void add_edge(int from, int to, int w) {
    edge[from].EB(to);
    edge[to].EB(from);
    grid[from][to] = w;
}
void clear() {
    vv.clear();
    memset(tracker, 0, sizeof tracker);
    memset(node_, 0, sizeof node_);
    memset(idx, 0, sizeof idx);
    for(int i = 0; i < N; i++) {
        edge[i].clear();
        print[i].clear();
    }
    memset(grid, 0, sizeof grid);
}
int main() {
    read;
    write;
    int n, m, cas = 0;
    while(scanf("%d", &n) == 1 && n) {
        clear();
        scanf("%d", &m);
        cas++;
        int v, a, b, lo = 1e9, hi = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d %d %d", &v, &a, &b);
            lo = min(lo, a);
            hi = max(hi, b);
            node_[a] = 1;
            node_[b] = 1;
            vv.EB(MP(MP(a, b), MP(v, i + 2)));
        }
        sort(all(vv));
        int minix, cnt = n + 2;
        int taken = 0, prev = -1;
        bool f = 0;

        for(int i = lo; i <= hi; i++) {
            if(node_[i] == 1) {
                if(prev == -1)
                    prev = i;
                else {
                    vv.EB(MP(prev, i), MP(0, cnt));
                    idx[prev] = vv.size() - 1;
                    assert(cnt < N);
                    add_edge(cnt, supersink, (i - prev)*m);
                    prev = i;
                    cnt++;
                }
            }
        }
        //cerr<<vv<<endl;
        pair<pii, pii>tt;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            add_edge(supersource, vv[i].ss.ss, vv[i].ss.ff);
            sum += vv[i].ss.ff;
            for(int j = vv[i].ff.ff; j <= vv[i].ff.ss; j++) {
                if(node_[j] == 1) {
                    tt = vv[idx[j]];
                    add_edge(vv[i].ss.ss, tt.ss.ss, tt.ff.ss - tt.ff.ff);
                }
            }
        }
        int ans = maxflow();
        //cerr << ans << " " << sum << endl;
        //cerr << (ans == sum ? "YES" : "NO") << endl;
        printf("%s\n", ans == sum ? "YES" : "NO");
        if(ans == sum) {
            sort(vv.begin(), vv.begin() + n, [](pair<pii, pii>a, pair<pii, pii>b) {
                if(a.ff.ss != b.ff.ss)
                    return a.ff.ss<b.ff.ss;
                return a.ff.ff < b.ff.ff;
            });
            for(int i = 0; i < n; i++) {
                int need = vv[i].ss.ff;
                cerr<<vv[i]<<endl;
                for(int j = vv[i].ff.ff; j <= vv[i].ff.ss && need > 0; j++) {
                    if(node_[j] == 1) {
                        tt = vv[idx[j]];
                        int last = -1;
                        for(int k = tt.ff.ff; k <= tt.ff.ss ; k++) {
                            if(need==0){
                                print[vv[i].ss.ss].EB(MP(last, k));
                                last=-1;
                                break;
                            }
                            if(tracker[k] == 0) {
                                if(last == -1)
                                    last = k;
                                need--;
                                tracker[k] = 1;
                            } else {
                                if(last != -1) {
                                    print[vv[i].ss.ss].EB(MP(last, k));
                                }
                                last = -1;
                            }
                        }
                        if(last!=-1){
                            print[vv[i].ss.ss].EB(MP(last,tt.ff.ss+1));
                        }
                    }
                }
            }
            for(int i = 0; i < N; i++) {
                if(print[i].empty())
                    continue;
                cerr << i << " :: ";
                cerr << print[i] << endl;
            }
        }

    }

}
