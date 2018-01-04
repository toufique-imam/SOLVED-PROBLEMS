#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define read(s)     freopen(#s,"r",stdin)
#define write(s)    freopen(#s,"w",stdout)
vector<string>v;

bool one_char_dif(string s1,string s2)
{
    ll cnt=0;
    for(ll i=0; i<s1.length(); i++)
    {
        if(cnt>1)
            return 0;
        if(s1[i]!=s2[i])
            cnt++;
    }
    if(cnt==1)
        return 1;
    return 0;
}

ll bfs(string s1,string s2)
{
    map<string,ll>level;
    queue<string>q;
    string t1;
    q.push(s1);
    level[s1]=0;
    while(q.empty()==0)
    {
        t1=q.front();
        if(t1==s2)
            break;
        q.pop();
        for(ll i=0; i<v.size(); i++)
        {
            if(v[i].length()==t1.length() && one_char_dif(t1,v[i]) && level[v[i]]==0)
            {
                q.push(v[i]);
                level[v[i]]=level[t1]+1;
            }
        }
    }
    return level[s2];
}

int main()
{
    //read(input.txt);
    //write(output.txt);
    ll test;
    size_t x;
    scanf("%lld",&test);
    getchar();
    for(ll t=0;t<test;t++)
    {
        string s1,s2,s;
        while(1)
        {
            cin>>s1;
            if(s1=="*")
                break;
            v.pb(s1);
        }
        getchar();
        while(1)
        {
            getline(cin,s);
            if(s.empty())
                break;
            x=s.find(" ");
            s1=s.substr(0,x);
            s2=s.substr(x+1);
            cout<<s1<<" "<<s2<<" "<<bfs(s1,s2)<<endl;
        }
        if(t!=test-1)
            cout<<endl;
    }
}
