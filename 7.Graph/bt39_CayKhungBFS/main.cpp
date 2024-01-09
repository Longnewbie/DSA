#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
#define pii pair<int,int>
int mod = 1e9+7;

/*
	- Cho đồ thị vô hướng G =(V, E) liên thông. Hãy in ra các cạnh của cây khung này theo thuật toán BFS bắt đầu từ đỉnh s. Thứ 
	  tự mở rộng cây khung của thuật toán BFS luôn mở rộng đỉnh có thứ tự nhỏ hơn trước.

	- Input Format: Dòng đầu tiên là n, m, và s tương ứng với số đỉnh, số cạnh và đỉnh gốc của cây khung. M dòng tiếp theo mỗi 
	  dòng là một cạnh của cây, dữ liệu đảm bảo cạnh chỉ nối giữa 2 đỉnh khác nhau.
	  
	- Output Format: In ra các cạnh của cây khung theo thứ tự duyệt bằng thuật toán BFS theo từng dòng.

	- Constraints: 1<=s<=n<=1000; 1<=m<=n*(n - 1)/2;

	- IP1:  9 18 4
			9 3
			5 4
			5 1
			5 2
			7 5
			4 3
			8 5
			4 2
			2 1
			9 4
			7 2
			8 6
			9 7
			4 1
			6 1
			9 1
			6 3
			7 1

	- OP1: 	4->1
			4->2
			4->3
			4->5
			4->9
			1->6
			1->7
			5->8
*/

vector<string> path;
vector<int> adj[1001];
bool visited[1001];

void BFS(int u) {
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : adj[u]) {
			if (!visited[v]) {
				q.push(v);
				string res = "";
				res += to_string(u) + "->" + to_string(v);
				path.pb(res);
				visited[v] = true;
			}
		}
	}
}

void solve() {
	int n, m, s; cin >> n >> m >> s;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		adj[x].pb(y); adj[y].pb(x);
	}
	for (int i = 1;  i <= n; i++) sort(begin(adj[i]), end(adj[i]));
	BFS(s);
	for (string x : path) cout << x << "\n";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}