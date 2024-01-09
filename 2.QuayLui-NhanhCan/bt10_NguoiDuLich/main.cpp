#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho n thành phố đánh số từ 1 đến n và các tuyến đường giao thông hai chiều giữa chúng, mạng lưới giao thông này được cho
	  bởi mảng C[1…n, 1…n] ở đây C[i][j] = C[j][i] là chi phí đi đoạn đường trực tiếp từ thành phố i đến thành phố j. Một người 
	  du lịch xuất phát từ thành phố 1, muốn đi thăm tất cả các thành phố còn lại mỗi thành phố đúng 1 lần và cuối cùng
	  quay lại thành phố 1. Hãy chỉ ra chi phí ít nhất mà người đó phải bỏ ra.

	- Input Format: Dòng đầu tiên là số nguyên n – số thành phố; n dòng sau, mỗi dòng chứa n số nguyên thể hiện cho mảng 2 
	  chiều C.

	- Output Format: In ra chi phí mà người đó phải bỏ ra.

	- Constraints: 1<=N<=15; 0<=C[i][j]<=100;

	- IP1:  4
			0 85 26 81 
			85 0 77 97 
			26 77 0 26 
			81 97 26 0 

	- OP1: 234
*/

int n, a[101][101], x[101], cmin = 1e9, res = 1e9, used[101];

void Try(int i, int sum) {
	for (int j = 2; j <= n; j++) {
		if (!used[j]) {
			used[j] = 1;
			x[i] = j;
			sum += a[x[i - 1]][x[i]];
			if (i == n) {
				res = min(res, sum + a[x[n]][1]);
			} else if (sum + (n - i) * cmin < res) {
				Try(i + 1, sum);
			}
			used[j] = 0;
			sum -= a[x[i - 1]][x[i]];
		}
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(used, 0, sizeof(used));
    cin >> n;
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    		cin >> a[i][j];
    		if (a[i][j]) cmin = min(cmin, a[i][j]);
		}
	}
	x[1] = 1;
	Try(2, 0);
	cout << res;
    return 0;
}