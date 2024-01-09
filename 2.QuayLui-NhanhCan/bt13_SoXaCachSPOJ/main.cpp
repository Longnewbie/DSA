#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho số nguyên dương N (2 < N <10). Một số nguyên dương K có N chữ số được gọi là số xa cách nếu thỏa mãn: K không chứa 
	  chữ số 0. Tất cả các chữ số từ 1 đến N đều xuất hiện trong K đúng 1 lần. Không có hai chữ số liên tiếp nào trong K có
	  hiệu bằng 1.

	- Input Format: 1 dòng duy nhất chứa số nguyên dương N.

	- Output Format: In ra các số thỏa mãn theo thứ tự tăng dần.

	- Constraints: 3<=N<=9

	- IP1: 4

	- OP1: 2413
		   3142
*/

int n, a[101], used[101];

void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (!used[j] && j != a[i - 1] - 1 && j != a[i - 1] + 1) {
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
    a[0] = -1;
    Try(1);
    return 0;
}