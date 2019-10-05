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
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};                        // 4Direction
/*int dx[] = {1,-1,0,0,1,1,-1,-1}, dy[] = {0,0,1,-1,1,-1,1,-1};         */ // 8Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1};     */ // KnightDirection
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1};                */ // HexagonalDirection
/* int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; */
const int N = 2009;
int grid[N][N];
vector<int>v[N];
int mini[N];
int par[N];
vector<string>vv;
int n, m, q;
int supersource = 0, supersink;
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
        for(int i = 0; i < v[t].size(); i++) {
            p = v[t][i];
            if(par[p] == -1 && grid[t][p] > 0) {
                par[p] = t;
                mini[p] = min(mini[t], grid[t][p]);
                q.push(p);
            }
        }
    }
    return 0;
}
void update_path(int now, ll cc) {
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
map<pii, int>mp;
void clear() {
    vv.clear();
    mp.clear();
    memset(grid, 0, sizeof grid);
    for(int i = 0; i < N; i++) {
        v[i].clear();
    }
}
void flow_print(){
    for(int i=0;i<N;i++){
        if(v[i].empty())continue;
        cerr<<i<<" :: ";
        for(int j:v[i]){
            if(grid[i][j]>0)
            cerr<<"("<<j<<":"<<grid[i][j]<<") ";
        }
        cerr<<endl;
    }
}
int main() {
    string s;
    while(scanf("%d %d %d", &n, &m, &q) == 3) {
        clear();
        int cnt = 0;
        int tx, rx, px, py;
        for(int i = 0; i < n; i++) {
            cin >> s;
            vv.EB(s);
            for(int j = 0; j < m; j++) {
                if(s[j] == '~') {
                    continue;
                }
                mp[MP(i, j)] = ++cnt;
                tx = cnt;
                rx = ++cnt;
                assert(tx<N && rx<N);
                v[tx].EB(rx);
                v[rx].EB(tx);
                if(s[j] == '#' || s[j] == '@') {
                    grid[tx][rx] = inf;
                } else {
                    grid[tx][rx] = 1;
                }
            }
        }
        supersource = ++cnt;
        supersink = ++cnt;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vv[i][j] == '~')
                    continue;
                tx = mp[MP(i, j)];
                if(vv[i][j] == '*') {
                    v[supersource].EB(tx);
                    v[tx].EB(supersource);
                    grid[supersource][tx] = 1;
                }
                tx++;
                if(vv[i][j] == '#') {
                    v[supersink].EB(tx);
                    v[tx].EB(supersink);
                    grid[tx][supersink] = q;
                }
                for(int k = 0; k < 4; k++) {
                    px = dx[k] + i;
                    py = dy[k] + j;
                    if(px > -1 && py > -1 && px < n && py < m) {
                        if(vv[px][py] == '~')
                            continue;
                        rx = mp[MP(px, py)];
                        v[tx].EB(rx);
                        v[rx].EB(tx);
                        if(vv[px][py] == '#' || vv[px][py]=='@') {
                            grid[tx][rx] = inf;
                        } else {
                            grid[tx][rx] = 1;
                        }
                    }
                }
            }
        }
        int ans = maxflow();
        printf("%d\n",ans);
    }

}
