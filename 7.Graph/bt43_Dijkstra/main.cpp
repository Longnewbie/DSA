#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
#define pii pair<int,int>
#define pip pair<int,pair<int,int>>
int mod = 1e9+7;

/*
	- Cho đồ thị vô hướng có trọng số không âm G= (V, E) được biểu diễn dưới dạng danh sách cạnh trọng số. Hãy viết chương 
	  trình tìm đường đi ngắn nhất từ đỉnh s đến tất cả các đỉnh còn lại trên đồ thị. Dữ liệu đảm bảo có đường đi từ đỉnh s 
	  tới mọi đỉnh khác trên đồ thị.

	- Input Format: Dòng đầu tiên là n m và s tương ứng với số lượng đỉnh, cạnh và đỉnh bắt đầu. M dòng tiếp theo là các dòng
	  mô tả cạnh của đồ thị.

	- Output Format: In ra đường đi ngắn nhất từ đỉnh u tới mọi đỉnh còn lại.

	- Constraints: 1<=n<=1000; 1<=m<=n*(n-1)/2; Trọng số các cạnh là số nguyên không âm không vượt quá 100;

	- IP1:  10 44 5
			7 5 60
			9 8 31
			9 1 83
			4 3 25
			6 2 1
			4 1 52
			6 3 76
			7 6 95
			9 7 84
			8 2 91
			10 7 8
			6 4 32
			10 2 76
			3 1 62
			10 6 88
			8 3 12
			5 3 15
			5 4 40
			9 2 20
			3 2 5
			5 1 36
			9 4 98
			8 6 65
			8 5 95
			10 3 55
			9 6 95
			10 1 5
			4 2 70
			7 1 80
			10 4 35
			7 2 99
			10 9 24
			6 5 94
			2 1 77
			8 1 12
			8 4 76
			9 3 27
			5 2 5
			9 5 12
			10 5 1
			8 7 59
			6 1 1
			10 8 92
			7 3 54

	- OP1:  6 5 10 35 0 6 9 18 12 1 
*/

int n, m, s;
vector<pii> adj[1001];
const int OO = 1e9+7;

void Dijkstra() {
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0, s});
	vector<int> d(n + 1, OO);
	d[s] = 0;
	while(!q.empty()) {
		pii x = q.top(); q.pop();
		int dis = x.first, u = x.second;
		if (dis > d[u]) continue;
		for (pii e : adj[u]) {
			int v = e.first, w = e.second;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				q.push({d[v], v});
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << d[i] << " ";
}

void solve() {
	cin >> n >> m >> s;
	for (int i = 1; i <= m; i++) {
		int x, y, z; cin >> x >> y >> z;
		adj[x].pb({y, z}); adj[y].pb({x, z});
	}
	Dijkstra();
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}