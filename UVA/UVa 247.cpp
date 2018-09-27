#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;

unordered_map< string, vector<string> >mp;
unordered_map<string,int>dis;
unordered_map<string,int>low;
unordered_map<string,bool>instack;
stack<string>sss;
set<string>ans[30];
int ti,sc;

void clean()
{
    ti=sc=0;
    for(int i=0;i<30;i++)ans[i].clear();
    while(sss.size())sss.pop();
    mp.clear();
    dis.clear();
    low.clear();
    instack.clear();
}
void dfs(string s)
{
    sss.push(s);
    instack[s]=1;
    dis[s]=low[s]=++ti;
    for(auto i:mp[s])
    {
        if(dis[i]==0)
            dfs(i);
        if(dis[i] and instack[i])
        {
            low[s]=min(low[s],low[i]);
        }
    }
    if(low[s]==dis[s])
    {
        while(1)
        {
            string temp=sss.top();
            instack[temp]=0;
            sss.pop();
            ans[sc].insert(temp);
            if(temp==s)
                break;
        }
        sc++;
    }
}
int main()
{
    int n,m;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cas=1;
    bool f1=0;
    while(cin>>n>>m and n+m>0)
    {
        if(f1)
            cout<<endl;
        clean();
        string s1,s2;
        unordered_set<string>s;
        for(int i=0;i<m;i++)
        {
            cin>>s1>>s2;
            mp[s1].push_back(s2);
            s.insert(s1);
            s.insert(s2);
        }
        cout<<"Calling circles for data set "<<cas<<":"<<endl;
        for(auto i:s)
        {
            if(dis[i]==0)
            {
                dfs(i);
            }
        }
        for(int i=0;i<sc;i++)
        {
            bool f=0;
            for(auto j:ans[i])
            {
                if(f)
                    cout<<", ";
                cout<<j;
                f=1;
            }
            cout<<endl;
        }
        f1=1;
        cas++;
    }
}
