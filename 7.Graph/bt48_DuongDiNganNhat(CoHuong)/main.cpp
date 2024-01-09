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
	- Cho đồ thị có hướng có trọng số  G = (V, E, w) có n đỉnh, m cạnh, cạnh (u, v) có trọng số w(u, v) và hai đỉnh s, t.
	  Hãy tìm đường đi ngắn nhất từ s đến t.

	- Input Format: +) Dòng đầu chứa bốn số nguyên n, m, s, t là số đỉnh và số cạnh của G, đỉnh xuất phát và đỉnh đích;
					+) m dòng tiếp theo, mỗi dòng chứa ba số số u, v, c cho biết một cạnh nối hai đỉnh u và v trong G và
					   trọng số c = w(u, v) tương ứng.

	- Output Format: +) Dòng đâu ghi số nguyên là độ dài đường đi ngắn nhất;
					 +) Dòng thứ hai ghi ra một đường đi từ  tới  có độ dài ngắn nhất.

	- Constraints: 1 <= n <= 100; n - 1 <= m <= n(n - 1)/2; 0 <= c <= 10000.

	- IP1:  6 8 1 5
			1 2 7
			1 3 12
			2 3 2
			2 4 9
			3 5 10
			4 6 1
			5 4 4
			5 6 5

	- OP1:  19
			1 2 3 5 
			
	- IP2:  5 5 1 4
			1 2 3
			2 3 5
			3 4 8
			1 5 6
			4 5 4

	- OP2:  16
			1 2 3 4		
*/

const int maxn = 1e9;
const int OO = 1e9;
int pre[1001];
int n, m, s, t;
vector<pii> adj[1001];

void Dijkstra(int s, int t) {
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0, s});
	vector<int> d(n + 1, OO);
	d[s] = 0;
	pre[s] = s;
	while(!q.empty()) {
		pii x = q.top(); q.pop();
		int dis = x.first, u = x.second;
		if (dis > d[u]) continue;
		for (pii e : adj[u]) {
			int v = e.first, w = e.second;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				q.push({d[v], v});
				pre[v] = u;
			}
		}
	}
	vector<int> path;
	cout << d[t] << "\n";
	while(1) {
		path.pb(t);
		if (t == s) break;
		t = pre[t];
	}
	reverse(begin(path), end(path));
	for (int x : path) cout << x << " ";
}

void solve() {
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++) {
		int x, y, z; cin >> x >> y >> z;
		adj[x].pb({y, z});
	}
	Dijkstra(s, t);
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);    
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}