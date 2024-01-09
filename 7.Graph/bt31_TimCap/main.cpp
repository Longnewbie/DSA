#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Bạn được cung cấp một cây gốc với các nút và nút 1 là gốc. Có một đường đi duy nhất giữa hai nút bất kỳ. Ở đây, d(i, j)
	  được định nghĩa là số cạnh trong một đường đi ngắn nhất giữa 2 nút i và j. Nhiệm vụ của bạn phải tìm số lượng cặp i, j 
	  sao cho d(i, j) = d(1, i) - d(1, j).

	- Input Format: Dòng đầu tiên là N là số lượng nút của cây. N - 1 dòng tiếp theo là các cạnh của cây.

	- Output Format: In ra số lượng cặp (i, j) thỏa mãn yêu cầu của đầu bài.

	- Constraints: 1<=N<=1000;

	- IP1:  10
			9 10
			5 9
			7 4
			4 5
			2 3
			6 7
			7 8
			3 6
			1 2

	- OP1:  51
	
	- IP1:  4
			1 2
			2 3
			3 4

	- OP1:  10
	
	- Explanation 1: Các cặp thỏa mãn : (1, 1), (1, 2), (1, 3), (1, 4), (2, 2), (2, 3), (2, 4), (3, 3), (3, 4), (4, 4).
*/

int res;
vector<int> adj[1001];
bool visited[1001];

int DFS(int u) {
	visited[u] = true;
	int ans = 1;
	for (int v : adj[u]) {
		if (!visited[v]) {
			ans += DFS(v);
		}
	}
	res += ans;
	return ans;
}

void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int x, y; cin >> x >> y;
		adj[x].pb(y); adj[y].pb(x);
	}
	memset(visited, false, sizeof(visited));
	DFS(1);
	cout << res;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}