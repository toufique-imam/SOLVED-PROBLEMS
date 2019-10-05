#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MX 21
const ll mod=1e9+7;
ll MODSQ = mod * mod, mul_res[MX][MX];
void multiply(ll a[][MX], ll b[][MX]) {
    memset(mul_res, 0, sizeof mul_res);
    for(int i = 1; i < MX; i++) {
        for(int j = 1; j < MX; j++) {
            for(int k = 1; k < MX; k++) {
                mul_res[i][j] = (mul_res[i][j] + a[i][k] * b[k][j]);
                if(mul_res[i][j] >= MODSQ)
                    mul_res[i][j] -= MODSQ;
            }
            mul_res[i][j] %= mod;
        }
    }
}
ll big_res[MX][MX], init[MX][MX];
void matrix_expo(ll n) {
    if(n == 0) {
        memset(mul_res, 0, sizeof mul_res);
        for(int i = 1; i < MX; i++)
            big_res[i][i] = 1;
        return;
    }
    if(n % 2 == 0) {
        matrix_expo(n / 2);
        multiply(big_res, big_res);
        for(int i = 1; i < MX; i++) {
            for(int j = 1; j < MX; j++)
                big_res[i][j] = mul_res[i][j];
        }
    } else {
        matrix_expo(n - 1);
        multiply(big_res, init);
        for(int i = 1; i < MX; i++) {
            for(int j = 1; j < MX; j++)
                big_res[i][j] = mul_res[i][j];
        }
    }
}

ll solve(ll N) {
    if (N == 3)
        return 20;
    if(N < 3)
        return 0;
    //define init
    init[1][1] = init[1][2] = init[1][3] = 1;
    init[2][4] = init[2][5] = init[2][6] = 1;
    init[3][7] = init[3][8] = init[3][9] = 1;
    init[4][10] = 1;
    init[5][11] = init[5][12] = 1;
    init[6][13] = init[6][14] = init[6][15] = 1;
    init[7][16] = 1;
    init[8][17] = 1;
    init[9][18] = init[9][19] = init[9][20] = 1;
    init[10][1] = init[10][2] = init[10][3] = 1;
    init[11][10] = 1;
    init[12][11] = init[12][12] = 1;
    init[13][16] = 1;
    init[14][17] = 1;
    init[15][18] = init[15][19] = init[15][20] = 1;
    init[16][1] = init[16][2] = init[16][3] = 1;
    init[17][10] = 1;
    init[18][16] = 1;
    init[19][17] = 1;
    init[20][18] = init[20][19] = init[20][20] = 1;
    matrix_expo(N);
    //define F
    //
    ll ans=0;
    for(int i=1;i<MX;i++){
        ans+=big_res[1][i];
        if(ans>=mod){
            ans%=mod;
        }
    }
    return ans%mod;
}
int main() {
    ll n;
    scanf("%lld", &n);
    ll ans = solve(n);
    printf("%lld\n", ans);
}