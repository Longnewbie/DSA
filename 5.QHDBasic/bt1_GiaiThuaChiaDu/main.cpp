#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Đề bài rất đơn giản, bạn hãy tính N! chia dư cho (10^9 + 7).

	- Input Format: +) Dòng 1 là số bộ test T.
					+) T dòng tiếp theo mỗi dòng là 1 số nguyên không âm N.

	- Constraints: +) 1<=T<=10000.
				   +) 0<=N<=10^6.

	- Output Format: Đưa ra kết quả của mỗi test trên 1 dòng

	- IP1: 	5
			11
			6
			8
			10
			13

	- OP1:  39916800
			720
			40320
			3628800
			227020758
*/

ll dp[1000006];

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    dp[1] = 1;
    for (int i = 2; i <= 1000000; i++) {
    	dp[i] = dp[i - 1] * i;
    	dp[i] %= mod;
	}
    int t; cin >> t;
    while(t--) {
    	int n; cin >> n;
    	cout << dp[n] << "\n";
	}
    return 0;
}