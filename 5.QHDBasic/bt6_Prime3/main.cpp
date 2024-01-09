#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho số nguyên dương N, hãy tính tích các số nguyên tố trong đoạn từ 0 đến N.

	- Input Format: +) Dòng 1 là số bộ test T.
					+) T dòng tiếp theo mỗi dòng là 1 số nguyên không âm N.

	- Output Format: Đưa ra kết quả của mỗi test trên 1 dòng, vì kết quả quá lớn nên hãy chia dư cho 10^9 + 7.

	- Constraints: +) 1<=T<=10000.
				   +) 0<=N<=10^6.

	- IP1:  5
		 	20
			16
			10
			22
			29

	- OP1:  9699690
			30030
			210
			9699690
			469693188
*/

int P[1000001];
void sieve() {
	for (int i = 1; i <= 1000000; i++) P[i] = 1;
	P[0] = P[1] = 0;
	int can = sqrt(1000000);
	for (int i = 2; i <= can; i++) {
		for (int j = i * i; j <= 1000000; j+=i) P[j] = 0;
	}
}

ll dp[1000001];

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    ll res = 1;
    for (int i = 2; i <= 1000000; i++) {
    	if (P[i]) {
    		res *= i;
    		res %= mod;
    	}
    	dp[i] = res;
	}
	int q; cin >> q;
	while(q--) {
		int n; cin >> n;
		cout << dp[n] << "\n";
	}
    return 0;
}