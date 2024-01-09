#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Mọi số nguyên dương N đều có thể phân tích thành tổng các bình phương của các số nhỏ hơn N. Ví dụ số 100 = 10^2 
	  hoặc 100 = 5^2 + 5^2 + 5^2 + 5^2. Cho số nguyên dương N. Nhiệm vụ của bạn là tìm số lượng ít nhất các số nhỏ hơn N 
	  mà có tổng bình phương bằng N.

	- Input Format: Một số tự nhiên N được viết trên 1 dòng.

	- Output Format: Đưa ra kết quả của bài toán.

	- Constraints: 1≤N≤10000;

	- IP1: 100

	- OP1: 1
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++) dp[i] = i;
    for (int i = 1; i <= n; i++) {
    	for (int j = 0; j <= sqrt(i); j++) {
    		dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	cout << dp[n];
    return 0;
}