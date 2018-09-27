/*ID: sabertooth
LANG: C++11
TASK: namenum
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector< pair<ll,string> >v;
ifstream ccin("namenum.in");
ofstream ccout("namenum.out");
ifstream fin("dict.txt");
void process(string s)
{
    ll x;
    ll ss=0;
    int len=(int)s.size();
    for(int i=0; i<len; i++)
    {
        if(s[i]=='A' or s[i]=='B' or s[i]=='C')ss=ss*10+2;
        else if(s[i]=='D' or s[i]=='E' or s[i]=='F')ss=ss*10+3;
        else if(s[i]=='G' or s[i]=='H' or s[i]=='I')ss=ss*10+4;
        else if(s[i]=='J' or s[i]=='K' or s[i]=='L')ss=ss*10+5;
        else if(s[i]=='M' or s[i]=='N' or s[i]=='O')ss=ss*10+6;
        else if(s[i]=='P' or s[i]=='R' or s[i]=='S')ss=ss*10+7;
        else if(s[i]=='T' or s[i]=='U' or s[i]=='V')ss=ss*10+8;
        else if(s[i]=='W' or s[i]=='X' or s[i]=='Y')ss=ss*10+9;
    }
    v.push_back(make_pair(ss,s));
}
void init()
{
    string s;
    while(fin>>s)
    {
        process(s);
    }
    sort(v.begin(),v.end());
}
ll bin_l(ll n)
{
    ll l=0,h=4616,mid,ans=-1;
    while(h>=l)
    {
        mid=(h+l)/2;
        if(v[mid].first==n)
        {
            h=mid-1;
            ans=mid;
        }
        else if(v[mid].first>n)
            h=mid-1;
        else
            l=mid+1;
    }
    return ans;
}

ll bin_h(ll n)
{
    ll l=0,h=4616,mid,ans=-1;
    while(h>=l)
    {
        mid=(h+l)/2;
        if(v[mid].first==n)
        {
            l=mid+1;
            ans=mid;
        }
        else if(v[mid].first>n)
            h=mid-1;
        else
            l=mid+1;
    }
    return ans;
}
int main()
{
    ll n;
    ccin>>n;
    init();
    ll pos1=bin_l(n);
    ll pos2=bin_h(n);
    if(pos1==-1 or pos2==-1)
        ccout<<"NONE"<<endl;
    else
        for(int i=pos1; i<=pos2; i++)
            ccout<<v[i].second<<endl;
}
