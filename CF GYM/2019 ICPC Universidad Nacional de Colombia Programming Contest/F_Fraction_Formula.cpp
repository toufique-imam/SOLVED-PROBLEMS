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
#define fbo find_by_order // k th index
#define ook order_of_key // strictly smaller than k
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define lead_zero(x) __builtin_clzll(x)
#define trail_zero(x) __builtin_ctzll(x)
#define total_1s(x) __builtin_popcountll(x)
#define first_1(x) __builtin_ffsll(x)
#define log2_(x) __builtin_clz(1) - __builtin_clz(x)
#define isLeap(x) ((x % 400 == 0) || (x % 100 ? x % 4 == 0 : false))
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
stack<char>stc;
stack<pll>st;
bool isdigit(char c) {
    return c>='0' && c<='9';
}
void work(char c,bool neg=0) {
    pll x,y;
    if(st.empty()) {
        y= {0,1};
    } else {
        y=st.top();
        st.pop();
    }
    if(st.empty()) {
        st.push(y);
        return;
    } else {
        x=st.top();
        st.pop();
        if(neg)
            x.ff=-x.ff;
        ll lc=LCM(y.ss,x.ss);
        pll z;
        ll x1=(lc/x.ss)*x.ff,x2=(lc/y.ss)*y.ff;
        z.ss=lc;
        if(c=='+')
            z.ff=x1+x2;
        else
            z.ff=x1-x2;
        ll gc=abs(__gcd(z.ss,z.ff));
        if(gc) {
            z.ss/=gc;
            z.ff/=gc;
        }
        st.push(z);
    }
}
void process(string s) {
    s="("+s+")";
    char c,xx;
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='(') {
            stc.push('(');
        } else if(s[i]==')') {
            while(1) {
                c=stc.top();
                stc.pop();
                if(c=='(')
                    break;
                char tmp=stc.top();
                if(tmp=='-') {
                    work(c,1);
                    stc.pop();
                    stc.push('+');
                } else {
                    work(c);
                }
            }
        } else if(isdigit(s[i])) {
            int j=i;
            ll x=0,y=0;
            while(isdigit(s[j])) {
                x=x*10+s[j]-'0';
                j++;
            }
            j++;
            while(isdigit(s[j])) {
                y=y*10+s[j]-'0';
                j++;
            }
            ll gc=abs(__gcd(x,y));
            x/=gc;
            y/=gc;
            st.push(MP(x,y));
            i=j-1;
        } else if(s[i]=='+') {
            stc.push(s[i]);
        } else if(s[i]=='-') {
            stc.push(s[i]);
        }
    }
}
int main() {
    string s;
    while(cin>>s){
        while(st.empty()==false)st.pop();
        while(stc.empty()==false)stc.pop();
        process(s);
        if(st.top().ss<0){
            st.top().ss=-1ll*st.top().ss;
            st.top().ff=-1ll*st.top().ff;
        }
        ll gc=abs(__gcd(st.top().ff,st.top().ss));
        printf("%lld/%lld\n",st.top().ff/gc,st.top().ss/gc);
        st.pop();
    }
}
