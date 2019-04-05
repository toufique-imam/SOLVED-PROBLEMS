#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <stack>
using namespace std;
#define ll long long

int main()
{
    ll test;
    scanf("%lld\n", &test);
    for (ll i = 1; i <= test; i++)
    {
        stack<string> bac;
        stack<string> fr;
        string a, current = "http://www.lightoj.com/";

        printf("Case %lld:\n", i);
        while (cin >> a)
        {
            if (a[0] == 'Q')
                break;
            else if (a[0] == 'V')
            {
                bac.push(current);
                cin >> current;
                while (!fr.empty())
                    fr.pop();
                cout << current << endl;
            }
            else if (a[0] == 'B')
            {
                if (bac.empty())
                {
                    puts("Ignored");
                    continue;
                }
                fr.push(current);
                current = bac.top();
                bac.pop();
                cout << current << endl;
            }
            else if (a[0] == 'F')
            {
                if (fr.empty())
                {
                    puts("Ignored");
                    continue;
                }
                bac.push(current);
                current = fr.top();
                fr.pop();
                cout << current << endl;
            }
        }
    }
}