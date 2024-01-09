#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Hãy đếm số lượng đỉnh trụ của đồ thị.

	- Input Format: Dòng đầu tiên là 2 số n, m, tương ứng với số lượng đỉnh, cạnh của đồ thị. Các đỉnh của đồ thị được đánh
	  số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

	- Output Format: In ra số lượng đỉnh trụ của đồ thị.

	- Constraints: 1=<=n<=1000; 1<=m<=n*(n-1)/2;.

	- IP1:  10 6
			5 4
			5 2
			10 2
			10 7
			5 3
			10 1

	- OP1:  3
	
	- Explanation 0: 3 đỉnh trụ của đồ thị là : 2, 5, 10
*/

vector<int> adj[1001];
bool visited[1001];
int n, m;

void DFS(int u) {
	visited[u] = true;
	for (int v : adj[u]) {
		if (!visited[v]) DFS(v);
	}
}

int tplt() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cnt++;
			DFS(i);
		}
	}
	return cnt;
}

void init() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		adj[x].pb(y); adj[y].pb(x);
	}
	int bd = tplt(), dem = 0;
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		visited[i] = true;
		if (bd < tplt()) dem++;
	}
	cout << dem;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    return 0;
}