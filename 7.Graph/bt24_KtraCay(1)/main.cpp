#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Một đồ thị N đỉnh là một cây, nếu như nó có đúng N-1 cạnh và giữa 2 đỉnh bất kì, chỉ tồn tại duy nhất 1 đường đi giữa 
	  chúng. Cho một đồ thị vô hướng N đỉnh và M cạnh, hãy kiểm tra đồ thị đã cho có phải là một cây hay không ?

	- Input Format: Dòng đầu tiên là số n, m tương ứng với số lượng đỉnh, cạnh của đồ thị. Các đỉnh của đồ thị được đánh số
	  từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

	- Output Format: In ra 1 nếu đồ thị đã cho là cây, ngược lại in ra 0.

	- Constraints: 1<=n<=1000; 1<=m<=n*(n-1)/2;

	- IP1:  6 5
			4 3
			2 1
			6 5
			5 4
			3 2

	- OP1:  1
	
	- IP2:  6 4
			6 3
			3 2
			4 2
			6 4

	- OP2:  0
*/

int parent[1001], cnt;
vector<int> adj[1001];
bool visited[1001];

void DFS(int u) {
	cnt++;
	visited[u] = true;
	for (int v : adj[u]) {
		if (!visited[v]) DFS(v);
	}
}

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		adj[x].pb(y); adj[y].pb(x);
	}
	if (n - 1 == m) {
		DFS(1);
		if (cnt == n) cout << 1;
		else cout << 0;
	} else cout << 0;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}