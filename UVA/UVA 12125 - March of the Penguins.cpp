#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using dijkstra = priority_queue<T, vector<T>, greater<T>>;

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define fbo find_by_order  // k th index
#define ook order_of_key   // strictly smaller than k
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define max_ull 18446744073709551615
#define max_ll 9223372036854775807
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
#define pul pair<ull, ull>
#define ff first
#define ss second
#define MERGE(v1, v2, v) merge(all(v1), all(v2), back_inserter(v))
#define MP make_pair
#define EB emplace_back
#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)
#define in_range(v, r, l) upper_bound(all(v), r) - lower_bound(all(v), l)
#define LCM(a, b) (a / __gcd(a, b)) * b;

ll rdn(int y, int m, int d) {
    /* Rata Die day one is 0001-01-01 */
    if (m < 3)
        y--, m += 12;
    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}
/* Direction arrays */
/*int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};                             */  // 4Direction
/*int dx[] = {1,-1,0,0,1,1,-1,-1}, dy[] = {0,0,1,-1,1,-1,1,-1};         */  // 8Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1};     */  // KnightDirection
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1};                */  // HexagonalDirection
/* int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; */
const int N1 = 1009;
vector<pair<pii, pii>> vp;
vector<int> edge[N1];
int cost[N1][N1];
int grid[N1][N1];
int n;
double dist;
int supersource = 1001, supersink = 1002;
double distance(int i, int j) {
    double d = (vp[i].ff.ff - vp[j].ff.ff) * (vp[i].ff.ff - vp[j].ff.ff) + (vp[i].ff.ss - vp[j].ff.ss) * (vp[i].ff.ss - vp[j].ff.ss);
    return d;
}
void addedge(int from, int to, int val) {
    if (cost[from][to] == 0 && cost[to][from] == 0) {
        edge[from].EB(to);
        edge[to].EB(from);
    }
    cost[from][to] += val;
}
void clear() {
    vp.clear();
    for (int i = 0; i < N1; i++) {
        edge[i].clear();
    }
    memset(cost,0,sizeof cost);
}
int par[N1],mini[N1];
int bfs() {
    memset(par, -1, sizeof par);
    memset(mini, inf, sizeof mini);
    queue<int> q;
    int p;
    q.push(supersource);
    par[supersource] = supersource;
    while (q.empty() == false) {
        int t = q.front();
        q.pop();
        if (t == supersink) return mini[t];
        for (int i = 0; i < edge[t].size(); i++) {
            p = edge[t][i];
            if (par[p] == -1 && grid[t][p] > 0) {
                par[p] = t;
                mini[p] = min(mini[t], grid[t][p]);
                q.push(p);
            }
        }
    }
    return 0;
}
void update_path(int x,int flow){
    if(par[x]==x || par[x]==-1){
    //    cerr<<x<<" ";
        return;
    }
    grid[par[x]][x]-=flow;
    grid[x][par[x]]+=flow;
    update_path(par[x],flow);
    //cerr<<x<<" ";
}
int maxflow()
{
    for(int i=0;i<N1;i++){
        for(int j=0;j<N1;j++){
            grid[i][j]=cost[i][j];
        }
    }
    int ans=0;
    int mf=bfs();
    while(mf>0){
        ans+=mf;
        update_path(supersink,mf);
     //   cerr<<" :: "<<mf<<"\n";
        mf=bfs();
    }
    return ans;
}
void debug()
{
    for(int i=0;i<N1;i++){
        if(edge[i].empty())continue;
        cerr<<i<<" :: ";
        for(int j:edge[i]){
            cerr<<"("<<j<<","<<cost[i][j]<<")"<<" ";
        }
        cerr<<endl;
    }
}
int main() {
    QUERY {
        clear();
        scanf("%d %lf", &n, &dist);
        dist = dist * dist;
        int xi, yi, ni, mi;
        int sum=0;
        //lets say distination is i, then source->(ni)->node->(mi)->i->(inf)->sink if flow==n ok
        // node split
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d %d", &xi, &yi, &ni, &mi);
            vp.EB(MP(MP(xi, yi), MP(ni, mi)));
        }
        for (int i = 0; i < n; i++) {
            addedge(supersource, 2*i, vp[i].ss.ff);
            addedge(2*i, 2*i+1, vp[i].ss.ss);
            sum+=vp[i].ss.ff;
            //cerr<<"DD "<<vp[i].ss.ff<<"\n";
            for (int j = i + 1; j < n; j++) {
                if (distance(i, j) <= dist) {
                    addedge(2*i+1, 2*j, inf);
                    addedge(2*j+1, 2*i, inf);
                }
            }
        }
        //debug();
        bool f=0;
        for (int i = 0; i < n; i++) {
            edge[2*i+1].EB(supersink);
            cost[2*i+1][supersink]=inf;
            cost[2*i][2*i+1]=inf;
            int ans=maxflow();
            if(ans==sum){
                if(f)printf(" ");
                printf("%d",i);
                f=1;
            }
            edge[2*i+1].pop_back();
            cost[2*i+1][supersink]=0;
            cost[2*i][2*i+1]=vp[i].ss.ss;
        }
        if(!f)printf("-1");
        printf("\n");
    }
}
