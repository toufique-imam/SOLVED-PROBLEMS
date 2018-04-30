/*
ID: sabertooth9
LANG: C++11
TASK: wormhole
*/
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
pair<int,int>A[14];
int paired[14];
int next_right[14];
int n;
bool check_cycle()
{
    for(int i=1;i<=n;i++)
    {
        int pos=i;
        for(int j=1;j<=n;j++)
        {
            pos=next_right[paired[pos]];
        }
        if(pos!=0)
            return 1;
    }
    return 0;
}
int recur()
{
    int cnt=0,pos=0;
    for(pos=1;pos<=n;pos++)
    {
        if(paired[pos]==0)
            break;
    }
    if(pos>n)
    {
        if(check_cycle())return 1;
        return 0;
    }
    for(int j=pos+1;j<=n;j++)
    {
        if(paired[j]==0)
        {
            paired[j]=pos;
            paired[pos]=j;
            cnt+=recur();
            paired[j]=0;
            paired[pos]=0;
        }
    }
    return cnt;
}
int main()
{
    freopen("wormhole.in","r",stdin);
    freopen("wormhole.out","w",stdout);
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        cin>>A[i].first>>A[i].second;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(A[i].second==A[j].second and A[i].first<A[j].first)
            {
                if(next_right[i]==0 or (A[next_right[i]].first-A[i].first)>A[j].first-A[i].first)
                    next_right[i]=j;
            }
        }
    }
    cout<<recur()<<endl;
}
