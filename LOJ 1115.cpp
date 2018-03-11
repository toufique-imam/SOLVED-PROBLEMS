#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<string>v;
int n,m;
int visited[60][60];
int ax[]={1,-1,0,0};
int ay[]={0,0,-1,1};
bool cango(int x,int y)
{
    return x<n and y<m and x>-1 and y>-1;
}

void dfs(int x,int y,char base,int cas)
{
    visited[x][y]=cas;
    for(int i=0;i<4;i++)
    {
        int px=x+ax[i];
        int py=y+ay[i];
        if(cango(px,py) and v[px][py]!=base and visited[px][py]!=cas)
            dfs(px,py,base,cas);
    }
}




int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    for(int _t=1; _t<=test; _t++)
    {
        v.clear();
        memset(visited,0,sizeof visited);
        cin>>n>>m;
        string s;
        for(int i=0; i<n; i++)
        {
            cin>>s;
            v.push_back(s);
        }
        for(int i=0;i<26;i++)
        {
            memset(visited,0,sizeof(visited));
            char base='A'+i;
            for(int j=0;j<m;j++)
            {
                if(visited[0][j]==0 and v[0][j]!=base)
                {
                    dfs(0,j,base,1);
                }
                if(visited[n-1][j]==0 and v[n-1][j]!=base)
                {
                    dfs(n-1,j,base,1);
                }
            }
            for(int k=0;k<n;k++)
            {
                if(visited[k][0]==0 and v[k][0]!=base)
                    dfs(k,0,base,1);
                if(visited[k][m-1]==0 and v[k][m-1]!=base)
                    dfs(k,m-1,base,1);
            }
            for(int j=0;j<n;j++)
                for(int k=0;k<m;k++)
                    if(visited[j][k]==0)
                        v[j][k]=base;
        }
        cout<<"Case "<<_t<<":"<<endl;
        for(int i=0;i<n;i++)
            cout<<v[i]<<endl;
    }
}

