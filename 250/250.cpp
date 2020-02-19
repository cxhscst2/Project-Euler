#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)    for (int i(a); i <= (b); ++i)
#define dec(i, a, b)    for (int i(a); i >= (b); --i)
#define MP              make_pair
#define fi              first
#define se              second


typedef long long LL;

const LL mod  =  250;
const int N   =  3e5 + 10;

inline LL Pow(LL a, LL b, LL mod){
        LL ret(1);
        for (; b; b >>= 1, (a *= a) %= mod) if (b & 1) (ret *= a) %= mod;
        return ret;
}

inline void up(LL &x, LL y){
        x += y;
        if (x >= 10000000000000000ll) x -= 10000000000000000ll;
}

LL f[2][305];
int x;


int main(){

        f[0][0] = 1;
        x = 0;
        rep(i, 1, 250250){
                memset(f[x ^ 1], 0, sizeof f[x ^ 1]);
                int d = (int)Pow(i, i, mod);
                rep(j, 0, 249) up(f[x ^ 1][(j + d) % 250], f[x][j]);
                rep(j, 0, 249) up(f[x ^ 1][j], f[x][j]);
                x ^= 1;
        }


        printf("%lld\n", f[x][0] - 1);
        return 0;
}


