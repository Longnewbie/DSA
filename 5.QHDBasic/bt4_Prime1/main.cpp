#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho số nguyên dương N, hãy đếm xem trong đoạn từ 0 tới N có bao nhiêu số nguyên tố. Hướng dẫn :
	  +) Bước 1 : Sàng số nguyên tố.
	  +) Bước 2 : Gọi F[i] là số lượng các số nguyên tố từ 0 tới i, xây dựng mảng F[i] sau khi sàng.

	- Input Format: +) Dòng 1 là số bộ test T.
					+) T dòng tiếp theo mỗi dòng là 1 số nguyên không âm N.

	- Output Format: Đưa ra kết quả của mỗi test trên 1 dòng.

	- Constraints: +) 1<=T<=10000.
				   +) 0<=N<=10^6.

	- IP1:  5
			39
			68
			26
			87
			6

	- OP1:  12
			19
			9
			23
			3
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

ll dp[1000000];

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int cnt = 0;
    for (int i = 1; i <= 1000000; i++) {
        if (P[i]) {
            cnt++;
        }
        dp[i] = cnt;
    }
    int q; cin >> q;
    while(q--) {
        int n; cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}