/*
ID: nuhash11
LANG: C++
TASK: milk
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<int,int>ara[2000009];
bool comp(pair<int,int>p1,pair<int,int>p2)
{
    if(p1.first<p2.first)
        return 1;
    if(p1.first==p2.first)
        return p1.second>p2.second;
    return 0;
}

int main()
{
freopen("milk.in","r",stdin);
freopen("milk.out","w",stdout);
    int req,n;
    cin>>req>>n;
    int ans=0,x,y;
    for(int i=0; i<n; i++)
        cin>>ara[i].first>>ara[i].second;
    sort(ara,ara+n,comp);
    int now=0;
    for(int i=0; i<n and now<req; i++)
    {
        if(req-now>=ara[i].second)
        {
            now+=ara[i].second;
            ans+=ara[i].second*ara[i].first;
        }
        else
        {
            int took=req-now;
            now+=took;
            ans+=ara[i].first*took;
        }
    }
    cout<<ans<<endl;
    return 0;
}
