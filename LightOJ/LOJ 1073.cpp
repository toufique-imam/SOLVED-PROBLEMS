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

int lt_match[17][17]; //ami jodi last er theke match korai taile koyta string pabe
string ara[17];
int dp[17][(1<<15)+2];
int n,limit;

int last_cnt(int pidx,int idx) {
    int ans=0;
    int lenp=ara[pidx].size();
    int len=ara[idx].size();
    do {
        if(len>lenp)
            continue;
        //cerr<<ara[idx].substr(0,len)<<" "<<ara[pidx].substr(lenp-len,len)<<"\n";
        if(ara[idx].substr(0,len)==ara[pidx].substr(lenp-len,len)) {
            ans=len;
            break;
        }
    } while(len--);
    return ans;
}
bool contains(int pidx,int idx) {
    if(ara[pidx].size()<ara[idx].size())
        return 0;
    int lenp=ara[pidx].size();
    int len=ara[idx].size();
    for(int i=0; i<lenp-len; i++) {
        if(ara[pidx].substr(i,len)==ara[idx])
            return 1;
    }
    return 0;
}
int recur(int last,int mask) {
    if(mask==limit)
        return 0;
    int &ans=dp[last][mask];
    if(ans!=-1)
        return ans;
    ans=1e9;
    for(int i=0; i<n; i++) {
        if((mask&(1<<i))==0)
            ans=min(ans,(int)ara[i].size()-lt_match[last][i]+recur(i,mask|(1<<i)));
    }
    return ans;
}
void print_ans(int last,int mask) {
    if(mask==limit){
        puts("");
        return;
    }
    int t,next=-1;
    bool f=0;
    string prev,now;
    for(int i=0; i<n; i++) {
        if((mask&(1<<i))==0) {
            t=ara[i].size()-lt_match[last][i]+dp[i][mask|(1<<i)];
            if(t>dp[last][mask])
                continue;
            else {
                if(f) {
                    now=ara[i].substr(lt_match[last][i],ara[i].size()-lt_match[last][i]);
                    if(now<prev) {
                        prev=now;
                        next=i;
                    }
                } else {
                    f=1;
                    next=i;
                    prev=ara[i].substr(lt_match[last][i],ara[i].size()-lt_match[last][i]);
                }
            }
        }
    }
    assert(next!=-1);
    cout<<prev;
    print_ans(next,mask|(1<<next));
}
int main() {
    QUERY{
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            cin>>ara[i];
        sort(ara,ara+n);
        int mask=0;
        for(int i=0; i<n; i++) {
            if((mask&(1<<i)))
                continue;
            for(int j=0; j<n; j++) {
                if(i==j)
                    continue;
                if((mask&(1<<j)))
                    continue;
                if(contains(i,j)) {
                    mask|=(1<<j);
                }
            }
        }
        for(int i=0; i<n; i++) {
            if((mask&(1<<i)))
                continue;
            for(int j=0; j<n; j++) {
                if(i==j)
                    continue;
                if((mask&(1<<j)))
                    continue;
                lt_match[i][j]=last_cnt(i,j);
            }
            lt_match[i][n]=0;
            lt_match[n][i]=0;
        }
        ara[n]="";
        limit=(1<<n)-1;
        memset(dp,-1,sizeof dp);
        recur(n,mask);
        printf("Case %d: ",_T);
        print_ans(n,mask);
    }
}
