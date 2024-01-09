#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho dãy số Fibonacci với F[0] = 0, F[1] = 1, F[n] = F[n - 1] + F[n - 2] với n >= 2. Hãy tính F[n] chia dư cho 10^9 + 7.

	- Input Format: +) Dòng 1 là số bộ test T.
					+) T dòng tiếp theo mỗi dòng là 1 số nguyên không âm N.

	- Output Format: Đưa ra kết quả của mỗi test trên 1 dòng.

	- Constraints: +) 1<=T<=10000.
				   +) 0<=N<=10^6.

	- IP1:  6
			5
			13
			10
			14
			8
			11

	- OP1:  5
			233
			55
			377
			21
			89
*/

ll F[1000001]; 

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        F[0] = 0; F[1] = 1;
        for (int i = 2; i <= 1000000; i++) {
        F[i] = ((F[i - 1] % mod) + ((F[i - 2] % mod))) % mod;
    }
    int q; cin >> q;
    while(q--) {
        int n; cin >> n;
        cout << F[n] << endl;
    }
    return 0;
} 