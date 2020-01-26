#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define MP		make_pair
#define fi		first
#define se		second


typedef long long LL;

const int N  =  6170736;
const int M  =  1e8 + 10;

char c[M];
int p[N];
int cnt = 0;
int n = 1e8 + 2;
int v;
int tot = 0;

double t = 0;
LL ans = 0;


int main(){

	t = clock();

	cnt = 0;
	rep(i, 2, n){
		if (!c[i]) p[++cnt] = i;

		rep(j, 1, cnt){
			v = i * p[j];
			if (v > n) break;
			c[v] = 1;
			if (i % p[j] == 0) break;
		}
	}

	printf("%d\n", cnt);

	rep(i, 1, 1e8){
		int k = (int)sqrt(i);
		int fg = 1;
		rep(j, 1, k) if (i % j == 0 && c[j + i / j]){ fg = 0; break; }
		if (fg) ++tot, ans += 1ll * i;
	}

	t = clock() - t;
	printf("%d %lld\n", tot, ans);
	puts("---------------------------");
	printf("time used : %.3fs\n", t / 1000); 
	return 0;
}


