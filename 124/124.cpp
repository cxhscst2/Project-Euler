#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define MP		make_pair
#define fi		first
#define se		second


typedef long long LL;

const int N = 1e5 + 10;

pair <int, int> a[N];
int cnt = 0;
int c[N];
int p[N];



int main(){

	rep(i, 2, 1e5){
		for (int j = i + i; j <= 1e5; j += i){
			c[j] = 1;
		}
	}

	rep(i, 2, 1e5) if (!c[i]) p[++cnt] = i;

	rep(i, 1, 1e5){
		int sq = sqrt(i);
		int now = 1;
		rep(j, 1, cnt){
			if (p[j] > i) break;
			if (i % p[j] == 0) now *= p[j];
		}
		a[i] = MP(now, i);
	}


	rep(i, 1, 100) printf("%d %d\n", a[i].se, a[i].fi);
	sort(a + 1, a + 100001);

	printf("%d\n", a[10000].se);
	return 0;
}


