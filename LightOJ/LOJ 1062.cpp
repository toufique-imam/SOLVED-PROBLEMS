/*
ID: sabertooth
LANG: C++11
TASK:
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define eps             1e-9
#define inf             0x3f3f3f3f
#define INF             2e18
#define PI              acos(-1.0)
#define ff              first
#define ss              second
#define all(v)          v.begin(),v.end()
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(min(a,b),min(c,d))
#define max4(a,b,c,d)   max(max(a,b),max(c,d))
#define max5(a,b,c,d,e) max(max3(a,b,c),max(d,e))
#define min5(a,b,c,d,e) min(min3(a,b,c),min(d,e))
#define Iterator(a)     __typeof__(a.begin())
#define read            freopen("in.txt","r",stdin);
#define write           freopen("out.txt","w",stdout);
#define TEST            int test;scanf("%d",&test);for(int T=1;T<=test;T++)
#define PCAS            printf("Case %d:",T);
#define lead_zero(x)    __builtin_clzll(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
#define reunique(v)     v.resize(std::unique(all(v)) - v.begin())
#define MP              make_pair
#define PB              push_back
#define EB              emplace_back
#define segtree         int mid=(st+en)/2,lt=node*2,rg=node*2+1
#define MERGE(v1,v2,v)  merge(all(v1),all(v2),back_inserter(v))
//n! ~ sqrt(2*pi*n)*n^n*e^-n

int myLog2(int x)
{
    return __builtin_clz(1) - __builtin_clz(x);
}
bool is_vowel(char x)
{
    x=tolower(x);
    return (x=='a' || x=='e' || x=='i' || x=='o' || x=='u');
}
//1/X+1/Y=1/C
int32_t main()
{
    TEST
    {
        double x,y,c;
        scanf("%lf %lf %lf",&x,&y,&c);
        if(x>y)swap(x,y);
        double lo=0.0,hi=y;
        double mid,ans=-1;
        cout<<fixed<<setprecision(7);
        while(hi-lo>=1e-9)
        {
            mid=(lo+hi)/2.0;
            double X=sqrt(x*x-mid*mid);
            double Y=sqrt(y*y-mid*mid);
            //if(X<Y)swap(X,Y);
            double dif=c*(X+Y)-X*Y;
           // cout<<"debug "<<dif<<endl;
            if(dif<=1e-8){
                ans=mid;
                lo=mid;
            }
            else{
                hi=mid;
            }
        }
        //assert(ans!=-1);
        printf("Case %d: %0.8f\n",T,ans);
    }
}
