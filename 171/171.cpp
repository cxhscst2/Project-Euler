#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)    for (int i(a); i <= (b); ++i)
#define dec(i, a, b)    for (int i(a); i >= (b); --i)

typedef long long LL;

const LL mod = 1e9;


struct node{
	LL cnt, sum;
} f[26][2010];

node ans;

LL p[26];
int a[26];
int T;
int l, r;
int now;
int ca = 0;



inline void up(LL &x, LL y){
	x += y;
	x %= mod;
}

node dp(int pos, int sum, int flag){
	if (pos == 0){
		node t;
		t.cnt = (sum == now);
		t.sum = 0;
		return t;
	}

	if (!flag && ~f[pos][sum].cnt) return f[pos][sum];

	
	int ed = flag ? a[pos] : 9;


	node ret;
	ret.cnt = ret.sum = 0;

	rep(i, 0, ed){
		node tmp = dp(pos - 1, sum + i * i, flag && (i == a[pos]));
		up(ret.cnt, tmp.cnt);
		up(ret.sum, tmp.sum + 1ll * i * p[pos - 1] % mod * tmp.cnt % mod);  
	}


	if (!flag) f[pos][sum] = ret;
	return ret;
}

node solve(){
	node ret;

	LL cnt = 0;
	LL sum = 0;

	int len = 20;

	rep(i, 1, 20) a[i] = 9;

	rep(i, 1, 41){
		rep(j, 0, 25) rep(k, 0, 2009) f[j][k].cnt = -1, f[j][k].sum = 0;
		now = i * i;
		node tmp = dp(len, 0, 1);
		up(cnt, tmp.cnt);
		up(sum, tmp.sum);
	}

	ret.cnt = cnt;
	ret.sum = sum;

	return ret;
}

int main(){


	p[0] = 1ll;
	rep(i, 1, 23) p[i] = p[i - 1] * 10ll % mod;

	ans = solve();
	printf("%lld %lld\n", ans.cnt, ans.sum);
	return 0;
}

