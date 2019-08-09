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
const int N=19;
char ara[N][N];
char mara[N][N];
int n;
char tempara[N][N];
void equalop() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            tempara[i][j]=ara[i][j];
    }
}
void rotate_90() {
    equalop();
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            ara[j][n-i+1]=tempara[i][j];
    }
}
void print() {
    cout<<"debug"<<endl;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            cout<<ara[i][j];
        cout<<endl;
    }
    cout<<"debug"<<endl;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            cout<<mara[i][j];
        cout<<endl;
    }
}
bool isequal() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(ara[i][j]!=mara[i][j])
                return 0;
        }
    }
    return 1;
}
bool reflected() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(ara[i][j]!=mara[n-i+1][j])
                return 0;
        }
    }
    return 1;
}
void reflect() {
    equalop();
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            ara[i][j]=tempara[n-i+1][j];
    }
}
int main() {
    int cas=1;
    while(scanf("%d",&n)==1 && n) {
        getchar();
        string s;
        for(int i=1; i<=n; i++) {
            getline(cin,s);
            int j=0;
            for(; j<n; j++)
                ara[i][j+1]=s[j];

            int idx=0;
            for(; j<s.size(); j++)
                mara[i][idx++]=s[j];
        }
        printf("Pattern %d ",cas++);
        if(isequal()) {
            printf("was preserved.\n");
            continue;
        }
        rotate_90();
        if(isequal()) {
            printf("was rotated 90 degrees.\n");
            continue;
        }
        rotate_90();
        if(isequal()) {
            printf("was rotated 180 degrees.\n");
            continue;
        }
        rotate_90();
        if(isequal()) {
            printf("was rotated 270 degrees.\n");
            continue;
        }
        rotate_90();
        if(reflected()) {
            printf("was reflected vertically.\n");
            continue;
        }
        reflect();
        rotate_90();
        if(isequal()) {

            printf("was reflected vertically and rotated 90 degrees.\n");
            continue;
        }
        rotate_90();
        if(isequal()) {
            printf("was reflected vertically and rotated 180 degrees.\n");
            continue;
        }
        rotate_90();
        if(isequal()) {
            printf("was reflected vertically and rotated 270 degrees.\n");
            continue;
        }
        printf("was improperly transformed.\n");
    }
}
