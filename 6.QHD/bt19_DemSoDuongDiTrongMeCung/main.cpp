#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho mê cung được mô tả bởi một ma trận kí tự gồm N hàng và N cột. Mỗi ô trên ma trận chứa kí tự '.' tương ứng với đường 
	  đi và dấu * tương ứng với bẫy. Một con chuột muốn đi từ ô (1, 1) tới ô (N, N) và chỉ được di chuyển khi một ô nào đó là 
	  đường đi và nó được di chuyển sang phải hoặc xuống dưới. Hãy đếm số cách con chuột có thể di chuyển tới đích. Vì kết quả
	  quá lớn nên hãy lấy dư với 10^9 + 7.

	- Input Format: Dòng đầu tiên là N; N dòng tiếp theo mỗi dòng là N kí tự.

	- Output Format: Số đường đi tối đa.

	- Constraints: 1<=N<=1000.

	- IP1:  4
			....
			.*..
			...*
			*...

	- OP1: 3
*/

char a[1002][1002];
int dp[1002][1002];

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    		cin >> a[i][j];
		}
	}
	dp[0][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == '.') {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				dp[i][j] %= mod;
			} else dp[i][j] = 0;
		}
	}
	cout << dp[n][n];
    return 0;
}