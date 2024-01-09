#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
#define pii pair<int,int>
int mod = 1e9+7;

/*
	- Cho bàn cờ A cỡ nxn, một con mã ở ô (s, t) muốn di chuyển sang ô (u, v). Hãy tìm số bước tối thiểu để con mã có thể đến
	  ô (u, v) hoặc xác định rằng con mã không thể đi tới nơi. Bàn cờ A được mô tả bằng các giá trị 0, 1, trong đó ô có giá trị
	  1 thì con mã có thể tự do di chuyển đến ô này, ngược lại nếu giá trị tại một ô của bàn cơ là 0 thì con mã không thể di 
	  chuyển đến ô này.

	- Input Format: Dòng đầu tiên là số nguyên dương N. Dòng thứ 2 gồm 4 số nguyên s, t, u, v. Dữ liệu đảm bảo ô (s, t) có giá
	  trị 1. N dòng tiếp theo, mỗi dòng gồm N số nguyên mô tả bàn cờ.

	- Output Format: In ra số bước đi tối tiểu của con mã hoặc in ra -1 nếu con mã không thể đi đến nơi.

	- Constraints: 2<=n<=1000; 0<=A[i][j]<=1;

	- IP1:  10
			6 7 8 9
			0 1 1 0 1 0 1 0 1 0 
			1 1 0 0 1 1 0 0 1 0 
			1 1 0 1 1 0 0 1 0 0 
			0 1 1 1 1 1 1 1 1 0 
			0 0 1 0 0 1 1 1 1 1 
			1 1 0 1 1 0 1 0 0 0 
			1 0 0 0 0 1 1 0 1 1 
			1 1 1 1 1 1 1 0 1 1 
			1 0 0 1 1 1 0 1 1 1 
			1 0 0 1 1 0 0 1 0 1 

	- OP1:  4
*/

int n, s, t, u, v;
int a[1001][1001], d[1001][1001];
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

void BFS(int i, int j) {
	a[i][j] = 0;
	queue<pii> q;
	q.push({i, j});
	while(!q.empty()) {
		pii x = q.front(); q.pop();
		int i = x.first, j = x.second;
		for (int k = 0; k < 8; k++) {
			int i1 = i + dx[k], j1 = j + dy[k];
			if (1 <= i1 && i1 <= n && 1 <= j1 && j1 <= n && a[i1][j1]) {
				d[i1][j1] = d[i][j] + 1;
				q.push({i1, j1});
				a[i1][j1] = 0;
			}
		}
	}
}

void solve() {
	cin >> n >> s >> t >> u >> v;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	if (a[u][v] == 0) {
		cout << -1;
		return;
	}
	BFS(s, t);
	if (a[u][v] == 0) {
		cout << d[u][v];
	} else cout << -1;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}