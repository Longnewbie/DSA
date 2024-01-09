#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
#define pii pair<int,int>
int mod = 1e9+7;

/*
	- Thành phố Vice được xây dựng trên một nhóm các hòn đảo, với những cây cầu nối giữa chúng. Như bất kỳ ai ở Vice City đều
	  biết, nỗi sợ hãi lớn nhất của các phó thành phố là một ngày nào đó các hòn đảo sẽ bị nhấn chìm. Vấn đề lớn của việc này
	  là một khi các hòn đảo bị nhấn chìm, một số hòn đảo khác có thể bị ngắt kết nối. Bạn đã được thị trưởng thành phố Vice
	  thuê để nói cho ông ta biết có bao nhiêu hòn đảo, khi bị nhấn chìm, sẽ ngắt kết nối các bộ phận của thành phố Vice. Bạn
	  nên biết rằng ban đầu tất cả các hòn đảo của thành phố đều được kết nối với nhau.

	- Input Format: Dòng đầu tiên là N và M, tương ứng với số lượng đảo và cầu; M dòng tiếp theo của mỗi test case mô tả cầu 
	  nối giữa 2 hòn đảo u, v;

	- Output Format: In ra số lượng hòn đảo khi bị ngập sẽ làm thành phố Vice bị ngắt kết nối.

	- Constraints: 1<=N<=1000; 1<=M<=N*(N-1)/2; 1<=u,v<=N;

	- IP1:  6 8
			1 3
			6 1
			6 3
			4 1
			6 4
			5 2
			3 2
			3 5

	- OP1:  1
	
	- IP2:  7 10
			1 5
			3 4
			1 4
			6 2
			3 1
			4 5
			7 4
			5 7
			2 4
			1 2

	- OP1:  1
*/

int cnt;
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
	int res = 0;
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		cnt = 0;
		visited[i] = true;
		if (i == 1) DFS(2);
		else DFS(1);
		if (cnt < n - 1) res++;
	}
	cout << res;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}