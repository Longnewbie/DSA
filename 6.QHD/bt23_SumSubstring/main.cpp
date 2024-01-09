#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho một số tự nhiên N được biểu diễn như một xâu kí tự, bạn hãy tính tổng của tất cả các số tạo bởi các xâu con liên tiếp
	  của N, ví dụ N = 235 thì ta có tổng = 2 + 3 + 5 + 23 + 35 + 235.

	- Input Format: Dòng duy nhất chứa số nguyên dương N.

	- Output Format: In ra kết quả của bài toán.

	- Constraints: 1<=N<=10^12.

	- IP1: 1807

	- OP1: 2915
	
	- IP2: 235

	- OP2: 303
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    ll dp[s.size() + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = s[0] - '0';
    for (int i = 1; i < s.size(); i++) {
    	dp[i] = dp[i - 1] * 10 + (s[i] - '0') * (i + 1);
	}
	cout << accumulate(dp, dp + s.size(), 0ll);
    return 0;
}