#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho ba xâu ký tự X, Y, Z. Nhiệm vụ của bạn là tìm độ dài dãy con chung dài nhất có mặt trong cả ba xâu.

	- Input Format: 3 dòng lần lượt chứa X, Y, Z;

	- Output Format: In ra độ dài của xâu con chung dài nhất của 3 xâu.

	- Constraints: 1<=len(X), len(Y), len(Z) <= 100;

	- IP1:  AGLEHHGE
			GLGHLALB
			DDLBLEHGD

	- OP1: 	2
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string x, y, z; cin >> x >> y >> z;
    int n = x.size(), m = y.size(), v = z.size();
	x = " " + x; y = " " + y; z = " " + z;
	int dp[n + 1][m + 1][v + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= v; k++) {
				if (x[i] == y[j] && y[j] == z[k]) dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				else dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
			}
		}
	}
	cout << dp[n][m][v]; 
    return 0;
}