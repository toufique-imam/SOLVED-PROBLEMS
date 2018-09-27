/*
ID:sabertooth9
TASK: beads
LANG: C++11
*/
#include<bits/stdc++.h>
using namespace std;
#define     pii     pair<int,int>
#define     pll     pair<long long,long long>
#define     ff      first
#define     sc      second
const long long arrsize=100000;
int main()
{
    int n,i,j,k;
    ofstream fout("beads.out");
    ifstream fin("beads.in");
    fin>>n;
    bool used[3000];
    string s;
    fin>>s;
    s+=s;
    int cnt1,cnt2,maxx=-1,cnt;
    for(i=0; i<s.length(); i++)
    {
        memset(used,0,sizeof(used));
        cnt1=cnt2=0;
        char main=s[i];
        //i theke tana ek colour koeta
        for(j=i; j<s.length(); j++)
        {
            if(used[j]==0)
            {
                if(main==s[j])
                    cnt1++;
                else if(main!=s[j] && main=='w')
                {
                    main=s[j];
                    cnt1++;
                }
                else if(s[j]=='w')
                    cnt1++;
                else
                    break;
                used[j]=1;
                used[j+n]=1;
            }
        }
        main=s[j];
        //erpor theke tana ek colour koeta
        for(k=j; k<s.length(); k++)
        {
            if(used[k]==0)
            {
                if(s[k]==main || s[k]=='w')
                {
                    cnt2++;
                }
                else if(main=='w' && s[k]!=main)
                {
                    cnt2++;
                    main=s[k];
                }
                else
                    break;
                used[k]=1;
                used[k+n]=1;
            }
        }
        cnt=cnt1+cnt2;
        maxx=max(maxx,cnt);
    }
    fout<<maxx<<endl;
    return 0;
}
