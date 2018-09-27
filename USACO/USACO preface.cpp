/*
ID: sabertooth
LANG: C++11
TASK: preface
*/
#include <bits/stdc++.h>
using namespace std;
int coin[]={1,5,10,50,100,500,1000};
char name[]={'I','V','X','L','C','D','M'};
string solve(int n)
{
    string ans;
    if(n<10){
        if(n==1)return "I";
        else if(n==2)return "II";
        else if(n==3)return "III";
        else if(n==4)return "IV";
        else if(n==5)return "V";
        else if(n==6)return "VI";
        else if(n==7)return "VII";
        else if(n==8)return "VIII";
        else if(n==9)return "IX";
        else return "";
    }
    else if(n<100){
        if((n/10)==1)return "X"+solve(n%10);
        else if((n/10)==2)return "XX"+solve(n%10);
        else if((n/10)==3)return "XXX"+solve(n%10);
        else if((n/10)==4)return "XL"+solve(n%10);
        else if((n/10)==5)return "L"+solve(n%10);
        else if((n/10)==6)return "LX"+solve(n%10);
        else if((n/10)==7)return "LXX"+solve(n%10);
        else if((n/10)==8)return "LXXX"+solve(n%10);
        else if((n/10)==9)return "XC"+solve(n%10);
    }
    else if(n<1000){
        if((n/100)==1)return "C"+solve(n%100);
        else if((n/100)==2)return "CC"+solve(n%100);
        else if((n/100)==3)return "CCC"+solve(n%100);
        else if((n/100)==4)return "CD"+solve(n%100);
        else if((n/100)==5)return "D"+solve(n%100);
        else if((n/100)==6)return "DC"+solve(n%100);
        else if((n/100)==7)return "DCC"+solve(n%100);
        else if((n/100)==8)return "DCCC"+solve(n%100);
        else if((n/100)==9)return "CM"+solve(n%100);
    }
    else if(n>=1000){
        if((n/1000)==1)return "M"+solve(n%1000);
        else if((n/1000)==2)return "MM"+solve(n%1000);
        else if((n/1000)==3)return "MMM"+solve(n%1000);
    }
    else return "";
}
int main()
{
    ifstream fin("preface.in");
    ofstream fout("preface.out");
    int n;
    fin>>n;
    string tmp;
    int cnt[10];
    memset(cnt,0,sizeof cnt);
    for(int i=1;i<=n;i++){
        tmp=solve(i);
        //cout<<tmp<<endl;
        for(int i=0;i<(int)tmp.size();i++){
            if(tmp[i]=='I')cnt[0]++;
            if(tmp[i]=='V')cnt[1]++;
            if(tmp[i]=='X')cnt[2]++;
            if(tmp[i]=='L')cnt[3]++;
            if(tmp[i]=='C')cnt[4]++;
            if(tmp[i]=='D')cnt[5]++;
            if(tmp[i]=='M')cnt[6]++;
        }
    }
    for(int i=0;i<7;i++){
        if(cnt[i]){
            fout<<name[i]<<" "<<cnt[i]<<endl;
        }
    }
}


