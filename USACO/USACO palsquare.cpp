/*ID: sabertooth
LANG: C++11
TASK: palsquare
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool ispalindrome(string a)
{
    string b=a;
    reverse(a.begin(),a.end());
    return a==b;
}

string toString(int n)
{
    string s;
    while(n)
    {
        s+=(n%10)+'0';
        n/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}
string change(ll n,int base)
{
    string s;
    while(n)
    {
//        s+=(n%base)+'0';
        int x=n%base;
        if(x>=10)
        {
            x-=10;
            x+='A';
            s+=x;
        }
        else
            s+=x+'0';
        n/=base;
    }
    reverse(s.begin(),s.end());
    return s;
}

int main()
{
    ofstream fout("palsquare.out");
    ifstream fin("palsquare.in");
    int b;
    fin>>b;
    for(ll i=1;i<=300;i++)
    {
        string x=change(i*i,b);
        if(ispalindrome(x))
        {
            string g=change(i,b);
            fout<<g<<" "<<x<<endl;
        }
    }
}
