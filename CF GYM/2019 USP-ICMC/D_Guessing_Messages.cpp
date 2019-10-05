#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s,t;
    cin>>s>>t;
    int j=0,i=0;
    bool f=0;
    for(i=0;i<s.size();i++){
        if(s[i]==t[j])j++;
        if(j==t.size()){
            f=1;
            break;
        }
    }
    if(f){
        puts("YES");
    }
    else puts("NO");
}