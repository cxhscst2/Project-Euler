#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define MP		make_pair
#define fi		first
#define se		second


typedef long long LL;


const int Q = 1010;
const int A = 31;


struct node{ int x, y; } d[Q];

char ch;
char st[A];
bool a[A][A];
bool rr[A][A], cc[A][A], vv[A][A];
bool flag;
int f[A][A], r[A][A], c[A][A], v[A][A];
int num;
int ans = 0;

inline void print(){ ans += (f[1][1] * 100 + f[1][2] * 10 + f[1][3]); }

void dfs(int now){
	if (flag) return;
	if (now > num){flag = true; print(); return ;}
	int x = d[now].x, y = d[now].y;

	if (flag) return;
	rep(i, 1, 9){
		if (vv[v[x][y]][i]) continue;
		if (cc[c[x][y]][i]) continue;
		if (rr[r[x][y]][i]) continue;
		f[x][y] = i;
		vv[v[x][y]][i] = true;
		cc[c[x][y]][i] = true;
		rr[r[x][y]][i] = true;
		dfs(now + 1);
		f[x][y] = 0;
		vv[v[x][y]][i] = false;
		cc[c[x][y]][i] = false;
		rr[r[x][y]][i] = false;
	}
}			

int main(){


	freopen("input.txt", "r", stdin);
	freopen("2.txt", "w", stdout);

	rep(i, 1, 3) rep(j, 1, 3) v[i][j] = 1;
	rep(i, 1, 3) rep(j, 4, 6) v[i][j] = 2;
	rep(i, 1, 3) rep(j, 7, 9) v[i][j] = 3;
	rep(i, 4, 6) rep(j, 1, 3) v[i][j] = 4;
	rep(i, 4, 6) rep(j, 4, 6) v[i][j] = 5;
	rep(i, 4, 6) rep(j, 7, 9) v[i][j] = 6;
	rep(i, 7, 9) rep(j, 1, 3) v[i][j] = 7;
	rep(i, 7, 9) rep(j, 4, 6) v[i][j] = 8;
	rep(i, 7, 9) rep(j, 7, 9) v[i][j] = 9;
	rep(i, 1, 9) rep(j, 1, 9) r[i][j] = i, c[i][j] = j;

	while (~scanf("%s%s", st, st)){
		num = 0;
		memset(f, 0, sizeof f);
		memset(cc, false, sizeof cc);
		memset(vv, false, sizeof vv);
		memset(rr, false, sizeof vv);
		memset(d, 0, sizeof d); 
	
		
		rep(cntx, 1, 9){
			scanf("%s", st);
			rep(cnty, 1, 9)	if (st[cnty - 1] == '0'){
			   	f[cntx][cnty] = 0;
				d[++num].x = cntx, d[num].y = cnty;
			}
			else{
				int np = (int)st[cnty - 1] - 48;
				f[cntx][cnty] = np;
				cc[c[cntx][cnty]][np] = true;
				vv[v[cntx][cnty]][np] = true;
				rr[r[cntx][cnty]][np] = true;
			}	
	
		}


		flag = false;
		dfs(1);

	}

	printf("%d\n", ans);
	return 0;
	
}


