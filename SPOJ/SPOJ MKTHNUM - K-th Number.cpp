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
const int N = 100009;
vector<int> tr[4 * N];
int ara[N];
int ara1[N];
template <typename T>
ostream& operator<<(ostream& fout, const vector<T>& v) {
    for (T i : v)
        fout << i << " ";
    return fout;
}
void build(int u, int st, int en) {
    if (st == en) {
        //init
        tr[u] = vector<int>(1,ara[st]);
    } else {
        int mid = (st + en) / 2;
        int lt = u+u,rg=u+u+1;
        build(lt, st, mid);
        build(rg, mid + 1, en);
        //init
        merge(tr[lt].begin(),
        tr[lt].end(),tr[rg].begin(),tr[rg].end(),back_inserter(tr[u]));
    }
}

ll query(int u, int st, int en, int l, int r,int x) {
    if (r < st || en < l)
        return 0;  //proper null
    else if (st == l && en == r) {
        //cerr<<"debug "<<u<<" "<<tr[u]<<"\n";
        int lo=0,hi=tr[u].size()-1;
        int mid,ans=-1;
        while (lo<=hi)
        {
            mid=(lo+hi)/2;
            if(tr[u][mid]<=x){
                ans=mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }return ans+1;
        
    } else {
        int mid = (st + en) / 2;
        return query(u + u, st, mid, l, min(r,mid),x)+ query(u + u + 1, mid + 1, en, max(l,mid+1), r,x);
    }
}
ll query1(int u, int st, int en, int l, int r, int x) {
    if (r < st || en < l)
        return inf;  //proper null
    else if (st == l && en == r) {
        vector<int>::iterator pos = lower_bound(tr[u].begin(), tr[u].end(), x);
        if (pos != tr[u].end())
            return *pos;
        return inf;

    } else {
        int mid = (st + en) / 2;
        return min(query1(u + u, st, mid, l, min(r, mid), x) , query1(u + u + 1, mid + 1, en, max(l, mid + 1), r, x));
    }
}
void debug(int u, int st, int en) {
    cout << "--->" << u << " " << st << " " << en << " : " << tr[u] << " " << endl;
    if (st == en) return;
    int mid = (st + en) / 2;
    debug(u + u, st, mid);
    debug(u + u + 1, mid + 1, en);
}

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&ara[i]);
        ara1[i]=ara[i];
    }
    build(1,1,n);
   // debug(1,1,n);
    int l,r,val;
    sort(ara+1,ara+n+1);
    while (m--)
    {
        scanf("%d %d %d",&l,&r,&val);
        int lo = 1,hi = n,mid,ans=-1;
        while (lo<=hi)
        {
            mid = (lo+hi)/2;
            ll tmp = query(1,1,n,l,r,ara[mid]);
           // cerr<<"de "<<tmp<<" "<<ara[mid]<<"\n";
            if(tmp==val){
                ans = ara[mid];
                hi=mid-1;
            }
            else if(tmp<val){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
       // cerr<<ans<<"\n";
        //ans = query1(1,1,n,l,r,ans);
        printf("%d\n",ans);
    }
    
}
