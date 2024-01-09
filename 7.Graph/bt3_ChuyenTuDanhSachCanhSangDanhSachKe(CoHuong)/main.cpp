#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho đồ thị có hướng G = được biểu diễn dưới dạng danh sách cạnh. Hãy chuyển đổi đồ thị dưới dạng danh sách cạnh này sang
	  danh sách kề tương ứng.

	- Input Format: Dòng đầu tiên là 2 số n và m, tương ứng với số lượng đỉnh và cạnh của đồ thị. Các đỉnh của đồ thị được đánh
	  số từ 1 tới n. M dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

	- Output Format: In ra n dòng, trong đó dòng thứ i in ra danh sách kề của đỉnh i. Các đỉnh trong danh sách kề được liệt kê
	  từ nhỏ tới lớn.

	- Constraints: 1<=n<=1000; 1<=m<=n*(n-1)/2;

	- IP1:  5 10
			4 2
			4 1
			2 5
			3 4
			1 5
			2 3
			5 1
			2 1
			1 4
			4 5

	- OP1:  1 : 4 5 
		 	2 : 1 3 5 
			3 : 4 
			4 : 1 2 5 
			5 : 1 
*/

vector<int> adj[1001];

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
    	int x, y; cin >> x >> y;
    	adj[x].pb(y);
	}
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
		cout << i << " : ";
		for (int x : adj[i]) cout << x << " ";
		cout << "\n";
	}
    return 0;
}