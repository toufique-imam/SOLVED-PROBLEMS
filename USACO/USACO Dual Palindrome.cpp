/*ID: sabertooth
LANG: C++11
TASK: dualpal
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isPalindrome(string s)
{
    string tt=s;
    reverse(s.begin(),s.end());
    return tt==s;
}
string change(int n,int base)
{
    string s;
    while(n)
    {
        s+=(n%base)+'0';
        n/=base;
    }
    reverse(s.begin(),s.end());
    return s;
}
int main()
{
    ifstream ccin("dualpal.in");
    ofstream ccout("dualpal.out");
    int n,s;
    ccin>>n>>s;
    int cntt=0;
    for(int i=s+1; cntt<n; i++)
    {
        int cnt=0;
        for(int j=2; j<=10; j++)
        {
            string ss=change(i,j);
            int len=int(ss.size());
            if(ss[0]!='0' and ss[len-1]!='0' and isPalindrome(ss))
            {
                cnt++;
            }
            if(cnt>=2)
                break;
        }
        if(cnt>=2)
        {
            cntt++;
            ccout<<i<<endl;
        }
    }
}
