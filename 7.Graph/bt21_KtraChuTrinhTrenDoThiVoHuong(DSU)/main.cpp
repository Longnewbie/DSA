#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
#define pi pair<int,int>
#define pip pair<int,pair<int,int>>
int mod = 1e9+7;

/*
	- Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Hãy xác định xem đồ thị có tồn tại chu trình hay
	  không? Bài này các bạn cài đặt bằng 3 phương pháp : DFS, BFS và DSU.

	- Input Format: Dòng đầu tiên là 2 số n, m, tương ứng với số lượng đỉnh, cạnh của đồ thị. Các đỉnh của đồ thị được đánh số 
	  từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

	- Output Format: In ra 1 nếu đồ thị tồn tại chu trình, ngược lại in ra 0.

	- Constraints: 1<=n<=1000; 1<=m<=n*(n-1)/2; 

	- IP1:  10 11
			10 5
			10 4
			10 1
			10 3
			5 2
			5 4
			10 8
			5 3
			5 1
			10 6
			10 9

	- OP1:  1
	
	- IP2:  6 4
			1 2
			2 4
			2 5
			3 6

	- OP2:  0
*/

int parent[1001], sz[1001];
vector<int> adj[1001];
bool visited[1001];

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

bool DSU(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return false;
	if (sz[u] > sz[v]) {
		sz[u] += sz[v];
		parent[v] = u;
	} else {
		sz[v] += sz[u];
		parent[u] = v;
	}
	return true;
}

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		sz[i] = 1;
		parent[i] = i;
	}
	int ok = 0;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		if (!DSU(x, y)) {
			ok = 1;
		}
	}
	if (ok) cout << "1";
	else cout << "0";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);    
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}