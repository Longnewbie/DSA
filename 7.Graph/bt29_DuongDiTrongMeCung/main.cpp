#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
#define ii pair<int,int>
int mod = 1e9+7;

/*
	- Cho mê cung A có n hàng, n cột. Một con chuột xuất phát từ ô (s, t) và di chuyển tới ô (u, v). Nhiệm vụ của bạn là xác
	  định số bước đi tối thiểu để con chuột con thể di chuyển từ ô (s, t) tới ô (u, v) hoặc xác định rằng không thể tìm được
	  đường tới ô (u, v). Mê cung A chỉ bao gồm các số 1 hoặc 0. Trong đó 1 đại diện cho đường đi và 0 đại diện cho vật cản,
	  con chuột chỉ có thể di chuyển từ ô hiện tại sang các ô chung đỉnh với nó và có đường đi.

	- Input Format: Dòng đầu tiên là số nguyên dương N. Dòng thứ 2 gồm 4 số nguyên s, t, u, v. Dữ liệu đảm bảo ô (s, t) có giá
	  trị 1. N dòng tiếp theo, mỗi dòng gồm N số nguyên mô tả mê cung A.

	- Output Format: In ra số bước đi tối tiểu của con chuột hoặc in ra -1 nếu con chuột không thể đi đến nơi.

	- Constraints: 2<=n<=1000; 0<=A[i][j]<=1;

	- IP1:  10
			9 6 9 3
			1 1 0 1 1 1 1 0 0 1 
			0 0 1 0 0 1 0 1 0 1 
			1 1 1 1 0 0 0 1 1 0 
			1 0 0 0 1 0 0 0 1 1 
			1 0 1 0 0 1 0 1 1 0 
			0 0 1 1 0 1 0 0 0 0 
			1 1 0 1 0 1 1 0 0 0 
			0 0 0 1 1 0 1 1 0 1 
			1 0 1 0 0 1 0 0 1 1 
			0 1 1 1 1 0 1 0 1 1 

	- OP1:  3
*/

int n, s, t, u, v;
int a[1001][1001], d[1001][1001];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void BFS(int i, int j) {
	a[i][j] = 0;
	queue<ii> q;
	q.push({i, j});
	while(!q.empty()) {
		ii x = q.front(); q.pop();
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
		cout << "-1";
		return;
	}
	BFS(s, t);
	if (a[u][v] == 0) {
		cout << d[u][v];
	} else cout << "-1";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}