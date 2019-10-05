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
        fout << i << " ";
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
const int N=3009;
int n;
map<string,int>_name,_poli,_club;
map<int,string>_rname,_rpoli,_rclub;
vector<int>v[N];
int grid[N][N];
int mini[N];
int par[N];
vector<int>clubr;
int supersource=0,supersink=1;
int bfs() {
    memset(mini,inf,sizeof mini);
    memset(par,-1,sizeof par);
    queue<int>q;
    int p;
    q.push(supersource);
    par[supersource]=supersource;
    while(!q.empty()) {
        int t=q.front();
        q.pop();
        if(t==supersink)
            break;
        for(int i=0; i<(int)v[t].size(); i++) {
            p=v[t][i];
            if(grid[t][p]==-1)grid[t][p]=(clubr.size()-1)/2;
            if(grid[t][p]>0 && par[p]==-1) {
                q.push(p);
                mini[p]=min(grid[t][p],mini[t]);
                par[p]=t;
            }
        }
    }
    if(par[supersink]!=-1)
        return mini[supersink];
    return 0;
}
void update_path(int now,int val) {
    if(par[now]==-1 || par[now]==now)
        return;
    grid[par[now]][now]-=val;
    grid[now][par[now]]+=val;
    update_path(par[now],val);
}
int maxflow() {
    int ans=0;
    int tt=bfs();
    while(tt>0) {
        ans+=tt;
        update_path(supersink,tt);
        tt=bfs();
    }
    return ans;
}
void clear() {
    memset(grid,0,sizeof grid);
    _poli.clear();
    _name.clear();
    _club.clear();
    _rname.clear();
    _rpoli.clear();
    _rclub.clear();
    clubr.clear();
    for(int i=0; i<N; i++)
        v[i].clear();
}
int main() {
    QUERY{
        clear();
        string s,name;
        if(_T==1){
            getchar();
            getchar();
        }
        else{
            puts("");
        }
        int cnt=2,pol=0;
        n=0;
        int peoplenow,policticsnow,tmp;
        while(getline(cin,s)) {
            if(s=="")
                break;
            n++;
            stringstream ss(s);
            ss>>name;
            if(_name[name]==0) {
                _name[name]=cnt;
                _rname[cnt]=name;
                cnt++;
            }
            peoplenow=_name[name];
            ss>>name;
            if(_poli[name]==0) {
                _poli[name]=cnt;
                _rpoli[cnt]=name;
                v[cnt].emplace_back(supersink);
                grid[cnt][supersink]=-1;
                cnt++;
                pol++;
            }
            policticsnow=_poli[name];

            v[peoplenow].emplace_back(policticsnow);
            v[policticsnow].emplace_back(peoplenow);
            grid[peoplenow][policticsnow]=1;

            while(ss>>name) {
                if(_club[name]==0) {
                    _club[name]=cnt;
                    _rclub[cnt]=name;
                    v[supersource].emplace_back(cnt);
                    grid[supersource][cnt]=1;
                    clubr.emplace_back(cnt);
                    cnt++;
                }
                tmp=_club[name];
                v[tmp].emplace_back(peoplenow);
                v[peoplenow].emplace_back(tmp);
                grid[tmp][peoplenow]=1;
            }
        }
        int ans=maxflow();
        pol=clubr.size();
        if(pol==ans) {
            for(int i=0; i<(int)clubr.size(); i++) {
                tmp=clubr[i];
                for(int j=0; j<(int)v[tmp].size(); j++) {
                    peoplenow=v[tmp][j];
                    if(grid[peoplenow][tmp]>0) {
                        cout<<_rname[peoplenow]<<" "<<_rclub[tmp]<<"\n";
                        break;
                    }
                }
            }
        } else
            puts("Impossible.");
    }
}
