#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho 2 số nguyên L, R, hãy đếm xem trong đoạn từ L tới R có bao nhiêu số nguyên tố.
	  +) Bước 1 : Sàng số nguyên tố.
	  +) Bước 2 : Gọi F[i] là số các nguyên tố từ 0 tới i, khi đó số các số nguyên tố từ L tới R là F[R] - F[L - 1].

	- Input Format: +) Dòng 1 là số bộ test T.
					+) T dòng tiếp theo mỗi dòng là 2 số nguyên không âm L, R.

	- Output Format: Đưa ra kết quả của mỗi test trên 1 dòng.	

	- Constraints: +) 1<=T<=10000.
				   +) 0<=L<=R<=10^6.

	- IP1:  3 19
			4 65
			4 44
			1 17
			1 7

	- OP1:  7
			16
			12
			7
			4
*/

int P[1000001];
void sieve() {
    for (int i = 1; i <= 1000000; i++) P[i] = 1;
    P[0] = P[1] = 0;
    int can = sqrt(1000000);
    for (int i = 2; i <= can; i++) {
        if (P[i]) {
            for (int j = i * i; j <= 1000000; j+=i) {
                P[j] = 0;
            }
        }
    }
}

int dp[1000001];

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int cnt = 0;
    for (int i = 2; i <= 1000000; i++) {
    	if (P[i]) cnt++;
    	dp[i] = cnt;
	}
	int t; cin >> t;
	while(t--) {
		int l, r; cin >> l >> r;
		if (l == 0) cout << dp[r] << "\n";
		else cout << dp[r] - dp[l - 1] << "\n";
	}
    return 0;
}