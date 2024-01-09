#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Một con ếch có thể nhảy 1, 2, 3 bước để có thể lên đến một đỉnh cần đến. Hãy đếm số các cách con ếch có thể nhảy đến đỉnh.

	- Input Format: Số nguyên dương N mô tả số bước con ếch cần di chuyển để nhảy tới đỉnh.

	- Output Format: In ra kết quả của bài toán.

	- Constraints: 1<=N<=40.

	- IP1: 5

	- OP1: 13
	
	- IP2: 10

	- OP2: 274
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1; dp[1] = 1; dp[2] = 2;
    for (int i = 3; i <= n; i++) {
    	dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
    cout << dp[n];
    return 0;
}