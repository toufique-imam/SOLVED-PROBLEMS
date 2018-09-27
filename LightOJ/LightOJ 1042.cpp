#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll bin_dec(string s)
{
    reverse(s.begin(),s.end());
    ll x=0;
    ll base=1;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='1')
            x=x+base;
        base*=2;
    }
    return x;
}

string dec_bin(ll n)
{
    string ans;
    while(n>0)
    {
        ans+=((n%2)+'0');
        n/=2;
    }
    for(; ans.length()<=30;)
        ans+='0';
    reverse(ans.begin(),ans.end());
    return ans;
}
string sorrt(string s,int x)
{
    for(int i=x;i<s.length();i++)
        for(int j=i+1;j<s.length();j++)
            if(s[i]>s[j])
                swap(s[i],s[j]);
    return s;
}
string nextPermutation(string s)
{
    for(int i=s.length()-1;i>0;i--)
    {
        if(s[i]>s[i-1]){
            swap(s[i],s[i-1]);
            s=sorrt(s,i+1);
            break;
        }
    }
    return s;
}

int main()
{
    int test;
    scanf("%d",&test);
    for(int i=1; i<=test; i++)
    {
        ll n;
        scanf("%lld",&n);
        string x=dec_bin(n);
        x=nextPermutation(x);
        printf("Case %d: %lld\n",i,bin_dec(x));
    }
}
