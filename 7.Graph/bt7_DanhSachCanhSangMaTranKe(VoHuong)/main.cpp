#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho đồ thị vô hướng G = được biểu diễn dưới dạng danh sách cạnh. Hãy chuyển đổi đồ thị dưới dạng danh sách cạnh này 
	  sang ma trận kề tương ứng.

	- Input Format: Dòng đầu tiên là 2 số n và m, tương ứng với số lượng đỉnh và cạnh của đồ thị. Các đỉnh của đồ thị được
	  đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v tương ứng với một cạnh của đồ thị. 

	- Output Format: In ra ma trận kề theo mẫu.

	- Constraints: 1<=n<=1000; 1<=m<=n*(n-1)/2;

	- IP1:  5 4
			4 3
			3 1
			4 2
			5 4

	- OP1:  0 0 1 0 0 
			0 0 0 1 0 
			1 0 0 1 0 
			0 1 1 0 1 
			0 0 0 1 0 
*/

int a[1001][1001];

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
    	int x, y; cin >> x >> y;
    	a[x][y] = a[y][x] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
    return 0;
}