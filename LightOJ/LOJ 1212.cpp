/*
ID: sabertooth
LANG: C++14
TASK:CF Diverse Group
*/
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
#define gcd(x, y) abs(__gcd(x, y))
#define all(v) v.begin(), v.end()
deque<int> dq;
int n;
void push_left(int x)
{
    if (dq.size() >= n)
    {
        printf("The queue is full\n");
        return;
    }
    else
    {
        dq.push_front(x);
        printf("Pushed in left: %d\n", x);
    }
}
void push_right(int x)
{
    if (dq.size() >= n)
    {
        printf("The queue is full\n");
        return;
    }
    else
    {
        dq.push_back(x);
        printf("Pushed in right: %d\n", x);
    }
}
void popleft()
{
    if (dq.empty())
    {
        printf("The queue is empty\n");
        return;
    }
    else
    {
        printf("Popped from left: %d\n", dq.front());
        dq.pop_front();
    }
}

void popRight()
{
    if (dq.empty())
    {
        printf("The queue is empty\n");
        return;
    }
    else
    {
        printf("Popped from right: %d\n", dq.back());
        dq.pop_back();
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int test;
    scanf("%d", &test);
    for (int T = 1; T <= test; T++)
    {
        dq.clear();
        int q, x;
        scanf("%d %d", &n, &q);
        string s;
        printf("Case %d:\n", T);
        for (int i = 0; i < q; i++)
        {
            cin >> s;
            if (s == "pushLeft")
            {
                cin >> x;
                push_left(x);
            }
            else if (s == "pushRight")
            {
                cin >> x;
                push_right(x);
            }
            else if (s == "popLeft")
                popleft();
            else
                popRight();
        }
    }
}
