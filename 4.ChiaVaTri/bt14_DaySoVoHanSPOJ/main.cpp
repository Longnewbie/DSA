#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Dãy số nguyên dương vô hạn A[] được định nghĩa một cách đệ quy như sau: A[0] = 0; A[1] = 1; A[i] = A[i-1] + A[i-2] với
	  mọi n ≥ 2. Cho số nguyên dương N không quá 10^9. Hãy xác định số thứ N trong dãy A[].

	- Input Format: Dòng duy nhất chứa số nguyên dương N.

	- Output Format: In ra đáp án của bài toán sau khi chia dư cho 1e9 + 7.

	- Constraints: 1<=N<=10^9.

	- IP1: 7 

	- OP1: 13
	
	- IP2: 999992343 

	- OP2: 865905443
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

Matrix binpow(Matrix a, int n) {
	if (n == 1) return a;
	Matrix res = binpow(a, n/2);
	if (n % 2 == 0) return res * res;
	else return res * res * a;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    Matrix x;
    x.a[0][0] = x.a[0][1] = x.a[1][0] = 1;
    x.a[1][1] = 0;
    Matrix Y = binpow(x, n);
    cout << Y.a[0][1];
    return 0;
}