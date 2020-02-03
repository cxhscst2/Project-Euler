#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define MP		make_pair
#define fi		first
#define se		second


typedef long long LL;

const int N = 105;

int ans = 0;
int c[N][N];


int main(){
	
	rep(i, 1, 100){
		rep(j, 1, i) scanf("%d", c[i] + j);
	}


	rep(i, 1, 100){
		rep(j, 1, i){
			c[i][j] += max(c[i - 1][j], c[i - 1][j - 1]);
		}
	}

	rep(i, 1, 100) ans = max(ans, c[100][i]);
	printf("%d\n", ans);
	return 0;
}


