#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii             pair<int,int>
#define pll             pair<ll,ll>
#define ff              first
#define ss              second
#define read            freopen("in.txt","r",stdin);
#define write           freopen("out.txt","w",stdout);
#define TEST            int test;scanf("%d",&test);for(int T=1;T<=test;T++)
#define lead_zero(x)    __builtin_clzll(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
#define all(v)          v.begin(),v.end()
#define reunique(v)     v.resize(std::unique(all(v)) - v.begin())
#define PQ              priority_queue< ll,vector<ll>,greater<ll> >pq;
#define PQii            priority_queue< pii,vector< pii >,greater< pii > >pq;
#define PQll            priority_queue< pll,vector< pll >,greater< pll > >pq;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
int myLog2(int x)
{
    return __builtin_clz(1) - __builtin_clz(x);
}
map<char,int>mp;
int greek_to_arabic(string s)
{
    int res=0;
    for(int i=0;i<(int)s.size();i++)
    {
        if(i+1<(int)s.size() and mp[s[i]]<mp[s[i+1]])
        {
            res+=mp[s[i+1]]-mp[s[i]];
            i++;
        }
        else
            res+=mp[s[i]];
    }
    return res;
}
string arabic_to_greek(int x)
{
    if(x<10)
    {
        if(x==0)return "";
        else if(x==1)return "I";
        else if(x==2) return "II";
        else if(x==3) return "III";
        else if(x==4) return "IV";
        else if(x==5) return "V";
        else if(x==6) return "VI";
        else if(x==7) return "VII";
        else if(x==8) return "VIII";
        else if(x==9) return "IX";
    }
    else if(x<100)
    {
        if(x/10==1)return "X"+arabic_to_greek(x%10);
        else if(x/10==2)return "XX"+arabic_to_greek(x%10);
        else if(x/10==3)return "XXX"+arabic_to_greek(x%10);
        else if(x/10==4)return "XL"+arabic_to_greek(x%10);
        else if(x/10==5)return "L"+arabic_to_greek(x%10);
        else if(x/10==6)return "LX"+arabic_to_greek(x%10);
        else if(x/10==7)return "LXX"+arabic_to_greek(x%10);
        else if(x/10==8)return "LXXX"+arabic_to_greek(x%10);
        else if(x/10==9)return "XC"+arabic_to_greek(x%10);
    }
    else if(x<1000)
    {
        if(x/100==1)return "C"+arabic_to_greek(x%100);
        else if(x/100==2)return "CC"+arabic_to_greek(x%100);
        else if(x/100==3)return "CCC"+arabic_to_greek(x%100);
        else if(x/100==4)return "CD"+arabic_to_greek(x%100);
        else if(x/100==5)return "D"+arabic_to_greek(x%100);
        else if(x/100==6)return "DC"+arabic_to_greek(x%100);
        else if(x/100==7)return "DCC"+arabic_to_greek(x%100);
        else if(x/100==8)return "DCCC"+arabic_to_greek(x%100);
        else if(x/100==9)return "CM"+arabic_to_greek(x%100);
    }
    else if(x>=1000)
    {
        return "M"+arabic_to_greek(((x/1000)-1)*1000+x%1000);
    }
    else
        return "";
}
int main()
{
    mp['I']=1;
    mp['V']=5;
    mp['X']=10;
    mp['L']=50;
    mp['C']=100;
    mp['D']=500;
    mp['M']=1000;
    string s;
    while(cin>>s)
    {
        if(isalpha(s[0]))
            cout<<greek_to_arabic(s)<<endl;
        else{
            stringstream ss(s);
            int x;
            ss>>x;
            cout<<arabic_to_greek(x)<<endl;
        }
    }
}
