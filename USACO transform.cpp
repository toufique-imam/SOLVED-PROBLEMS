/*ID: sabertooth
LANG: C++11
TASK: transform
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ifstream ccin("transform.in");
ofstream ccout("transform.out");
class matrix
{
public:
    int n;
    vector<string>v;
    matrix()
    {
        n=0;
        v.clear();
    }
    void show()
    {
        for(int i=0; i<n; i++)
            cout<<v[i]<<endl;
    }
    bool operator == (const matrix&A) const
    {
        for(int i=0; i<n; i++)
            if(v[i]!=A.v[i])
                return 0;
        return 1;
    }
    matrix turn_90()
    {
        matrix temp;
        temp.n=this->n;
        temp.v=this->v;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                temp.v[i][j]=this->v[n-j-1][i];
            }
        }
        return temp;
    }
    matrix turn_180()
    {
        matrix temp;
        temp.n=this->n;
        temp.v=this->v;
        for(int i=0; i<n; i++)
        {
            string s=v[n-i-1];
            reverse(s.begin(),s.end());
            temp.v[i]=s;
        }
        return temp;
    }
    matrix turn_270()
    {
        matrix temp;
        temp.n=this->n;
        temp.v=this->v;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                temp.v[i][j]=this->v[j][n-i-1];
            }
        }
        return temp;
    }
    matrix reflect()
    {
        matrix temp;
        temp.n=this->n;
        temp.v=this->v;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                temp.v[i][j]=this->v[i][n-j-1];
            }
        }
        return temp;
    }
};
int main()
{
    int n;
    ccin>>n;
    matrix M,M1;
    M.n=n;
    M1.n=n;
    string s;
    for(int i=0; i<n; i++)
    {
        ccin>>s;
        M.v.push_back(s);
    }
    for(int i=0; i<n; i++)
    {
        ccin>>s;
        M1.v.push_back(s);
    }
    if(M1==M.turn_90())
        ccout<<1<<endl;
    else if(M1==M.turn_180())
        ccout<<2<<endl;
    else if(M1==M.turn_270())
        ccout<<3<<endl;
    else if(M1==M.reflect())
        ccout<<4<<endl;
    else if(M1.turn_90()==M.reflect() or M.reflect()==M1.turn_270() or M.reflect()==M1.turn_180())
        ccout<<5<<endl;
    else if(M1==M)
        ccout<<6<<endl;
    else
        ccout<<7<<endl;
}
