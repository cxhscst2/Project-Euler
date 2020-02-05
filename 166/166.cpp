#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define MP		make_pair
#define fi		first
#define se		second


typedef long long LL;

int ans = 0;
int c[61][1010][5];
int et[61];

double t = 0;


void solve(int x){
	rep(i, 1, et[x]){
		rep(j, 1, et[x]){
			rep(k, 1, et[x]){
				int A = x - c[x][i][1] - c[x][j][1] - c[x][k][1];
				int B = x - c[x][i][2] - c[x][j][2] - c[x][k][2];
				int C = x - c[x][i][3] - c[x][j][3] - c[x][k][3];
				int D = x - c[x][i][4] - c[x][j][4] - c[x][k][4];


				if (A < 0 || B < 0 || C < 0 || D < 0 || A > 9 || B > 9 || C > 9 || D > 9) continue;
				if (A + B + C + D != x) continue;
				if (c[x][i][1] + c[x][j][2] + c[x][k][3] + D != x) continue;
				if (c[x][i][4] + c[x][j][3] + c[x][k][2] + A != x) continue;

				++ans;
/*
				if (c[x][i][1] == 6 && c[x][i][2] == 3 && c[x][i][3] == 3 &&  c[x][i][4] == 0 
						&& c[x][j][1] == 5 && c[x][j][2] == 0 && c[x][j][3] == 4 &&  c[x][j][4] == 3 
				    )
				{
					printf("%d%d%d%d\n%d%d%d%d\n%d%d%d%d\n%d%d%d%d\n", c[x][i][1], c[x][i][2], c[x][i][3], c[x][i][4], 
							c[x][j][1], c[x][j][2], c[x][j][3], c[x][j][4], 
							c[x][k][1], c[x][k][2], c[x][k][3], c[x][k][4],
							A, B, C, D);
					putchar(10);
				

				}*/
			}
		}
	}
}


int main(){

	t = clock();

	rep(i, 0, 9) rep(j, 0, 9) rep(k, 0, 9) rep(l, 0, 9)
	{

		int s = i + j + k + l;
		++et[s];

		c[s][et[s]][1] = i;
		c[s][et[s]][2] = j;
		c[s][et[s]][3] = k;
		c[s][et[s]][4] = l;
	}


	rep(i, 0, 36) solve(i);

	printf("%d\n", ans);

	t = clock() - t;
	puts("---------------------------");
	printf("time used : %.3fs\n", t / 1000);
	return 0;
}


