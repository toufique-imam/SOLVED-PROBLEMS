/*
ID: sabertooth9
TASK: milk2
LANG: C++11
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000000;
pair<int,int>A[5009];
int cum[N+9];
int main()
{
    FILE *fin=fopen("milk2.in","r");
    FILE *fout=fopen("milk2.out","w");
    int n,x,y;
    int st=1e9,en=-1e9;
    fscanf(fin,"%d",&n);
    for(int i=0; i<n; i++)
    {
        fscanf(fin,"%d %d",&x,&y);
        A[i]= {x,y};
        st=min(st,x);
        en=max(en,y);
    }
    for(int i=0; i<n; i++)
    {
        cum[A[i].first]+=1;
        cum[A[i].second]-=1;
    }
    for(int i=1; i<=N; i++)
        cum[i]+=cum[i-1];
    bool f=0,f1=0;
    int ans1,ans2,pos1,pos2,posx1,posx2;
    ans1=ans2=-1e9;
    for(int i=st; i<=en; i++)
    {
        if(cum[i] and !f)
        {
            pos1=i,f=1;
            if(f1)
                ans2=max(ans2,posx2-posx1+1);
            f1=0;
        }
        else if(cum[i] and f)
            pos2=i;
        else if(!cum[i] and f)
        {
            ans1=max(ans1,pos2-pos1+1);
            f=0;
            f1=1;
            posx1=i;
            posx2=i;
        }
        else if(!cum[i] and f1)
        {
            posx2=i;
        }
        else if(!cum[i] and !f1)
        {
            posx1=i;
            posx2=i;
            f1=1;
        }
    }
    if(f)
    {
        ans1=max(ans1,pos2-pos1+1);
        //ans2=max(ans2,0);
    }
    ans2=max(ans2,0);
    fprintf(fout,"%d %d\n",ans1,ans2);
    return 0;
}
