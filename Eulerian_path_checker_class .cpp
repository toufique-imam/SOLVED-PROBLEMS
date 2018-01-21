#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class graph
{
    int node;
    vector< vector<int> >v;
public:
    graph(int x)
    {
        node=x;
        v=vector< vector<int> >(x+9);
    }
    void addpath(int q,int w);
    int iscycle();
    int isconnected();
    void dfs(int x,vector<bool>&visited);
};

void graph::addpath(int q,int w)
{
    v[q].push_back(w);
    v[w].push_back(q);
}

void graph::dfs(int edge,vector<bool>&visited)
{
    visited[edge]=1;
    for(int i=0; i<v[edge].size(); i++)
    {
        if(visited[v[edge][i]]==0)
        {
            dfs(v[edge][i],visited);
        }
    }
}

int graph::isconnected()
{
    vector<bool>visited(node+9,0);
    int i;
    for(i=0;i<node;i++)
    {
        if(v[i].size()!=0)
            break;
    }
    if(i==node)
        return 1;
    dfs(i,visited);
    for(i=0;i<node;i++)
    {
        if(!visited[i] && v[i].size()>0)
            return 0;
    }
    return 1;
}

int graph::iscycle()
{
    if(isconnected()==0)
        return 0;
    int odd=0;
    for(int i=0;i<node;i++)
    {
        if(v[i].size() & 1)
            odd++;
    }
    if(odd>2)
        return 0;
    return odd? 1:2;
}
