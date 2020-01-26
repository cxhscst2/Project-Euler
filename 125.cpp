#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define MP		make_pair
#define fi		first
#define se		second


typedef long long LL;

const int N = 1e4 + 10;

LL c[N];
LL a[30], b[30];
unordered_set <LL> s;


inline bool check(LL x){
	int cnt = 0;
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);

	for (; x; x /= 10) a[++cnt] = x % 10;
	rep(i, 1, cnt) b[i] = a[i];

	reverse(b + 1, b + cnt + 1);

	rep(i, 1, cnt) if (a[i] != b[i]) return false;
	return true;
}


int main(){

	rep(i, 1, 10000) c[i] = c[i - 1] + 1ll * i * i;

	rep(i, 2, 10000){
		rep(j, 0, i - 2){
			LL now = c[i] - c[j];
			if (check(now)) s.insert(now);
		}
	}

	LL ans = 0;
	for (auto u : s) if (u <= 100000000) ans += u, printf("%lld\n", u);
	printf("%lld\n", ans);
	return 0;
}


