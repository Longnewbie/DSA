#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho một hình chữ nhật a × b, nhiệm vụ của bạn là cắt nó thành các hình vuông. Trên mỗi lần cắt, bạn có thể chọn một hình
	  chữ nhật và cắt nó thành hai hình chữ nhật sao cho tất cả độ dài các cạnh vẫn là số nguyên. Số lần di cắt tối thiểu có
	  thể là bao nhiêu ?

	- Input Format: Dòng duy nhất chứa 2 số nguyên a và b.

	- Output Format: In ra số lần cắt tối thiểu.

	- Constraints: 1<=a,b<=500;

	- IP1: 3 5

	- OP1: 3
*/

int F[501][501];

int solve(int n, int m) {
	if (n == m) return 0;
	if (F[n][m]) return F[n][m];
	int res = 1e9;
	for (int i = 1; i < m; i++) {
		int tmp = solve(n, i) + solve(n, m - i) + 1;
		res = min(res, tmp);
	}
	for (int i = 1; i < n; i++) {
		int tmp = solve(i, m) + solve(n - i, m) + 1;
		res = min(res, tmp);
	}
	F[n][m] = F[m][n] = res;
	return res;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    cout << solve(n, m);
    return 0;
}