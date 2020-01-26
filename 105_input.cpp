#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define MP		make_pair
#define fi		first
#define se		second


typedef long long LL;

const int N = 1e3 + 10;

char s[N];
int n, co;


int main(){

	while (~scanf("%s", s + 1)){
		n = strlen(s + 1);
		co = 0;
		rep(i, 1, n) co += (s[i] == ',');
		rep(i, 1, n) if (s[i] == ',') s[i] = ' ';
		printf("%d\n", co + 1);
		rep(i, 1, n) printf("%c", s[i]);
		putchar(10);
	}

	return 0;
}


