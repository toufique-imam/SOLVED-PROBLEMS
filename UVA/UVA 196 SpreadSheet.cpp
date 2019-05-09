#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_set_rev = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using dijkstra = priority_queue<T, vector<T>, greater<T>>;

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define fbo find_by_order //k th index
#define ook order_of_key // strictly smaller than k
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
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
#define QUERY int test;scanf("%d", &test);for (int _T = 1; _T <= test; _T++)
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
#define LCM(a,b) (a/__gcd(a,b))*b;
ll rdn(int y, int m, int d) {
    /* Rata Die day one is 0001-01-01 */
    if (m < 3)
        y--, m += 12;
    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}
/* Direction arrays */
/* int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1}; */                         // 4 Direction
/*int dx[] = {1,-1,0,0,1,1,-1,-1}, dy[] = {0,0,1,-1,1,-1,1,-1};   */    // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */            // Hexagonal Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */            // Hexagonal Direction
/* int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; */
#define SEGTREE int mid=(st+en)/2,lt=node*2,rg=node*2+1;
int grid[1009][1009];
pair<int,int> eva_str(string s) {
    int ii=0;
    int jj=0;
    for(int i=0;i<s.size();i++){
        if(isalpha(s[i])){
            jj=jj*26+s[i]-'A'+1;
        }
        else{
            ii=ii*10+s[i]-'0';
        }
    }
    return MP(jj,ii);
}
int to_num(string s) {
    int ans=0;
    bool f=0;
    int st=0;
    if(s[0]=='-') {
        st=1;
        f=1;
    }
    for(int i=st; i<s.size(); i++)
        ans=(ans*10+s[i]-'0');
    if(f)
        ans=-1*ans;
    return ans;
}
/*

*/
struct node {
    int i,j;
    pii x;
    node(int a,int b,pii xx) {
        i=a;
        j=b;
        x=xx;
    }
};
int cntt[1009][1009];
int main() {
    QUERY{
        int n,m;
        scanf("%d %d",&n,&m);
        string s;
        int x;
        memset(grid,0,sizeof grid);
        memset(cntt,0,sizeof cntt);
        map<pair<int,int>,int>mp;
        queue<node>q;

        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                cin>>s;
                if(s[0]=='=') {
                    string tt="";
                    int ans=0;
                    for(int k=1; k<s.size(); k++) {
                        if(s[k]=='+') {
                            pair<int,int> x=eva_str(tt);
                            if(mp.find(x)!=mp.end())
                                grid[i][j]+=mp[x];
                            else {
                                cntt[i][j]++;
                                q.push(node(i,j,x));
                            }
                            tt="";
                        } else
                            tt+=s[k];
                    }
                    pair<int,int> x=eva_str(tt);
                    if(mp.find(x)!=mp.end())
                        grid[i][j]+=mp[x];
                    else {
                        cntt[i][j]++;
                        q.push(node(i,j,x));
                    }
                } else {
                    x=to_num(s);
                    mp[MP(j,i)]=x;
                    grid[i][j]=x;
                }
            }
        }
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(cntt[i][j]<1) {
                    mp[MP(j,i)]=grid[i][j];
                }
            }
        }
        while(!q.empty()){
            node xx=q.front();
            q.pop();
            if(mp.find(xx.x)!=mp.end()){
                grid[xx.i][xx.j]+=mp[xx.x];
                cntt[xx.i][xx.j]--;
                if(cntt[xx.i][xx.j])continue;
                mp[MP(xx.j,xx.i)]=grid[xx.i][xx.j];
            }
            else{
                q.push(xx);
            }
        }
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                printf("%d",grid[i][j]);
                //if(j==n)printf("\n");
                if(j!=n)
                    printf(" ");
            }
            printf("\n");
        }
    }
}
