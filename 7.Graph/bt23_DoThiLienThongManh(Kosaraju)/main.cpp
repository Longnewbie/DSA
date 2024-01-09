#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho đồ thị có hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Hãy kiểm tra đồ thị có liên thông mạnh hay không?
	  Bài này các bạn thử cài đặt bằng 3 cách là : brute force, thuật toán Tarjan, thuật toán Kosaraju.

	- Input Format: Dòng đầu tiên là 2 số n, m, tương ứng với số lượng đỉnh, cạnh của đồ thị. Các đỉnh của đồ thị được đánh
	  số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

	- Output Format: In ra 1 nếu đồ thị liên thông mạnh, ngược lại in ra 0.

	- Constraints: 1=<=n<=1000; 1<=m<=n*(n-1)/2;

	- IP1:  6 14
			3 4
			3 1
			2 5
			2 6
			4 6
			2 3
			5 6
			1 5
			1 2
			3 5
			4 5
			6 3
			4 2
			1 4

	- OP1:  1
*/

vector<int> adj[1001], t_adj[1001];
bool visited[1001];
stack<int> st;
int n, m;

void DFS1(int u) {
	visited[u] = true;
	for (int v : adj[u]) {
		if (!visited[v]) DFS1(v);
	}
	st.push(u);
}

void DFS2(int u) {
	visited[u] = true;
	for (int v : t_adj[u]) {
		if (!visited[v]) DFS2(v);
	}
}

void Kosaraju() {
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) DFS1(i);
	}
	memset(visited, false, sizeof(visited));
	int cnt = 0;
	while(!st.empty()) {
		int u = st.top(); st.pop();
		if (!visited[u]) {
			cnt++;
			DFS2(u);
		}
	}
	if (cnt == 1) cout << 1;
	else cout << 0;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		t_adj[y].pb(x);
	}
	Kosaraju();
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}