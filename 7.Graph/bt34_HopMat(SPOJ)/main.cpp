#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
#define pii pair<int,int>
int mod = 1e9+7;

/*
	- Có K người (1 ≤ K ≤ 100) đứng tại vị trí nào đó trong N địa điểm cho trước (1 ≤ N ≤ 1,000) được đánh số từ 1..N. Các điểm
	  được nối với nhau bởi M đoạn đường một chiều (1 ≤ M ≤ 10,000) (không có đoạn đường nào nối một điểm với chính nó). Mọi 
	  người muốn cùng tụ họp tại một địa điểm nào đó. Tuy nhiên, với các đường đi cho trước, chỉ có một số địa điểm nào đó có
	  thể được chọn là điểm họp mặt. Cho trước K, N, M và vị trí ban đầu của K người cùng với M đường đi một chiều, hãy xác 
	  định xem có bao nhiêu điểm có thể được chọn làm điểm họp mặt.

	- Input Format: Dòng 1: Ghi 3 số: K, N, và M Dòng 2 đến K+1: dòng i+1 chứa một số nguyên trong khoảng (1..N) cho biết địa 
	  điểm mà người thứ i đang đứng. Dòng K+2 đến M+K+1: Mỗi dòng ghi một cặp số A và B mô tả một đoạn đường đi một chiều từ 
	  A đến B (cả hai trong khoảng 1..N và A != B).

	- Output Format: In ra số địa điểm có thể được chọn là điểm họp mặt.

	- Constraints: (1 ≤ K ≤ 100); (1 ≤ N ≤ 1,000); (1 ≤ M ≤ 10,000);

	- IP1:  4 10 15
		 	1
			4
			5
			7
			10 3
			5 6
			4 9
			5 3
			8 6
			4 6
			8 9
			3 9
			1 9
			6 9
			7 9
			9 6
			7 3
			2 9
			5 9

	- OP1:  2
	
	- IP2:  2 4 4
			2
			3
			1 2
			1 4
			2 3
			3 4

	- OP2:  2
	
	- Explanation 1: 2 điểm có thể họp mặt : 3, 4.
*/

int k, n, m, cnt;
int d[1001];
vector<int> adj[1001];
bool visited[1001];

void DFS(int u) {
	visited[u] = true;
	d[u]++;
	if (d[u] == k) cnt++;
	for (int v : adj[u]) {
		if (!visited[v]) DFS(v);
	}
}

void solve() {
	cin >> k >> n >> m;
	int a[k];
	for (int &x : a) cin >> x;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		adj[x].pb(y);
	}
	for (int x : a) {
		memset(visited, false, sizeof(visited));
		if (!visited[x]) {
			DFS(x);
		}
	}
	cout << cnt;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}