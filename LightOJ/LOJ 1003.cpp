#include<bits/stdc++.h>
using namespace std;
const int arrsz=10000;
map<string,int>mp;
vector<int>v[arrsz+9];
bool visited[arrsz+9];
int indegree[arrsz+9];
void clean()
{
    memset(indegree,0,sizeof indegree);
    memset(visited,0,sizeof visited);
    mp.clear();
    for(int i=0; i<=arrsz; i++)
        v[i].clear();
}

void bfs(int x)
{
    queue<int>q;
    for(int i=1; i<x; i++)
        if(indegree[i]==0)
        {
            q.push(i);
            visited[i]=1;
        }
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(int i=0; i<v[t].size(); i++)
        {
            if(!visited[v[t][i]])
            {
                indegree[v[t][i]]--;
                if(indegree[v[t][i]]==0)
                {
                    visited[v[t][i]]=1;
                    q.push(v[t][i]);
                }
            }
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    for(int T=1; T<=test; T++)
    {
        clean();
        int n;
        cin>>n;
        string a,b;
        int idx=1;
        for(int i=0; i<n; i++)
        {
            cin>>a>>b;
            if(mp[a]==0)
            {
                mp[a]=idx++;
            }
            if(mp[b]==0)
                mp[b]=idx++;
            v[mp[a]].push_back(mp[b]);
            indegree[mp[b]]++;
        }
        bfs(idx);
        bool f=1;
        for(int i=1; i<idx; i++)
        {
            if(!visited[i])
            {
                f=0;
                break;
            }
        }
        cout<<"Case "<<T<<": ";
        if(f)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}
