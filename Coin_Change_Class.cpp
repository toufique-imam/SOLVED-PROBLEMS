#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//coin change
//unlimited coins
//limited coins
//How_many_ways_to_make?
//Can_make?


class CoinChange_un
{
    int _coinCnt;
    int _moneyLimit;
    vector<int>_Coin;
    vector<int>_moneyRange;
public:
    CoinChange_un(int n,int k)
    {
        _coinCnt=n;
        _moneyLimit=k;
        _moneyRange=vector<int>(k+9,0);
    }
    CoinChange_un()
    {
        _coinCnt=0;
        _moneyLimit=0;
    }
    void getCoin(int n)
    {
        _coinCnt=n;
    }
    void getMoney(int k)
    {
        _moneyLimit=k;
        _moneyRange=vector<int>(k+9,0);
    }
    void _coinInput()
    {
        for(int i=0; i<_coinCnt; i++)
        {
            int x;
            scanf("%d",&x);
            _Coin.push_back(x);
        }
        sort(_Coin.begin(),_Coin.end());
    }
    void calc()
    {
        _moneyRange[0]=1;
        for(int i=0; i<_Coin.size(); i++)
            for(int j=_Coin[i]; j<=_moneyLimit; j++)
                _moneyRange[j]+=_moneyRange[j-_Coin[i]];
    }
    bool CanMake(int k)
    {
        if(_moneyRange[k])
            return 1;
        return 0;
    }
    int Ways_to_make(int k)
    {
        return _moneyRange[k];
    }
};

class CoinChange_lm
{
    int _coinCnt;
    int _moneyLimit;
    vector< pair<int,int> >coins;
    //coin value--coin count;
    vector<int>Money_limit;
public:
    CoinChange_lm()
    {
        _coinCnt=0;
        _moneyLimit=0;
    }
    CoinChange_lm(int n,int k)
    {
        _coinCnt=n;
        _moneyLimit=k;
        Money_limit=vector<int>(k+9,0);
    }
    void getCoin(int n)
    {
        _coinCnt=n;
    }
    void getMoney(int k)
    {
        _moneyLimit=k;
        Money_limit=vector<int>(k+9,0);
    }
    void _coinInput()
    {
        int x,y;
        for(int i=0; i<_coinCnt; i++)
        {
            scanf("%d %d",&x,&y);
            coins.push_back(make_pair(x,y));
        }
        sort(coins.begin(),coins.end());
    }
    void calc()
    {
        Money_limit[0]=1;
        for(int i=0;i<_coinCnt;i++)
            for(int j=0;j<coins[i].second;j++)
                for(int k=_moneyLimit;k>=coins[i].first;k--)
                    Money_limit[k]+=Money_limit[k-coins[i].first];
    }
    int Ways_to_make(int k)
    {
        return Money_limit[k];
    }
    bool CanMake(int k)
    {
        return Money_limit[k]>0?1:0;
    }
};

int main()
{
    CoinChange_un CcU;
    int n,k,q;
    scanf("%d %d",&n,&k);
    CcU.getCoin(n);
    CcU.getMoney(k);
    CcU._coinInput();
    CcU.calc();
    while(1)
    {
        scanf("%d",&q);
        if(q<0)
          break;
        printf("%d\n",CcU.Ways_to_make(q));
    }
}
