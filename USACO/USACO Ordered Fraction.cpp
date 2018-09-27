/*
ID: sabertooth
LANG: C++11
TASK: frac1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<double,bool>mp;
int X(string s)
{
    int ans=0;
    for(int i=0; i<(int)s.size(); i++)
    {
        if(s[i]=='/')
            break;
        ans=ans*10+(s[i]-'0');
    }
    return ans;
}
int Y(string s)
{
    bool f=0;
    int ans=0;
    for(int i=0; i<(int)s.size(); i++)
    {
        if(f)
            ans=ans*10+s[i]-'0';
        if(s[i]=='/')
            f=1;
    }
    return ans;
}
bool comp(string s1,string s2)
{
    double x=X(s1)*1.0/Y(s1)*1.0;
    double y=X(s2)*1.0/Y(s2)*1.0;
    return x<y;
}
string toString(int n)
{
    string s;
    while(n>0)
    {
        s+=(n%10)+'0';
        n/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}
int main()
{
    freopen("frac1.in","r",stdin);
    freopen("frac1.out","w",stdout);
    vector<string>v;
    int n;
    scanf("%d",&n);
    v.push_back("0/1");
    v.push_back("1/1");
    mp[0.0]=1;
    mp[1.0]=1;
    string s;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(!mp[j*1.0/i*1.0])
            {
                s="";
                mp[j*1.0/i*1.0]=1;
                s+=toString(j);
                s+='/';
                s+=toString(i);
                v.push_back(s);
            }
        }
    }
    sort(v.begin(),v.end(),comp);
    for(int i=0; i<(int)v.size(); i++)
        cout<<v[i]<<endl;
}
