#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho xâu S chỉ bao gồm các ký tự viết thường và dài không quá 1000 ký tự. Hãy tìm xâu con đối xứng dài nhất của S.

	- Input Format: Dòng duy nhất chứa xâu S.

	- Output Format: In ra đáp án của bài toán.

	- Constraints: 1<=len(S)<=1000;

	- IP1: edhcgeehahbbeggfcgcchffbffcgfghgc

	- OP1: 5
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    int dp[n + 1][n + 1];
    for (int i = 1; i <= n; i++) dp[i][i] = 1;
    int res = 0;
    for (int len = 2; len <= n; len++) {
    	for (int i = 1; i <= n - len + 1; i++) {
    		int j = i + len - 1;
    		if (len == 2) dp[i][j] = (s[i] == s[j]);
    		else dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
    		if (dp[i][j]) res = max(res, len);
		}
	}
	cout << res;
    return 0;
}