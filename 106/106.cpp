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
int b[M];
int c[N], d[N];



int judge(int n){
	int ret = 0;
	int all = 1 << n;
	rep(i, 1, all - 1){
		rep(j, i + 1, all - 1){
			if ((i & j) == 0){
				if (b[i] ^ b[j]) continue;
				if (b[i] == 1) continue;

				int c1 = 0, c2 = 0;
				rep(k, 0, 12) if ((i >> k) & 1) c[++c1] = k;
				rep(k, 0, 12) if ((j >> k) & 1) d[++c2] = k;

				int fg = 0;
				rep(k, 1, c1) if (c[k] > d[k]){
					fg = 1;
					break;
				}

				if (fg) ++ret;
			}
		}
	}
	return ret;
}

int main(){

	rep(i, 1, M >> 1) b[i] = __builtin_popcount(i);
	rep(i, 4, 12) printf("%d\n", judge(i));
	return 0;
}


