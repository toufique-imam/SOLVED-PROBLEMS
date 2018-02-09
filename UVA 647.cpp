#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class sapludu
{
    int playercnt;
    int playerprev[10];
    int chulad[109];
    int throws[1009];
    int throwsz;
public:
    sapludu()
    {
        playercnt=0;
        memset(chulad,0,sizeof(chulad));
        memset(throws,0,sizeof(throws));
        memset(playerprev,0,sizeof(playerprev));
    }
    void getThrow()
    {
        int x,i=0;
        while(1)
        {
            scanf("%d",&x);
            if(x)
                throws[i++]=x;
            else
                break;
        }
        throwsz=i;
    }
    bool getPlayer()
    {
        scanf("%d",&playercnt);
        memset(chulad,0,sizeof(chulad));
        memset(playerprev,0,sizeof(playerprev));
        if(playercnt==0)
            return 0;
        return 1;
    }
    void getchuald()
    {
        int x,y;
        while(scanf("%d %d",&x,&y) && x!=0 && y!=0)
        {
            chulad[x]=y;
        }
    }
    void getspecial()
    {
        int x;
        while(scanf("%d",&x)==1 && x!=0)
        {
            if(x<0)
                chulad[-x]=-1009;
            else
                chulad[x]=1009;
        }
    }
    int simulation()
    {
        int x,turner=0;
        for(int i=0; i<throwsz; i++)
        {
            if(playerprev[turner]<0)
            {
                playerprev[turner]*=-1;
                turner++;
                turner=turner%playercnt;
            }
            x=playerprev[turner]+throws[i];
            if(x==100)
                return turner;
            else if(x>100)
                x=playerprev[turner];
            if(chulad[x]==-1009)
            {
                playerprev[turner]=-x;
                turner++;
                turner=turner%playercnt;
            }
            else if(chulad[x]==1009)
            {
                playerprev[turner]=x;
            }
            else if(chulad[x]!=0)
            {
                playerprev[turner]=chulad[x];
                turner++;
                turner=turner%playercnt;
            }
            else
            {
                playerprev[turner]=x;
                turner++;
                turner=turner%playercnt;
            }
        }
    }
};

int main()
{
    sapludu sp;
    sp.getThrow();
    while(sp.getPlayer())
    {
        sp.getchuald();
        sp.getspecial();
        printf("%d\n",sp.simulation()+1);
    }
}
