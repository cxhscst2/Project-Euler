#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define MP		make_pair
#define fi		first
#define se		second


typedef long long LL;

const int N = 20;
const int M = 1e8 + 10;
const int Q = 7e6;

bitset <M> c;
int n = 1e8;
int f[N];
int p[Q];
int cnt = 0;
int v;
int now;
int fuck = 0;

double t;

vector <int> a;
set <string> s;


void dfs(int x, int y){
	if (x > 9){
		if (y > 1e8) return;
		if (c[y]) return;
		a.push_back(y);
		vector <int> b;
		for (auto u : a) b.push_back(u);
		sort(b.begin(), b.end());
		string ss = "";
		for (auto u : b) ss = ss + to_string(u) + " ";
		s.insert(ss);
		a.pop_back();
		return;
	}


	dfs(x + 1, y * 10 + f[x]);
	if (!c[y]){
		a.push_back(y);
		dfs(x + 1, f[x]);
		a.pop_back();
	}
}



int main(){

	t = clock();

	cnt = 0;
	c[1] = 1;
	rep(i, 2, n){
		if (!c[i]) p[++cnt] = i;
		rep(j, 1, cnt){
			v = i * p[j];
			if (v > n) break;
			c[v] = 1;
			if (i % p[j] == 0) break;
		}
	}

	rep(i, 1, 9) f[i] = i;

	do{
		now = 0;
		dfs(2, f[1]);


	} while (next_permutation(f + 1, f + 10));

	printf("%d\n", (int)s.size());
	t = clock() - t;
	puts("---------------------------");
	printf("time used : %.3fs\n", t / 1000); 
	return 0;
}


