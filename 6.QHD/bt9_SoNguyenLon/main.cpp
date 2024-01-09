#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho hai số nguyên lớn N và M có không quá 1000 chữ số. Người ta muốn tính xem liệu có thể lấy ra nhiều nhất bao nhiêu chữ
	  số trong N (không cần liên tiếp) và giữ nguyên thứ tự của nó để tạo ra một số X sao cho ta cũng có thể tìm thấy X trong
	  số M theo cách tương tự.

	- Input Format: Dòng thứ nhất ghi số N, dòng thứ 2 ghi số M.

	- Output Format: In ra số chữ số nhiều nhất có thể của X.

	- Constraints: 1<=len(N), len(M) <= 1000.

	- IP1:  82619136359
			5572555993152891122

	- OP1: 	5
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    s = " " + s; t = " " + t;
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
    	for (int j = 1;  j<= m; j++) {
    		if (s[i] == t[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
    		else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[n][m];
    return 0;
}