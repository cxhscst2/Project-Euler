#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define MP		make_pair
#define fi		first
#define se		second


typedef long long LL;

int n = 1548136;

LL f[1548999];
LL ans = 0;

inline void up(LL &a, LL &b){
	a += b;
	if (a >= 10000000000000000ll) a -= 10000000000000000ll;
}


int main(){

	f[0] = 1;

	rep(i, 2, 5000){
		int fg = 1;
		int x = sqrt(i);

		rep(j, 2, x){
			if (i % j == 0){
				fg = 0;
				break;
			}
		}
		if (fg) dec(j, n, i) up(f[j], f[j - i]);
	}

	rep(i, 2, 1548136){
		int x = sqrt(i);
		int fg = 1;
		rep(j, 2, x){
			if (i % j == 0){
				fg = 0;
				break;
			}
		}

		if (fg) up(ans, f[i]);
	}

	printf("%lld\n", ans);
	return 0;
}


