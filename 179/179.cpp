#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define MP		make_pair
#define fi		first
#define se		second


typedef long long LL;

const int N = 1e7 + 10;

int c[N];
int ans = 0;


int main(){

	rep(i, 1, 1e7){
		for (int j = i; j <= 1e7; j += i){
			++c[j];
		}
	}


	rep(i, 2, 1e7 - 1) if (c[i] == c[i + 1]) ++ans;
	printf("%d\n", ans);
	return 0;
}


