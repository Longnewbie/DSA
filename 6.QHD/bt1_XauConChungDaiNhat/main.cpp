#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho 2 xâu kí tự S và T, hãy tìm xâu con chung dài nhất của S và T. Các kí tự của xâu con không nhất thiết phải liền
	  kề nhau.

	- Input Format: Dòng đầu tiên là xâu S; Dòng thứ 2 là xâu T;

	- Output Format: In ra độ dài xâu con chung dài nhất của S và T.

	- Constraints: S và T chỉ gồm các chữ cái in hoa và có độ dài không quá 1000.

	- IP1:  ZHFTDFHF
			TFISHROV

	- OP1: 3
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
    	for (int j = 1; j <= m; j++) {
    		if (s[i] == t[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
    		else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[n][m];
    return 0;
}