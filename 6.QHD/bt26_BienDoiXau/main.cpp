#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho hai xâu ký tự str1, str2 bao gồm các ký tự in thường và các thao tác dưới đây: Insert: chèn một ký tự bất kỳ vào str1.
	  Delete: loại bỏ một ký tự bất kỳ trong str1. Replace: thay một ký tự bất kỳ trong str1. Nhiệm vụ của bạn là đếm số các 
	  phép Insert, Delete, Replace ít nhất thực hiện trên str1 để trở thành str2.

	- Input Format: Dòng 1 là xâu str1; Dòng 2 là xâu str2;

	- Output Format: Đưa ra kết quả của bài toán;

	- Constraints: 1<=len(str1), len(str2)<=100;

	- IP1: geek gesek

	- OP1: 1
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s1, s2; cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    s1 = " " + s1; s2 = " " + s2; 
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int i = 0; i <= m; i++) dp[0][i] = i;
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		if (s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1];
    		else dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
		}
	}
	cout << dp[n][m];
    return 0;
}