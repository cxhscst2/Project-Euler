#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define MP		make_pair
#define fi		first
#define se		second


typedef long long LL;

int a[105];
LL f[105];
LL ans = 0;

inline bool judge(int x){
	rep(i, 1, x - 2) if (a[i] == a[i + 1] && a[i + 1] == a[i + 2] && a[i] == 1) return false;
	return true;
}

void dfs(int x){
	if (!judge(x - 1)) return;
	++f[x - 1];
	if (x > 30) return;

	a[x] = 0;
	dfs(x + 1);
	a[x] = 1;
	dfs(x + 1);
}


int main(){

	dfs(1);

	ans = f[30];
	rep(i, 1, 30){
		int x = i - 1, y = 30 - i;
		ans += f[x] * f[y];
	}

	printf("%lld\n", ans);
	return 0;
}


