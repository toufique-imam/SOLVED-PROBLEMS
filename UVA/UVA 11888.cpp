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
typedef long long ll;
typedef unsigned long long ull;
#define fbo find_by_order
#define ook order_of_key
#define PI acos(-1.0)
#define eps 1e-10
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
#define trail_zero(x) __builtin_ctz(x)
#define total_1s(x) __builtin_popcount(x)
#define first_1(x) __builtin_ffs(x)
#define log2_(x) __builtin_clz(1) - __builtin_clz(x)
#define isLeap(x) ((x % 400 == 0) || (x % 100 ? x % 4 == 0 : false))
#define set(N, cur) N = (N | (1 << cur))
#define reset(N, cur) N = (N & (~(1 << cur)))
#define check(N, cur) ((N & (1 << cur)) == 0)
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
#define what_is(x) cerr << #x << " is " << x << endl;
#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
#define in_range(v, r, l) upper_bound(all(v), r) - lower_bound(all(v), l)
void err(istream_iterator<string> it) {
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
ll rdn(int y, int m, int d) {
    /* Rata Die day one is 0001-01-01 */
    if (m < 3)
        y--, m += 12;
    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}
/* Direction arrays */
/* int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1}; */                        // 4 Direction
/*int dx[] = {1,-1,0,0,1,1,-1,-1}, dy[] = {0,0,1,-1,1,-1,1,-1};     */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */            // Hexagonal Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */            // Hexagonal Direction
/* int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; */
#define MH 200009
#define Base1 10000019
#define Base2 10000079
#define MOD1 1000000007
#define MOD2 1000000009
ll B1[MH],B2[MH];
void init_hash() {
    B1[0]=B2[0]=1;
    for(int i=1; i<MH; i++) {
        B1[i]=(B1[i-1]*Base1)%MOD1;
        B2[i]=(B2[i-1]*Base2)%MOD2;
    }
}
struct Hash {
    pll *H;
    int *digit;
    int len;
    Hash() {
        H=new pll[MH];
        digit=new int[MH];
        len=0;
        H[0]=pll(0,0);
    }
    void clear() {
        len=0;
        H[0]=pll(0,0);
    }
    ~Hash(){
        delete(H);
        delete(digit);
    }
    void insert(char ch) {
        len++;
        digit[len]=ch-'a'+1;
        H[len].ff=(((H[len-1].ff*Base1)%MOD1)+digit[len])%MOD1;
        H[len].ss=(((H[len-1].ss*Base2)%MOD2)+digit[len])%MOD2;
    }
    pll substr(int l, int r) {
        if(l>len || r<1 || r<l)
            return pll(0,0);
        int sub_len=r-l+1;
        pll ans;
        ans.ff=(H[r].ff-((H[l-1].ff*B1[sub_len])%MOD1)+MOD1)%MOD1;
        ans.ss=(H[r].ss-((H[l-1].ss*B2[sub_len])%MOD2)+MOD2)%MOD2;
        return ans;
    }
    pll concate(pll h, int l, int r) {
        pll x=substr(l,r);
        int sub_len=r-l+1;
        h.ff=(((h.ff*B1[sub_len])%MOD1)+x.ff)%MOD1;
        h.ss=(((h.ss*B2[sub_len])%MOD2)+x.ss)%MOD2;
        return h;
    }
    bool operator==(const Hash& p) const {
        return len==p.len && H[len]==p.H[len];
    }
    pll & operator[](int index) {
        return H[index];
    }
};
void substr_(string s,int l,int r){
    l--;
    for(int i=l;i<r;i++){
        cout<<s[i];
    }
    cout<<endl;
}
int main() {
    init_hash();
    Hash *h1=new Hash();
    Hash *h2=new Hash();
    QUERY{
        string s;
        cin>>s;
        h1->clear();
        h2->clear();
        string t=s;
        reverse(all(t));
        int f=0;
        if(t==s)f=-1;
        int len=s.size();
        for(int i=0;i<len;i++){
            h1->insert(s[i]);
        }
        for(int i=len-1;i>-1;i--){
            h2->insert(s[i]);
        }
        for(int i=1;i<len;i++){
            int l1=i+1;
            int l2=len-i+1;
            int l3=l2-1;
            if(l3<1)break;
            if(l1>len)break;
            pll x1=h1->substr(1,i);
            pll x2=h1->substr(l1,len);
            pll y1=h2->substr(l2,len);
            pll y2=h2->substr(1,l3);
            //substr_(s,1,i);
            //substr_(s,l1,len);
            //substr_(t,l2,len);
            //substr_(t,1,l3);
            if(x1==y1 && x2==y2){
                f=1;
                break;
            }
        }
        if(f==0){
            puts("simple");
        }
        else if(f==-1){
            puts("palindrome");
        }
        else puts("alindrome");
    }
}
