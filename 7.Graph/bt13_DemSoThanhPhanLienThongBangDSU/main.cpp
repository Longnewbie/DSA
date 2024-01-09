#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Hãy đếm số thành phần liên thông của đồ thị.

	- Input Format: Dòng đầu tiên là 2 số n và m, tương ứng với số lượng đỉnh, cạnh của đồ thị. Các đỉnh của đồ thị được đánh 
	  số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

	- Output Format: In ra số thành phần liên thông của đồ thị.

	- Constraints: 1<=n<=1000; 1<=m<=n*(n-1)/2;.

	- IP1:  5 4
			4 1
			2 1
			3 2
			4 3

	- OP1:  2
	
	- IP2:  5 2
			4 1
			2 1

	- OP1:  3
*/

int parent[1001], sz[1001];
vector<int> adj[1001];

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

bool Union(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return false;
	if (sz[u] > sz[v]) {
		parent[v] = u;
		sz[u] += sz[v];
	} else {
		parent[u] = v;
		sz[v] += sz[u];
	}
	return true;
}

void init() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		sz[i] = 1;
	}
	int d = n;							//int d = 0;
	for (int i = 1; i <= m; i++) {		//for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;		//	int x, y; cin >> x >> y;
		d -= Union(x, y);				//	Union(x, y);
	}									//}
	cout << d;							//for (int i = 1; i <= n; i++) {
}										//	if (parent[i] == i) d++;
										//}
										//cout << d;
int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    return 0;
}