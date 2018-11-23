#include<bits/stdc++.h>
using namespace std;


/*--Policy Based Data Structure--*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_set_rev = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fbo         find_by_order //index wise op
#define ook         order_of_key  //number of elements less than key


typedef long long ll;
typedef unsigned long long ull;
#define PI              acos(-1.0)
#define eps             1e-6
#define inf             0x3f3f3f3f

#define sf(x)           scanf("%I64d",&x)
#define sff(x,y)        scanf("%I64d %I64d",&x,&y)
#define sl(x)           scanf("%lld",&x)
#define sll(x,y)        scanf("%lld %lld",&x,&y)

#define max_ull         18446744073709551615
#define max_ll          9223372036854775807

#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(min(a,b),min(c,d))
#define max4(a,b,c,d)   max(max(a,b),max(c,d))
#define max5(a,b,c,d,e) max(max3(a,b,c),max(d,e))
#define min5(a,b,c,d,e) min(min3(a,b,c),min(d,e))

#define segtree         lt=2*par,rg=2*par+1,mid=(st+en)/2

#define lead_zero(x)    __builtin_clzll(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
#define first_1(x)      __builtin_ffs(x)
#define log2_(x)        __builtin_clz(1) - __builtin_clz(x);
#define isPowerOfTwo(x) (x!=0 && (x&(x-1))==0)
#define isLeap(x)       ((x%400==0) || (x%100?x%4==0:false))

#define set(N,cur)      N=(N|(1<<cur))
#define reset(N,cur)    N=(N&(~(1<<cur)))
#define check(N,cur)    ((N&(1<<cur))==0)

#define TEST            int test;scanf("%d",&test);for(int T=1;T<=test;T++)
#define rep(i,begin,end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

/*-----STL------*/
#define fast            ios_base::sync_with_stdio(0),cin.tie(0)
#define ii              int,int
#define all(v)          v.begin(),v.end()
#define reunique(v)     v.resize(std::unique(all(v)) - v.begin())
#define pii             pair<ii>
#define ff              first
#define ss              second
#define Iterator(a)     __typeof__(a.begin())
#define MERGE(v1,v2,v)  merge(all(v1),all(v2),back_inserter(v))
#define MP              make_pair
#define PB              push_back
#define EB              emplace_back

template<typename T>
using dijkstra=priority_queue<T,vector<T>,greater<T> >;

/*____Debug____*/
#define read            freopen("in.txt","r",stdin)
#define write           freopen("out.txt","w",stdout)

#define what_is(x)      cerr << #x << " is " << x << endl;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

/* Direction arrays */
/* int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};   */// 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction
/* int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};*/
typedef pair<double,double> point;
double distance_(point A,point B)
{
    return (A.ff-B.ff)*(A.ff-B.ff)+(A.ss-B.ss)*(A.ss-B.ss);
}

int n;
pair<int,point>ara[100];
double area_traingle(point A,point B,point C)
{
    return fabs((C.ss-A.ss)*(B.ff-A.ff)-(B.ss-A.ss)*(C.ff-A.ff));
}
class rectangle
{
public:
    point a,b,c,d;
    rectangle() {}
    rectangle(point a,point c)
    {
        this->a=a;
        this->c=c;
        this->b=MP(c.ff,a.ss);
        this->d=MP(a.ff,c.ss);
    }
    friend bool intersect(rectangle A,rectangle B,rectangle &C)
    {
        double leftX=max(A.a.ff,B.a.ff);
        double rightX=min(A.b.ff,B.b.ff);
        double topY=max(A.a.ss,B.a.ss);
        double bottomY=min(A.c.ss,B.c.ss);
        if(leftX<rightX and topY<bottomY)
        {
            C=rectangle(MP(leftX,topY),MP(rightX,bottomY));
            return true;
        }
        return false;
    }
    friend istream& operator>>(istream &sin,rectangle &x)
    {
        sin>>x.a.ff>>x.a.ss;
        sin>>x.c.ff>>x.c.ss;
        x.b=MP(x.c.ff,x.a.ss);
        x.d=MP(x.a.ff,x.c.ss);
        return sin;
    }
};
int main()
{
    bool f=0;
    TEST
    {
        if(f)puts("");
        f=1;
        rectangle A,B;
        cin>>A>>B;
        rectangle C;
        if(intersect(A,B,C))
        {
            cout<<C.a.ff<<" "<<C.a.ss<<" "<<C.c.ff<<" "<<C.c.ss<<endl;
        }
        else
        {
            cout<<"No Overlap"<<endl;
        }
    }
}
