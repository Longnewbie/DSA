#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Một chiếc cầu thang có N bậc. Mỗi bước, bạn được phép bước lên trên tối đa K bước. Hỏi có tất cả bao nhiêu cách bước để
	  đi hết cầu thang? (Tổng số bước đúng bằng N).

	- Input Format: Dòng duy nhất chứa 2 số nguyên N và K.

	- Output Format: In ra đáp án tìm được trên một dòng theo modulo 10^9+7.

	- Constraints: 1<=N<=100000; 1<=K<=100;

	- IP1: 7 3

	- OP1: 44
	
	- IP2: 4 2

	- OP2: 5
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= min(i, k); j++) {
    		dp[i] += dp[i - j];
    		dp[i] %= mod;
		}
	}
	cout << dp[n];
    return 0;
}