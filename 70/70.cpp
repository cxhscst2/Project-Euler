#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define MP		make_pair
#define fi		first
#define se		second


typedef long long LL;

const int N = 1e7 + 10;

bool not_prime[N];
int prime[N / 10];
int tot;
int phi[N];
int a[12], b[12];
int ans = 0;
double mx = 10000;

bool check(int x){
	int y = phi[x];

	int c1 = 0, c2 = 0;

	for (; x; x /= 10) a[++c1] = x % 10;
	for (; y; y /= 10) b[++c2] = y % 10;


	if (c1 ^ c2) return false;
	sort(a + 1, a + c1 + 1);
	sort(b + 1, b + c1 + 1);
	rep(i, 1, c1) if (a[i] ^ b[i]) return false;

	return true;
}

	

int main(){

	phi[1] = 1;
	rep(i, 2, 1e7){
		if (!not_prime[i]) prime[++tot] = i, phi[i] = i - 1;
		for (int j = 1; j <= tot && i * prime[j] <= 1e7; j++){
			not_prime[i * prime[j]] = 1;
			if (i % prime[j] == 0){
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			phi[i * prime[j]] = phi[i] * (prime[j] - 1);
		}
	}


	rep(i, 2, 1e7){
		if (check(i)){
		//	printf("%d\n", i);
			if (1.00 * i / phi[i] < mx){
				mx = 1.00 * i / phi[i];
				ans = i;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}


