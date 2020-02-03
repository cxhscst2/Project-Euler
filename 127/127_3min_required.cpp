#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define MP		make_pair
#define fi		first
#define se		second


typedef long long LL;

const int N = 2e5 + 10;
const int n = 120000;

double t;
int c[N];
int val[N];
int rad[N];
int skip = 0;
int ans = 0;
vector <int> p[N];


void init(){

	rep(i, 1, n) val[i] = i;
	rep(i, 2, n) if (!c[i]){
		for (int j = i * 2; j <= n; j += i){
			c[j] = 1;
	 		int cnt = 0;
			while (val[j] % i == 0) val[j] /= i, ++cnt;
			p[j].push_back(i);
		}
	}

	rep(i, 2, n) if (val[i] > 1)
		p[i].push_back(i);
}

inline int gcd(int a, int b){ return b == 0 ? a : gcd(b, a % b);}


int main(){

	t = clock();


	init();


	rep(i, 1, n){
		rad[i] = 1;
		for (auto u : p[i]) rad[i] *= u;
	}

	rep(c, 1, n){
		if (rad[c] == c) continue;
		rep(a, 1, c){
			int b = c - a;
			if (a >= b) break;
			if (gcd(a, c) > 1) continue;
			if (1ll * rad[a] * rad[b] * rad[c] < 1ll * c) ans += c;
		}
	}

	printf("%d\n", ans);

	t = clock() - t;
	puts("---------------------------");
	printf("time used : %.3fs\n", t / 1000); 
	return 0;
}


