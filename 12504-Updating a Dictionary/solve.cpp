#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sf(x)           scanf("%lld",&x)
#define flop(n,i)       for(i=0;i<n;i++)
#define all(v)          v.begin(),v.end()


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll test,t;
    while(scanf("%lld",&test)==1)
    {
        getchar();
        for(t=0; t<test; t++)
        {
            ll i,j=1,k,l1,l2,pos;
            string x="",y="",temp="",temp2="";

            map<string,string>mp1;
            map<string,string>mp2;
            map<string,string>::iterator itm;

            vector<string>v1;
            vector<string>v2;
            vector<string>::iterator itv;

            set<string>tp;
            set<string>tn;
            set<string>ts;
            set<string>::iterator its;

            getline(cin,x);
            getline(cin,y);

            l1=x.length(),l2=y.length();

//old
            for(i=1; i<l1-1; i++)
            {
                if(x[i]==':')
                {
                    temp="";
                    temp2="";
                    for(; j<i; j++)
                        temp+=x[j];
                    for(k=i+1; k<l1-1; k++)
                    {
                        if(x[k]==',')
                        {
                            i=k+1;
                            j=k+1;
                            break;
                        }
                        temp2+=x[k];
                    }
                }
                if(temp!="")
                {
                    mp1[temp]=temp2;
                    v1.push_back(temp);
                }
            }
//new
            j=1;
            temp="";
            temp2="";
            for(i=1; i<l2-1; i++)
            {
                if(y[i]==':')
                {
                    temp="";
                    temp2="";
                    for(; j<i; j++)
                        temp+=y[j];
                    for(k=i+1; k<l2-1; k++)
                    {
                        if(y[k]==',')
                        {
                            i=k+1;
                            j=k+1;
                            break;
                        }
                        temp2+=y[k];
                    }
                }
                if(temp!="")
                {
                    mp2[temp]=temp2;
                    v2.push_back(temp);
                }
            }

//positive,negative,star
            for(i=0; i<v1.size(); i++)
            {
                itv=find(all(v2),v1[i]);
                if(itv==v2.end())
                    tn.insert(v1[i]);
                else
                {
                    if(mp1[*itv]!=mp2[*itv])
                        ts.insert(v1[i]);
                }
            }
            for(i=0; i<v2.size(); i++)
            {
                itv=find(all(v1),v2[i]);
                if(itv==v1.end())
                    tp.insert(v2[i]);
            }

            vector<string>sp(all(tp));
            vector<string>sn(all(tn));
            vector<string>ss(all(ts));

//printing part
            if(sp.size()+sn.size()+ss.size()==0)
                puts("No changes");
            else
            {
                if(sp.size())
                {
                    printf("+");
                    for(i=0; i<sp.size(); i++)
                    {
                        cout<<sp[i];
                        if(i!=sp.size()-1)
                        {
                            printf(",");
                        }
                    }
                    puts("");
                }
                if(sn.size())
                {
                    printf("-");
                    for(i=0; i<sn.size(); i++)
                    {
                        cout<<sn[i];
                        if(i!=sn.size()-1)
                        {
                            printf(",");
                        }
                    }
                    puts("");
                }
                if(ss.size())
                {
                    printf("*");
                    for(i=0; i<ss.size(); i++)
                    {
                        cout<<ss[i];
                        if(i!=ss.size()-1)
                        {
                            printf(",");
                        }
                    }
                    puts("");
                }
            }
            puts("");
        }
    }
}
