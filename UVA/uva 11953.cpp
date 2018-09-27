#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<string>v;
bool visited[109][109];
int ax[]= {0,0,-1,1};
int ay[]= {1,-1,0,0};
bool cango(int x,int y)
{
    return x>-1 and y>-1 and x<n and y<n;
}
void dfs(int x,int y)
{
    visited[x][y]=1;
    for(int i=0; i<4; i++)
    {
        int px=ax[i]+x;
        int py=ay[i]+y;
        if(cango(px,py) and !visited[px][py] and v[px][py]!='.')
            dfs(px,py);
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
    int test;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>test;
    for(int  _t=1; _t<=test; _t++)
    {
        cin>>n;
        v.clear();
        memset(visited,0,sizeof visited);
        string s;
        for(int i=0; i<n; i++)
        {
            cin>>s;
            v.push_back(s);
        }
        int cnt=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(!visited[i][j] and v[i][j]=='x')
                {
                    dfs(i,j);
                    cnt++;
                }

        cout<<"Case "<<_t<<": "<<cnt<<endl;
    }
}
