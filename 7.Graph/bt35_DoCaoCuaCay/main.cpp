#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
#define pii pair<int,int>
int mod = 1e9+7;

/*
	- Cho cây với đỉnh gốc là đỉnh 1, các đỉnh của cây được đánh số từ 1 tới n. Độ cao của một nốt trong cây được tính bằng số
	  cạnh trên đường đi ngắn nhất giữa nốt này tới đỉnh gốc. Như vậy, gốc của cây là đỉnh 1 sẽ có độ cao là 0. Nhiệm vụ của bạn
	  là hãy xác định chiều cao của mọi nốt trong cây. Dưới đây là một ví dụ về cây.

	- Input Format: Dòng đầu tiên là số n - số nốt của cây. N - 1 dòng tiếp theo mỗi dòng mô tả một cạnh của cây.

	- Output Format: In ra độ cao của các nốt, từ nốt 1 tới nốt n.

	- Constraints: 1<=n<=1000;

	- IP1:  7
			1 2
			2 3
			3 4
			1 5
			5 6
			1 7

	- OP1: 0 1 2 3 1 2 1
*/

int d[1001];
vector<int> adj[1001];
bool visited[1001];

void DFS(int u) {
	visited[u] = true;
	for (int v : adj[u]) {
		if (!visited[v]) {
			d[v] = d[u] + 1;
			DFS(v);
		}
	}
}

void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int x, y; cin >> x >> y;
		adj[x].pb(y); adj[y].pb(x);
	}
	d[1] = 0;
	DFS(1);
	for (int i = 1; i <= n; i++) cout << d[i] << " ";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}