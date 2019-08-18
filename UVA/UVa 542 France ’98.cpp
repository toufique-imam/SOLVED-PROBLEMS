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
vector<string>v;
double dp[20][4];
double prob[20][20];
vector<pii>ara[4];
bool inside(int id,int i,int x) {
    return (ara[id][i].ff<=x && ara[id][i].ss>=x);
}
bool samegroup(int prev,int x,int me) {
    if(prev<0)
        return false;
    for(int i=0; i<ara[prev].size(); i++) {
        if(inside(prev,i,x) && inside(prev,i,me))
            return true;
    }
    return false;
}
int main() {
    int n=16;
    for(int i=0; i<n; i+=2)
        ara[0].push_back(MP(i,i+1));
    for(int i=0; i<n; i+=4)
        ara[1].push_back(MP(i,i+3));
    for(int i=0; i<n; i+=8)
        ara[2].push_back(MP(i,i+7));
    ara[3].push_back(MP(0,15));
    string s;
    for(int i=0; i<n; i++) {
        cin>>s;
        v.push_back(s);
        dp[i][0]=1.0;
        dp[i][1]=1.0;
        dp[i][2]=1.0;
        dp[i][3]=1.0;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%lf",&prob[i][j]);
            prob[i][j]/=100.0;
        }
    }
    for(int id=0; id<4; id++) {
        for(int i=0; i<n; i++) {
            int grp=i/(1<<(id+1));
            if(id)
                dp[i][id]=dp[i][id-1];
            double xd=0.0;
            for(int j=0; j<n; j++) {
                if(i==j)
                    continue;
                int grpnow=j/(1<<(id+1));
                if(grpnow!=grp)
                    continue;
                if(samegroup(id-1,j,i))
                    continue;
                if(id)xd+=dp[j][id-1]*prob[i][j];
                else xd+=prob[i][j];
            }
            dp[i][id]*=xd;
        }
    }
    cout<<fixed<<setprecision(2);
    for(int i=0; i<n; i++)
    {
        cout<<v[i];
        for(int j=v[i].size();j<11;j++){
            cout<<" ";
        }
        cout<<"p="<<dp[i][3]*100.0<<"%\n";
    }
}
