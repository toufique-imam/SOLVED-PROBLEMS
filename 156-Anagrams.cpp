#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//vector<string>vs;
bool check(string a,string b)
{
    string t1,t2;
    ll i,j;
    if(a.length()!=b.length())
        return false;
    for(i=0; i<a.length(); i++)
    {
        t1+=tolower(a[i]);
        t2+=tolower(b[i]);
    }
    sort(t1.begin(),t1.end());
    sort(t2.begin(),t2.end());
    for(i=0; i<a.length(); i++)
    {
        if(t1[i]!=t2[i])
            return false;
    }
    return true;
}

int main()
{
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    string st;
    vector<string>vs;
    while(cin>>st && st!="#")
        vs.push_back(st);
    ll i,j;
    set<string>s;
    set<string>::iterator itr;
    for(i=0; i<vs.size(); i++)
    {
        bool f=0;
        for(j=0; j<vs.size(); j++)
        {
            if(j!=i && check(vs[i],vs[j]))
            {
                f=1;
                break;
            }
        }
        if(!f)
            s.insert(vs[i]);
    }
    for(itr=s.begin();itr!=s.end();itr++)
        cout<<*itr<<endl;
}
