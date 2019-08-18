#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
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
        fout << i.first << " : " << i.second << endl;
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
const int N=1e5+9;
vector<int>v[N];
int visited[N];
int inedge[N];
int cas;
bool dfs(int x){
    visited[x]=cas;
    bool ans=0;
    for(int i=0;i<v[x].size() && !ans;i++){
        int _t=v[x][i];
        if(visited[_t]!=cas){
            ans|=dfs(_t);
        }
        else return 1;
    }
    return ans;
}
void clear_(){
    for(int i=0;i<N;i++){
        v[i].clear();
        visited[i]=0;
        inedge[i]=0;
    }
}
int main() {
    int n,m;
    while(scanf("%d %d",&n,&m)==2) {
        if(n<0 && m<0)
            break;
        bool f=1;
        int cnt=1,a,b;
        unordered_set<int>s;
        unordered_map<int,int>mp;
        cas++;
        clear_();
        do {
            if(n==0 || m==0)
                break;
            if(n==m)
                f=0;
            if(f) {
                if(mp[n]==0){
                    mp[n]=cnt++;
                }
                if(mp[m]==0){
                    mp[m]=cnt++;
                }
                a=mp[n];
                b=mp[m];
                inedge[b]++;
                if(inedge[b]>1)f=0;
                v[a].EB(b);
                s.insert(a);
                s.insert(b);
            }
        }while(scanf("%d %d",&n,&m)==2);

        if(f && s.empty()==false) {
            int root=0;
            for(unordered_set<int>::iterator itr=s.begin();f && itr!=s.end(); itr++) {
                n=*itr;
                if(inedge[n]==0){
                    root++;
                    m=n;
                }
            }
            if(root!=1)
                f=0;
        }
        if(f){
            int ans=dfs(m);
            if(ans==1)f=0;
            for(unordered_set<int>::iterator itr=s.begin();f && itr!=s.end(); itr++) {
                n=*itr;
                if(visited[n]!=cas){
                    f=0;
                }
            }
        }
        if(f)
            printf("Case %d is a tree.\n",cas);
        else
            printf("Case %d is not a tree.\n",cas);
    }
}
