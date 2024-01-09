#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho đồ thị có hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Hãy xác định xem đồ thị có tồn tại chu trình hay
	  không? Bài này các bạn cài đặt bằng 3 phương pháp : DFS, BFS và DSU.

	- Input Format: Dòng đầu tiên là 2 số n, m, tương ứng với số lượng đỉnh, cạnh của đồ thị. Các đỉnh của đồ thị được đánh số
	  từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

	- Output Format: In ra 1 nếu đồ thị tồn tại chu trình, ngược lại in ra 0. 

	- Constraints: 1=<=n<=1000; 1<=m<=n*(n-1)/2;

	- IP1:  10 13
			6 5
			6 3
			6 1
			6 2
			9 5
			3 9
			9 7
			3 7
			3 2
			6 7
			6 9
			3 5
			6 8

	- OP1:  0
	
	- IP2:  10 16
			9 10
			6 4
			6 1
			6 3
			9 2
			3 9
			9 4
			3 8
			3 5
			6 7
			6 10
			9 6
			6 8
			3 7
			6 5
			9 7

	- OP2:  1
	
	- IP3:  6 6
			1 5
			5 2
			5 3
			3 4
			4 5
			1 6

	- OP3:  1
*/

int color[1001], ok;
vector<int> adj[1001];
bool visited[1001];

void DFS(int u) {
	color[u] = 1;
	for (int v : adj[u]) {
		if (color[v] == 1) {
			ok = 1;
			return;
		} else DFS(v);
	}
	color[u] = 2;
}

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		adj[x].pb(y);
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			DFS(i);
		}
	}
	cout << ok;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}