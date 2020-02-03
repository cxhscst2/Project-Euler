#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define MP		make_pair
#define fi		first
#define se		second


typedef long long LL;

const int N = 1e5 + 10;
const LL mod = 1e9;

double t;
int cnt = 0;
int c[N];
int F[30];
LL f[N];
LL ans = 0;


int main(){

	t = clock();
	F[1] = F[2] = 1;
	rep(i, 3, 24) F[i] = F[i - 1] + F[i - 2];

	rep(i, 2, F[24]){
		int q = sqrt(i);
		int fg = 1;
		rep(j, 2, q) if (i % j == 0){
			fg = 0;
			break;
		}
		if (fg){
			c[++cnt] = i;
		}
	}


	f[0] = 1;
	
	rep(i, 1, cnt){
		dec(j, F[24], 1){
		       for (int k = c[i], v = c[i]; v <= j; k = 1ll * k * c[i] % mod, v += c[i]){
			       if (j >= v){
				       f[j] = (f[j] + 1ll * f[j - v] * k % mod) % mod;
			       }
		       }
		}
	}


	rep(i, 2, 24) (ans += f[F[i]]) %= mod;
	printf("%lld\n", ans);

	t = clock() - t;
	puts("---------------------------");
	printf("time used : %.3fs\n", t / 1000); 
	return 0;
}


