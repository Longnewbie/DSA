#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Tìm số Fibonacci thứ N sau khi chia dư kết quả cho 10^9 + 7

	- Input Format: Dòng duy nhất chứa số nguyên dương N;

	- Output Format: In ra đáp án của bài toán.

	- Constraints: 1<=N<=10^10.

	- IP1: 58

	- OP1: 286725742
	
	- IP2: 36

	- OP2: 14930352
*/

struct Matrix {
	ll a[2][2];
	friend Matrix operator * (Matrix x, Matrix y) {
		Matrix res;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				res.a[i][j] = 0;
				for (int k = 0; k < 2; k++) {
					res.a[i][j] += x.a[i][k] * y.a[k][j];
					res.a[i][j] %= mod;
				}
			}
		}
		return res;
	}
};

Matrix binpow(Matrix a, ll n) {
	if (n == 1) return a;
	Matrix res = binpow(a, n/2);
	if (n % 2 == 0) return res * res;
	else return res * res * a; 
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n; cin >> n;
    Matrix x;
    x.a[0][0] = x.a[0][1] = x.a[1][0] = 1;
    x.a[1][1] = 0;
    Matrix Y = binpow(x, n);
    cout << Y.a[0][1];
    return 0;
}