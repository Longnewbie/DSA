#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho ma trận vuông A[][] kích thước N x N. Nhiệm vụ của bạn là hãy tính ma trận A^K với K là số nguyên cho trước. Sau đó,
	  tính tổng các phần tử của cột cuối cùng. Đáp số có thể rất lớn, hãy in ra kết quả theo modulo 10^9+7.

	- Input Format: Dòng đầu tiên chứa 2 số nguyên dương N và K; N dòng tiếp theo là các phần tử trong ma trận A.

	- Output Format: In ra đáp án của bài toán theo yêu cầu.

	- Constraints: 1<=N<=10; 1<=K<=10^9; 0<=A[i][j]<=1000.

	- IP1: 2 2
		   216 71 
		   923 906  

	- OP1: 966031
*/

int n, k;

struct Matrix {
	ll a[12][12];
	friend Matrix operator * (Matrix x, Matrix y) {
		Matrix res;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				res.a[i][j] = 0;
				for (int k = 1; k <= n; k++) {
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
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> x.a[i][j];
        }
    }
    Matrix Y = binpow(x, k);
    ll res = 0;
    for (int i = 1; i <= n; i++) {
    	res += Y.a[i][n];
    	res %= mod;
	}
	cout << res;
    return 0;
}