#include<bits/stdc++.h>
using namespace std;

char grid[40][100];
int used[40][100];
int ax[]= {0,0,-1,1};
int ay[]= {1,-1,0,0};

void dfs(int i,int j,char x)
{
    if(used[i][j])
        return;
    if(grid[i][j]=='X')
        return;
    used[i][j]=1;
    grid[i][j]=x;
    for(int t=0; t<4; t++)
        dfs(i+ax[t],j+ay[t],x);
}
int main()
{
    while(1)
    {
        int sz=0;
        while(1)
        {
            if(!gets(grid[sz]))
                return 0;
            if(grid[sz][0]=='_')
                break;
            sz++;
        }
        memset(used,0,sizeof(used));
        for(int i=0; i<sz; i++)
            for(int j=0; j<strlen(grid[i]); j++)
                if(grid[i][j]!='X' && grid[i][j]!=' ')
                {
                    if(used[i][j]==0)
                        dfs(i,j,grid[i][j]);
                }

        for(int i=0;i<sz;i++)
            puts(grid[i]);
        puts("_____________________________");
    }
}
