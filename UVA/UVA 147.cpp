#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void getval(string s,ll &a,ll &b)
{
    bool f=0;
    for(ll i=0;i<s.length();i++)
    {
        if(s[i]=='.')
        {
            f=1;
            continue;
        }
        if(f)
            b=b*10+(s[i]-'0');
        else
            a=a*10+(s[i]-'0');
    }
}
int main()
{
    ll ara[300*100+9];
    memset(ara,0,sizeof(ara));
    ll a,b;
    ll coins[]={100*100,50*100,20*100,10*100,5*100,2*100,1*100,50,20,10,5};
    ara[0]=1;
    for(ll i=0;i<11;i++)
    {
        for(ll j=coins[i];j<=300*100;j++)
        {
            ara[j]+=ara[j-coins[i]];
        }
    }
    string s;
    while(cin>>s)
    {
        ll a=0,b=0;
        getval(s,a,b);
        if(a==0 && b==0)
            break;
        ll t=a*100+b;
        cout<<setw(6)<<right<<s<<setw(17)<<right<<ara[t]<<endl;
    }
}
