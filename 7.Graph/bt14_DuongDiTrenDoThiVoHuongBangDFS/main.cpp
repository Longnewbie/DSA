#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Hãy tìm đường đi theo thuật toán DFS từ đỉnh s tới
	  đỉnh t. Trong qúa trình mở rộng của thuật toán DFS, luôn ưu tiên mở rộng đỉnh có số thứ tự nhỏ hơn.

	- Input Format: Dòng đầu tiên là 4 số n, m, s, t, tương ứng với số lượng đỉnh, cạnh của đồ thị, đỉnh bắt đầu và đỉnh kết
	  thúc. Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một
	  cạnh của đồ thị.

	- Output Format: In ra đường đi từ s tới t nếu có đường đi, trường hợp không tồn tại đường đi thì in ra -1.

	- Constraints: 1<=s,t<=n<=1000; 1<=m<=n*(n-1)/2;

	- IP1:  5 3 4 3
			4 2
			2 1
			3 1

	- OP1:  4 2 1 3 
*/

vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void DFS(int u) {
	visited[u] = true;
	for (int v : adj[u]) {
		if (!visited[v]) {
			DFS(v);
			parent[v] = u;
		}
	}
}

void path(int s, int t) {
	DFS(s);
	if (!visited[t]) cout << -1;
	else {
		vector<int> res;
		while(t != s) {
			res.pb(t);
			t = parent[t];
		}
		res.pb(s);
		reverse(begin(res), end(res));
		for (int x : res) cout << x << " ";
	}
}

void init() {
	int n, m, s, t; cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		adj[x].pb(y); adj[y].pb(x);
	}
	for (int i = 1; i <= n; i++) sort(begin(adj[i]), end(adj[i]));
	path(s, t);
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    return 0;
}