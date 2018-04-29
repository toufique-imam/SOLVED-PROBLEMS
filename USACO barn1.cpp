/*
ID: sabertooth9
LANG: C++11
TASK: barn1
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int ara[209];
pair<int,int> ara1[209];
bool comp(pair<int,int>p1,pair<int,int>p2){return p1.first>p2.first;}
int main()
{
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
    int s,stalls,c;
    cin>>s>>stalls>>c;
    int start=0;
    for(int i=0;i<c;i++)scanf("%d",&ara[i]);
    sort(ara,ara+c);
    for(int i=1;i<c;i++)ara1[i]={ara[i]-ara[i-1],i};
    sort(ara1+1,ara1+c,comp);
    vector<int>v;
    for(int i=1;i<s;i++)v.push_back(ara1[i].second);
    v.push_back(0);
    v.push_back(c);
    sort(v.begin(),v.end());
    for(int i=1;i<v.size();i++)for(int j=ara[v[i-1]];j<=ara[v[i]-1];j++)start++;
    cout<<start<<endl;
}
