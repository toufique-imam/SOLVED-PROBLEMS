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
#define MAX 109
bool done[MAX];
int used[MAX];

typedef long long Tc;
typedef long long Tf;
struct Edge {
    int from, to, next;
    Tf cap, flow;
    Tc cost;
    Edge(int from, int to, int next, Tf cap, Tc cost) {
        this->from = from;
        this->to = to;
        this->next = next;
        this->cap = cap;
        this->cost = cost;
        this->flow = 0;
    }
};
struct MinCostFlow {
    typedef pair<Tc, int> Pti;
    Tf infF = (numeric_limits<Tf>::max() / 4);
    Tc infC = (numeric_limits<Tf>::max() / 4);
    int n;
    int S, T, ne[MAX];
    Tc d[MAX];
    //Tc pi[MAX];
    vector<Edge> E;
    void init(int _n) {
        n = _n;
        memset(ne, -1, n * sizeof(int));
        //fill(pi, pi + n, 0);
        E.clear();
    }
    void addEdge(int u, int v, Tf cap = 1, Tc cost = 0) {
        E.push_back(Edge(u, v, ne[u], cap, cost));
        ne[u] = (int)E.size() - 1;
        E.push_back(Edge(v, u, ne[v], 0, -cost));
        ne[v] = (int)E.size() - 1;
    }
    bool djkstra() {
        memset(used, -1, n * sizeof(int));
        memset(done, 0, n * sizeof(bool));
        fill(d, d + n, infC);
        priority_queue<Pti, vector<Pti>, greater<Pti>> q;
        q.push(MP(0, S));
        d[S] = 0;
        while (!q.empty()) {
            int u = q.top().second, v;
            q.pop();
            if (done[u]) continue;
            done[u] = 1;
            for (int i = ne[u]; i != -1; i = E[i].next) {
                v = E[i].to;
                Tc pot = d[u] ;//+ pi[u] - pi[v];
                if (E[i].cap > E[i].flow && pot + E[i].cost < d[v]) {
                    d[v] = pot + E[i].cost;
                    used[v] = i;
                    q.push(MP(d[v], v));
                }
            }
        }
        //for (int i = 0; i < n; i++) pi[i] = min(pi[i] + d[i], infC);
        return d[T] != infC;
    }
    bool belmanford() {
        memset(used, -1, n * sizeof(int));
        memset(done, 0, n * sizeof(bool));
        fill(d, d + n, infC);
        queue<int> q;
        q.push(S);
        d[S] = 0;
        while (!q.empty()) {
            int u = q.front(), v;
            q.pop();
            done[u] = 0;
            for (int i = ne[u]; i != -1; i = E[i].next) {
                v = E[i].to;
                Tc pot = d[u];  //+ pi[u] - pi[v];
                if (E[i].cap > E[i].flow && pot+E[i].cost < d[v]) {
                    d[v] = pot+E[i].cost ;
                    used[v] = i;
                    if (done[v] == 0) {
                        q.push(v);
                        done[v] = 1;
                    }
                }
            }
        }
        return used[T]!=-1;
        //for (int i = 0; i < n; i++) pi[i] = min(pi[i] + d[i], infC);
        //return d[T] != infC;
    }
    pair<Tf, Tc> maxFlow(int src, int snk) {
        S = src, T = snk;
        Tf flow = 0;
        Tc cost = 0;
        while (belmanford()) {
            snk = T;
            Tf bflow = infF;
            while (snk != S) {
                bflow = min(bflow, E[used[snk]].cap - E[used[snk]].flow);
                snk = E[used[snk]].from;
            }
            snk = T;
            while (snk != S) {
                E[used[snk]].flow += bflow;
                E[used[snk] ^ 1].flow -= bflow;
                cost += E[used[snk]].cost * bflow;
                snk = E[used[snk]].from;
            }
            flow += bflow;
        }
        return make_pair(flow, cost);
    }
}mcf;


int main() {
   // read;
    //write;
    int n,m;
    while (scanf("%d",&n)==1 && n)
    {
        scanf("%d",&m);
        mcf.init(n+7);
        int a,b,c;
        mcf.addEdge(0,1,2,0);
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&a,&b,&c);
            mcf.addEdge(a,b,1,c);
            mcf.addEdge(b,a,1,c);
        }
        mcf.addEdge(n,n+1,2,0);
        pll ans=mcf.maxFlow(0,n+1);
        if(ans.first<2){
            puts("Back to jail");
        }
        else{
            printf("%lld\n",ans.second);
        }
    }
    
}
