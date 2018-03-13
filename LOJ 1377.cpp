#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ff first
#define sc second
vector< pair<int,int> >tp;
int visited[3][209][209];
//map< pair<int,int>, int >mp;
int n,m;
vector<string>v;
int ax[]= {0,0,-1,1};
int ay[]= {1,-1,0,0};
//pair<int,int> par[209][209];
bool cango(int x,int y)
{
    return x<n and y<m and x>-1 and y>-1;
}

void bfs(int x,int y,int mark)
{
    queue<int>q;
    q.push(x);
    q.push(y);
    visited[mark][x][y]=0;
    while(q.size())
    {
        int tx=q.front();
        q.pop();
        int ty=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int px=tx+ax[i];
            int py=ty+ay[i];
            if(cango(px,py) and visited[mark][px][py]==-1 and v[px][py]!='#')
            {
                visited[mark][px][py]=visited[mark][tx][ty]+1;
                q.push(px);
                q.push(py);
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
    for(int _t=1; _t<=test; _t++)
    {
        memset(visited,-1,sizeof(visited));
        //mp.clear();
        tp.clear();
        v.clear();
        cin>>n>>m;
        int stx,sty;
        int enx,eny;
        string s;
        for(int i=0; i<n; i++)
        {
            cin>>s;
            // cout<<s<<endl;
            v.push_back(s);
            for(int j=0; j<m; j++)
            {
                if(s[j]=='P')
                {
                    stx=i;
                    sty=j;
                }
                if(s[j]=='D')
                {
                    enx=i;
                    eny=j;
                }
                if(s[j]=='*')
                {
                    tp.push_back(make_pair(i,j));
                    //mp[make_pair(i,j)]=1;
                }
            }
        }
        bfs(stx,sty,0);
        bfs(enx,eny,1);
        bool f=0,f1=0,f2=0;
        int ans=1000000000;
        int x=ans,y=ans,posx1,posx2,posy1,posy2;
        if(tp.size()>1)
        {
            for(int i=0; i<tp.size(); i++)
            {
                if(visited[1][tp[i].ff][tp[i].sc]<x and visited[1][tp[i].ff][tp[i].sc]!=-1)
                {
                    f1=1;
                    posx1=tp[i].ff;
                    posy1=tp[i].sc;
                    x=visited[1][tp[i].ff][tp[i].sc];
                }
            }
            for(int i=0; i<tp.size(); i++)
            {
                if(visited[0][tp[i].ff][tp[i].sc]!=-1 and visited[0][tp[i].ff][tp[i].sc]<y and !(posx1==tp[i].ff and posy1==tp[i].sc))
                {
                    y=visited[0][tp[i].ff][tp[i].sc];
                    posx2=tp[i].ff;
                    posy2=tp[i].sc;
                    f2=1;
                }
            }
            if(!f2)
            {
                for(int i=0; i<tp.size(); i++)
                {
                    if(visited[0][tp[i].ff][tp[i].sc]!=-1 and visited[0][tp[i].ff][tp[i].sc]<y)
                    {
                        y=visited[0][tp[i].ff][tp[i].sc];
                        posx2=tp[i].ff;
                        posy2=tp[i].sc;
                        f2=1;
                    }
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(v[i][j]=='*')
                {
                    v[i][j]='#';
                }
            }
        }
        if(f1 and f2)
        {
            f=1;
            ans=x+y;
            if(posx1==posx2 and posy1==posy2)
                ans+=2;
            else
                ans+=1;
        }
        bfs(stx,sty,2);
        if(visited[2][enx][eny]!=-1)
        {
            f=1;
            if(f1 and f2)
            {
                ans=min(ans,visited[2][enx][eny]);
            }
            else
                ans=visited[2][enx][eny];

        }
        cout<<"Case "<<_t<<": ";
        if(f)
            cout<<ans<<endl;
        else
            cout<<"impossible"<<endl;
    }
    return 0;
}
