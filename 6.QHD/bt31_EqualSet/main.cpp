#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Nhiệm vụ của bạn là đếm số cách các số 1,2,…, n có thể chia thành hai tập có tổng bằng nhau. Các phần tử trong tập không 
	  xét đến thứ tự Ví dụ, nếu n = 7, có bốn nghiệm: {1,3,4,6} và {2,5,7}. {1,2,5,6} và {3,4,7}. {1,2,4,7} và {3,5,6}. {1,6,7}
	  và {2,3,4,5}.

	- Input Format: Dòng duy nhất chứa số nguyên dương n.

	- Output Format: In ra kết quả sau khi chia dư với 10^9 + 7.

	- Constraints: 1<=n<=500.

	- IP1: 7

	- OP1: 4
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int s = n*(n + 1)/2;
    if (s % 2 == 1) {
    	cout << 0;
    	return 0;
	}
	s /= 2;
	int dp[150000];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	int res;
	for (int i = 1; i <= n; i++) {
		for (int j = s; j >= 1; j--) {
			if (j >= i) {
				dp[j] = dp[j] + dp[j - i];
				dp[j] %= mod;
				if (j == s && i == n) res = dp[j - i];
			}
		}
	}
	cout << res;
    return 0;
}