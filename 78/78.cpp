#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define MP		make_pair
#define fi		first
#define se		second


typedef long long LL;

const int mod = 1e6;

int f[101000];
double t = 0;


inline void up(int &x, int y){
	x += y;
	if (x >= mod) x -= mod;
}


int main(){

	t = clock();

	f[0] = 1;
	rep(i, 1, 6e4) rep(j, i, 6e4) up(f[j], f[j - i]);
	rep(i, 1, 6e4) if (!f[i]) printf("%d\n", i);

	t = clock() - t;
	puts("---------------------------");
	printf("time used : %.3fs\n", t / 1000);
	return 0;
}


