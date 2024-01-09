#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho hai số nguyên dương N và K. Nhiệm vụ của bạn là hãy liệt kê tất cả các tập con K phần tử của các số từ 1 tới N.

	- Input Format: 2 số nguyên dương N và K.

	- Output Format: In ra các tổ hợp trên từng dòng.

	- Constraints: 1<=K<=N<=15;

	- IP1:  5 3

	- OP1:  123
			124
			125
			134
			135
			145
			234
			235
			245
			345
*/

int n, k, a[101];

void Try(int i) {
	for (int j = a[i - 1] + 1; j <= n - k + i; j++) {
		a[i] = j;
		if (i == k) {
			for (int u = 1; u <= k; u++) cout << a[u];
			cout << "\n";
		} else Try(i + 1);
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    a[0] = 0;
    Try(1);
    return 0;
}
