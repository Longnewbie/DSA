#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho ma trận A[][] là ma trận vuông cỡ N x N. Hãy tính kết quả A^K và chia dư các phần tử trong ma trận kết quả cho 
	  10^9 + 7

	- Input Format: Dòng đầu tiên chứa 2 số nguyên dương N và K; N dòng tiếp theo là các phần tử trong ma trận A.

	- Output Format: In ra ma trận đáp án.

	- Constraints: 1<=N<=10; 1<=K<=10^9; 0<=A[i][j]<=1000.

	- IP1: 2 3
		   712 141 
		   55 619 

	- OP1: 376787593 188740908 
		   73622340 252298909 
*/

int n, k;

struct Matrix {
	ll a[10][10];
	friend Matrix operator * (Matrix x, Matrix y) {
		Matrix res;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				res.a[i][j] = 0;
				for (int k = 0; k < n; k++) {
					res.a[i][j] += x.a[i][k] * y.a[k][j];
					res.a[i][j] %= mod;
				}
			}
		}
		return res;
	}
};

Matrix binpow(Matrix x, int n) {
	if (n == 1) return x;
	Matrix a = binpow(x, n/2);
	if (n % 2 == 0) return a * a;
	else return a * a * x;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    Matrix x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x.a[i][j];
        }
    }
    Matrix Y = binpow(x, k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << Y.a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}