#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho số nguyên dương N. Nhiệm vụ của bạn là hãy liệt kê tất cả các hoán vị của các số từ 1 tới N theo thứ tự.

	- Input Format: Dòng duy nhất chứa số nguyên dương N.

	- Output Format: In ra các hoán vị của N phần tử theo thứ tự.

	- Constraints: 1<=N<=10;

	- IP1:  3

	- OP1:  123
			132
			213
			231
			312
			321
*/

int n, a[101], used[101];

void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (!used[j]) {
			used[j] = 1;
			a[i] = j;
			if (i == n) {
				for (int u = 1; u <= n; u++) cout << a[u];
				cout << "\n";
			} else Try(i + 1);
			used[j] = 0;
		}
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    Try(1);
    return 0;
}
