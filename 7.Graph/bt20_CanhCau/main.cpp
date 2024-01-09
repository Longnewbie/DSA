#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Hãy đếm số lượng cạnh cầu của đồ thị.

	- Input Format: Dòng đầu tiên là 2 số n, m, tương ứng với số lượng đỉnh, cạnh của đồ thị. Các đỉnh của đồ thị được đánh số 
	  từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị. Giữa 2 đỉnh bất kỳ chỉ 
	  tồn tại nhiều nhất một cạnh nối.

	- Output Format: In ra số lượng cạnh cầu của đồ thị.

	- Constraints: 1<=n<=1000; 1<=m<=n*(n-1)/2;

	- IP1: 	10 6
			10 1
			5 2
			10 5
			10 6
			5 3
			10 4

	- OP1:  6
	
	- IP2: 	10 8
			10 9
			10 8
			10 3
			10 4
			5 3
			10 1
			5 1
			5 4

	- OP2:  2
*/

int parent[1001];
vector<int> adj[1001];
vector<pair<int,int>> edge;
bool visited[1001];

int n, m;

void DFS(int u, int s, int t) {
	visited[u] = true;
	for (int v : adj[u]) {
		if ((u == s && v == t) || (u == t && v == s)) continue;
		if (!visited[v]) {
			DFS(v, s, t);
		}
	}
}

int tplt(int s, int t) {
	int d = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			d++;
			DFS(i, s, t);
		}
	}
	return d;
}

void solve() {
	int bd = tplt(0, 0), cnt = 0;
	for (pair<int,int> x : edge) {
		int s = x.first, t = x.second;
		memset(visited, false, sizeof(visited));
		if (bd < tplt(s, t)) cnt++;
	}
	cout << cnt;
}

void init() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		adj[x].pb(y); adj[y].pb(x);
		edge.pb({x, y});
	}
	solve();
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    return 0;
}