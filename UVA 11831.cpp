/*
ID:sabertooth9
TASK:DCP-17: Tourist
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;
#define ll              long long
#define pb              push_back
#define read(s)         freopen(#s,"r",stdin)
#define write(s)        freopen(#s,"w",stdout)
#define lead_zero(x)    __builtin_clzll(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
#define mod             1000000007
#define all(v)          v.begin(),v.end()

int grid[109][109];

int main ()
{
    int row,col,com;
    while(scanf("%d %d %d",&row,&col,&com)==3 && row && col && com)
    {
        getchar();
        char x;
        int startx,starty;
        string s;
        char dirnow;
        memset(grid,-1,sizeof(grid));
        for(int i=0; i<row; i++)
        {
            cin>>s;
            for(int j=0; j<col; j++)
            {
                if(s[j]=='*')
                    grid[i][j]=1;
                else if(s[j]=='#')
                    grid[i][j]=0;
                else if(isalpha(s[j]))
                {
                    dirnow=s[j];
                    startx=i;
                    starty=j;
                }
            }
        }
        cin>>s;
        int cnt=0;
        for(int i=0; i<com; i++)
        {
            if(s[i]=='D')
            {
                if(dirnow=='N')
                {
                    dirnow='L';
                }
                else if(dirnow=='S')
                {
                    dirnow='O';
                }
                else if(dirnow=='O')
                {
                    dirnow='N';
                }
                else
                {
                    dirnow='S';
                }
            }
            else if(s[i]=='E')
            {
                if(dirnow=='N')
                {
                    dirnow='O';
                }
                else if(dirnow=='S')
                {
                    dirnow='L';
                }
                else if(dirnow=='O')
                {
                    dirnow='S';
                }
                else
                {
                    dirnow='N';
                }
            }
            else if(s[i]=='F')
            {
                if(dirnow=='N')
                {
                    if(startx-1>-1 && grid[startx-1][starty]!=0)
                    {
                        startx-=1;
                        if(grid[startx][starty]==1)
                        {
                            cnt++;
                            grid[startx][starty]=-1;
                        }
                    }
                }
                else if(dirnow=='S')
                {
                    if(startx+1<row && grid[startx+1][starty]!=0)
                    {
                        startx+=1;
                        if(grid[startx][starty]==1)
                        {
                            cnt++;
                            grid[startx][starty]=-1;
                        }
                    }
                }
                else if(dirnow=='O')
                {
                    if(starty-1>-1 && grid[startx][starty-1]!=0)
                    {
                        starty-=1;
                        if(grid[startx][starty]==1)
                        {
                            cnt++;
                            grid[startx][starty]=-1;
                        }
                    }
                }
                else
                {
                    if(starty+1<col && grid[startx][starty+1]!=0)
                    {
                        starty+=1;
                        if(grid[startx][starty]==1)
                        {
                            cnt++;
                            grid[startx][starty]=-1;
                        }
                    }
                }
            }
        }
        printf("%d\n",cnt);
    }
}
