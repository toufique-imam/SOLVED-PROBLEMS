#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int ax[]= {0,0,1,-1};
int ay[]= {1,-1,0,0};
vector<string>v;
char land;
bool visited[30][30];
int sum;
bool cango(int x,int y)
{
    return x>-1 and y>-1 and x<n and y<m;
}
void dfs(int x,int y)
{
    sum++;
    visited[x][y]=1;
    for(int i=0; i<4; i++)
    {
        int px=ax[i]+x;
        int py=(ay[i]+y);
        if(py==-1){
            py=m-1;
        }
        if(py==m){
            py=0;
        }
        if(cango(px,py) and !visited[px][py] and v[px][py]==land)
        {
            dfs(px,py);
        }
    }
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n>>m and n and m)
    {
        memset(visited,0,sizeof visited);
        v.clear();
        string s;
        for(int i=0; i<n; i++)
        {
            cin>>s;
            v.push_back(s);
        }
        int x,y;
        cin>>x>>y;
        land=v[x][y];
        dfs(x,y);
        sum=0;
        int ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                sum=0;
                if(!visited[i][j] and v[i][j]==land)
                {
                    dfs(i,j);
                    ans=max(ans,sum);
                }
            }
        }
        cout<<ans<<endl;
    }
}
