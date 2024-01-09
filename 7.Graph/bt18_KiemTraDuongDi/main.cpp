#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Có Q truy vấn, mỗi truy vấn yêu cầu trả lời câu
	  hỏi giữa 2 đỉnh s và t có tồn tại đường đi tới nhau hay không ?

	- Input Format: Dòng đầu tiên là 2 số n, m, tương ứng với số lượng đỉnh, cạnh của đồ thị. Các đỉnh của đồ thị được đánh số
	  từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị. Dòng tiếp theo là Q, Q 
	  dòng tiếp theo mỗi dòng chứa 2 đỉnh s, t cần truy vấn.

	- Output Format: Đối với mỗi truy vấn in ra 1 nếu có đường đi giữa s và t, ngược lại in ra -1.

	- Constraints: 1<=s,t<=n<=1000; 1<=m<=n*(n-1)/2; 1<=Q<=10000;

	- IP1:  5 3
			5 4
			4 1
			4 3
			3
			4 5
			4 2
			3 4

	- OP1:  1
			-1
			1
*/

int tplt[1001], dem;
vector<int> adj[1001];
bool visited[1001];

void DFS(int u) { //BFS tuong tu
	tplt[u] = dem;
	visited[u] = true;
	for (int v : adj[u]) {
		if (!visited[v]) DFS(v);
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
    	int x, y; cin >> x >> y;
    	adj[x].pb(y); adj[y].pb(x);
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dem++;
			DFS(i);
		} 
	}
	int q; cin >> q;
	while(q--) {
		int s, t; cin >> s >> t;
		if (tplt[s] == tplt[t]) cout << "1\n";
		else cout << "-1\n";
	}
    return 0;
}