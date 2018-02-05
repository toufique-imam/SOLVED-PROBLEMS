#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct data
{
    double ax;
    double ay;
};

double distance_(data a,data b)
{
    return sqrt((a.ax-b.ax)*(a.ax-b.ax)+(a.ay-b.ay)*(a.ay-b.ay));
}
double conv_polygon_area(ll n,vector<data>&v)
{
    double area=0.0;
    for(ll i=0;i<n;i++)
    {
        area+=(v[i%n].ax*v[(i+1)%n].ay)-(v[i%n].ay*v[(i+1)%n].ax);
    }
    return area*0.5;
}

double conv_polygon_circumference(ll n,vector<data>&v)
{
    double circumference=0.0;
    for(ll i=0;i<n;i++)
    {
        circumference+=distance_(v[i%n],v[(i+1)%n]);
    }
    return circumference;
}
int main()
{
    ll n;
    double r;
    data x;
    vector<data>v;
    scanf("%lld %lf",&n,&r);
    for(int i=0;i<n;i++)
    {
        scanf("%lf %lf",&x.ax,&x.ay);
        v.push_back(x);
    }
    printf("%0.2f\n",conv_polygon_circumference(n,v)+2*3.1416*r);
}
