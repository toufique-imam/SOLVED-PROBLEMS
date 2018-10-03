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
bool is_palindrome(string s)
{
    string t=s;
    reverse(all(s));
    return s==t;
}
int main()
{
    set<string>st;
    string s,tmp;
    while(cin>>s)
    {
        st.clear();
        int cnt=0;
        for(int l=1; l<=(int)s.size(); l++)
        {
            for(int i=0; i+l<=(int)s.size(); i++)
            {
                tmp="";
                for(int j=i; j<i+l; j++)
                {
                    tmp+=s[j];
                }

                //cout<<"Bug :"<<tmp<<endl;
                if(is_palindrome(tmp))
                {
                    st.insert(tmp);
                }
            }
        }
        cout<<"The string '"<<s<<" contains "<<st.size()<<" palindromes."<<endl;
    }
}
