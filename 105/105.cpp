#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define MP		make_pair
#define fi		first
#define se		second


typedef long long LL;

const int N = 20;
const int M = 1 << 14 | 100;


int n;
int a[N];
int b[M], c[M];


int judge(){
	memset(c, 0, sizeof c);
	int all = 1 << n;

	rep(i, 1, all - 1){
		rep(j, 0, n - 1){
			if ((i >> j) & 1) c[i] += a[j];
		}
	}

	rep(i, 1, all - 1){
		rep(j, i + 1, all - 1){
			if ((i & j) == 0){
				if ((b[i] < b[j] && c[i] > c[j]) || (b[i] > b[j] && c[i] < c[j]))
					return 0;
				
				if (c[i] == c[j])
					return 0;
			}
		}
	}

	return c[all - 1];
}

int ans = 0;

int main(){

	rep(i, 1, M >> 1) b[i] = __builtin_popcount(i);

	while (~scanf("%d", &n)){
		memset(a, 0, sizeof a);
		rep(i, 0, n - 1) scanf("%d", a + i);
		ans += judge();
	}

	printf("%d\n", ans);
	return 0;
}


