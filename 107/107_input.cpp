#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define MP		make_pair
#define fi		first
#define se		second


typedef long long LL;

const int N = 1e5 + 10;

char s[N];


int main(){

	freopen("network.txt", "r", stdin);
	freopen("1.txt", "w", stdout);

	rep(i, 1, 40){
		fgets(s, N, stdin);
		int len = strlen(s);
		rep(j, 0, len - 1){
			if (s[j] == ',') putchar(32);
			else if (s[j] == '-') printf("-1");
			else putchar(s[j]);
		}
	}


	return 0;
}


