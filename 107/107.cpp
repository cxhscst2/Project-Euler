#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define MP		make_pair
#define fi		first
#define se		second


typedef long long LL;

struct node{
	int x, y, z;
	friend bool operator < (const node &a, const node &b){
		return a.z < b.z;
	}
} e[101010];

int n;
int all = 0;
int cnt = 0;
int father[1010];
int fg = 0;

int getfather(int x){
	return father[x] ? father[x] = getfather(father[x]) : x;
}

inline void add(int x, int y, int z){
	e[++cnt].x = x;
	e[cnt].y = y;
	e[cnt].z = z;
}

int ans = 0;


int main(){

	freopen("1.txt", "r", stdin);
	freopen("11.txt", "w", stdout);

	n = 40;

	rep(i, 1, n){
		rep(j, 1, n){
			int x;
			scanf("%d", &x);
			if (i >= j) continue;
			if (x == -1) continue;

			all += x;
			add(i, j, x);

			
		}
	}

	sort(e + 1, e + cnt + 1);

	rep(i, 1, cnt){
		int fx = getfather(e[i].x), fy = getfather(e[i].y);

		if (fx ^ fy){
			father[fx] = fy;
			ans += e[i].z;
			++fg;
		}
	}


	printf("%d\n", all - ans);
	return 0;
}


