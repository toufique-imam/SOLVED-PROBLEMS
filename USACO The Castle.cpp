/*
ID: sabertooth
LANG: C++11
TASK: castle
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class node
{
public:
    int on[4];
};
node graph[60][60];
int n,m;
void process(int sum,int x,int y)
{
    if(sum==0)
        graph[x][y]= {0,0,0,0};
    if(sum==1)
        graph[x][y]= {1,0,0,0};
    if(sum==2)
        graph[x][y]= {0,1,0,0};
    if(sum==3)
        graph[x][y]= {1,1,0,0};
    if(sum==4)
        graph[x][y]= {0,0,1,0};
    if(sum==5)
        graph[x][y]= {1,0,1,0};
    if(sum==6)
        graph[x][y]= {0,1,1,0};
    if(sum==7)
        graph[x][y]= {1,1,1,0};
    if(sum==8)
        graph[x][y]= {0,0,0,1};
    if(sum==9)
        graph[x][y]= {1,0,0,1};
    if(sum==10)
        graph[x][y]= {0,1,0,1};
    if(sum==11)
        graph[x][y]= {1,1,0,1};
    if(sum==12)
        graph[x][y]= {0,0,1,1};
    if(sum==13)
        graph[x][y]= {1,0,1,1};
    if(sum==14)
        graph[x][y]= {0,1,1,1};
    if(sum==15)
        graph[x][y]= {1,1,1,1};
}
int visited[60][60];
int SOC[400];
//w n e s
int ax[]= {0,-1,0,1};
int ay[]= {-1,0,1,0};
int max_un,wallx,wally,max_br;
char direc;
bool cango(int x,int y)
{
    return x>-1 and y>-1 and x<n and y<m;
}
char get_direc(int xx)
{
    if(xx==0) return 'W';
    else if(xx==1) return 'N';
    else if(xx==2)return 'E';
    else if(xx==3)return 'S';
}
void assign_(int maxi,int posx,int posy,int dir)
{
    max_br=maxi;
    wallx=posx;
    wally=posy;
    direc=get_direc(dir);
}
void get_break()
{
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            for(int k=0;k<4;k++)
            {
                int px=i+ax[k];
                int py=j+ay[k];
                if(cango(px,py) and visited[px][py]!=visited[i][j])
                {
                    int x=visited[px][py];
                    int y=visited[i][j];
                    if(SOC[x]+SOC[y]>max_br)
                        assign_(SOC[x]+SOC[y],i+1,j+1,k);
                    else if(SOC[x]+SOC[y]==max_br and (wally-1>j or (wally-1==j and wallx-1<i) or (wally-1==j and wallx-1==i and get_direc(k)=='N' and direc=='E')))
                        assign_(SOC[x]+SOC[y],i+1,j+1,k);
                }
            }
}
int dfs(int x,int y,int comp)
{
    int maxi=1;
    visited[x][y]=comp;
    for(int i=0; i<4; i++)
    {
        int px=ax[i]+x;
        int py=ay[i]+y;
        if(cango(px,py) and !graph[x][y].on[i] and visited[px][py]==-1)
            maxi+=dfs(px,py,comp);
    }
    max_un=max(max_un,maxi);
    return maxi;
}
int main()
{
    int x;
    freopen("castle.in","r",stdin);
    freopen("castle.out","w",stdout);
    scanf("%d %d",&m,&n);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            scanf("%d",&x);
            process(x,i,j);
        }
    direc=-1;
    memset(visited,-1,sizeof visited);
    int comp=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(visited[i][j]==-1)
            {
                comp++;
                SOC[comp]=dfs(i,j,comp);
            }
    get_break();
    cout<<comp<<endl<<max_un<<endl<<max_br<<endl<<wallx<<" "<<wally<<" "<<direc<<endl;
    return 0;
}
