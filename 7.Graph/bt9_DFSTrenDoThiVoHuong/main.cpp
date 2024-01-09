#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho đồ thị vô hướng G = được biểu diễn dưới dạng danh sách cạnh. Hãy thực hiện in ra danh sách các đỉnh được duyệt theo
	  thuật toán DFS(s).

	- Input Format: Dòng đầu tiên là 2 số n và m và s, tương ứng với số lượng đỉnh, cạnh của đồ thị và đỉnh bắt đầu duyệt.
	  Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh
	  của đồ thị.

	- Output Format: In ra các đỉnh được duyệt theo thuật toán DFS(s). Chú ý trong quá trình mở rộng các đỉnh của thuật toán
	  DFS luôn lựa chọn duyệt các đỉnh có thứ tự nhỏ hơn trước.

	- Constraints: 1<=s<=n<=1000; 1<=m<=n*(n-1)/2;

	- IP1:  5 5 3
			5 2
			3 2
			5 4
			5 3
			5 1

	- OP1:  3 2 5 1 4 
*/

vector<int> adj[1001];
bool visited[1001];

void DFS(int u) {
	cout << u << " ";
	visited[u] = true;
	for (int v : adj[u]) {
		if (!visited[v]) {
			DFS(v);
		}
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, u; cin >> n >> m >> u;
    for (int i = 1; i <= m; i++) {
    	int x, y; cin >> x >> y;
    	adj[x].pb(y); adj[y].pb(x);
	}
	for (int i = 1; i <= n; i++) sort(begin(adj[i]), end(adj[i]));
	memset(visited, false, sizeof(visited));
	DFS(u);
    return 0;
}