#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define MP		make_pair
#define fi		first
#define se		second


typedef unsigned long long LL;

const LL all = ~0ull;
const int M = 1003;

LL a[(M * M * M) >> 6];
long long ans = 0;


inline void set0(int x){
	int p = x >> 6;
	int q = x & 63;

	a[p] &= (all  ^ (1ULL << q));
}

inline void set1(int x){
	int p = x >> 6;
	int q = x & 63;

	a[p] |= (1ULL << q);
}

inline int get(int x){
	int p = x >> 6;
	int q = x & 63;

	return (a[p] >> q) & 1;
}



inline print(LL x){
	dec(i, 63, 0) if (x >> i & 1) putchar(49); else putchar(48);
}

inline getpos(int x, int y, int z){
	int pos = x * M * M + y * M + z;
	if (pos >= M * M * M) assert(1 == 2);
	return pos;
}

inline void go(int x, int y, int z){
	int pos = getpos(x, y, z);
	set1(pos);
}

double t = 0;

int main(){

	t = clock();

	rep(i, 0, 1000){
		rep(j, 0, 1000){
			rep(k, 0, 1000){
				int now = get(getpos(i, j, k));
				if (!now){
					int A = 1000 - i;
					int B = 1000 - j;
					int C = 1000 - k;
					for (int m = A; m; m--) go(i + m, j, k);
					for (int m = B; m; m--) go(i, j + m, k);
					for (int m = C; m; m--) go(i, j, k + m);
					for (int m = min(A, B); m; m--) go(i + m, j + m, k);
					for (int m = min(A, C); m; m--) go(i + m, j, k + m);
					for (int m = min(B, C); m; m--) go(i, j + m, k + m);
					for (int m = min(A, min(B, C)); m; m--) go(i + m, j + m, k + m);
				}
			}
		}
	}

	rep(i, 0, 1000){
		rep(j, i, 1000){
			rep(k, j, 1000){
				if (!get(getpos(i, j, k))) ans += (0ll + i + j + k);
			}
		}
	}


	printf("%lld\n", ans);
	
	
	t = clock() - t;
	puts("---------------------------");
	printf("time used : %.3fs\n", t / 1000); 
	return 0;
}


