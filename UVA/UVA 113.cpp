#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 10000
#define all(v) v.begin() v.end()
int main()
{
    double x,y;
    while(scanf("%lf %lf",&x,&y)==2)
    {
        printf("%0.0lf\n",pow(y,1.0/x));
    }
    return 0;
}
