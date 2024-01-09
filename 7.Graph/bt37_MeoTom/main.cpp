#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
#define pii pair<int,int>
int mod = 1e9+7;

/*
	- Chú mèo Tom đang ở gốc 1 cây với nhiều lá và cành. Cái cây này có rất nhiều lá và các đỉnh trung gian. Ở các nốt lá có 
	  treo các con cá và mèo Tom mong muốn ăn được nhiều cá nhất có thể vì thế nó dự định sẽ trèo từ gốc cây tương ứng với đỉnh
	  1 và đi lần lượt tới các nốt lá để ăn cá, nhưng trên đường đi từ nốt gốc lên nốt lá, mèo Tom phải đi qua các nốt trung 
	  gian. Các nốt trung gian này sẽ có những con gián và mèo Tom chỉ có thể đi đến các nốt lá để ăn cá nếu trên đường đi từ 
	  nốt gốc tới nốt lá có không quá m con gián liên tiếp. Bạn hãy giúp Tom đếm số cá tối đa mà nó có thể ăn được nhé.

	- Input Format: Dòng đầu tiên là n và m, tương ứng với số lượng nốt của cây và số con gián liên tiếp. Dòng thứ 2 gồm n số
	  có giá trị 1 hoặc 0, tương ứng với vị trí ở nốt thứ i có hoặc không có con gián. N - 1 dòng tiếp theo mỗi dòng là mô tả 1
	  cạnh của cây.

	- Output Format: In ra số con cá tối đa mèo Tom có thể ăn.

	- Constraints: 2<=n<=1000; 1<=m<=n;

	- IP1:  7 1
			1 0 1 1 0 0 0
			1 2
			1 3
			2 4
			2 5
			3 6
			3 7

	- OP1:  2
*/

vector<int> adj[1001];
bool visited[1001];

int n, m, cnt, a[1001], d[1001];

void DFS(int u) {
	int ok = 0;
	for (int v : adj[u]) {
		ok = 1;
		if (a[v] == 1) d[v] = d[u] + 1;
		else d[v] = 0;
		if (d[v] <= m) {
			DFS(v);
		}
	}
	if (!ok) cnt++;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n - 1; i++) {
		int x, y; cin >> x >> y;
		adj[x].pb(y);
	}
	d[1] = a[1];
	DFS(1);
	cout << cnt;	
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}