#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho dãy số Tribonacci 
	  với F[0] = 0, F[1] = 0, F[2] = 1, F[n] = F[n - 1] + F[n - 2] + F[n - 3] với n >= 3. Hãy tính F[n] chia dư cho 10^9 + 7.

	- Input Format: +) Dòng 1 là số bộ test T.
					+) T dòng tiếp theo mỗi dòng là 1 số nguyên không âm N.

	- Output Format: Đưa ra kết quả của mỗi test trên 1 dòng.

	- Constraints: +) 1<=T<=10000.
				   +) 0<=N<=10^6.

	- IP1:  7
			8
			14
			12
			7
			9
			7
			12

	- OP1:  24
			927
			274
			13
			44
			13
			274
*/

ll dp[1000006];

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    dp[0] = dp[1] = 0; dp[2] = 1;
    for (int i = 3; i <= 1000000; i++) {
    	dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    	dp[i] %= mod;
	}
	int q; cin >> q;
	while(q--) {
		int n; cin >> n;
		cout << dp[n] << "\n";
	}
    return 0;
}