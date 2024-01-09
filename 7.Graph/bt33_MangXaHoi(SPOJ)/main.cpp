#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
#define pii pair<int,int>
int mod = 1e9+7;

/*
	- Tý đang xây dựng một mạng xã hội và mời các bạn của mình dùng thử. Bạn của bạn cũng là bạn. Vì vậy, Tý muốn mạng xã hội
	  của mình là hoàn hảo, tức với mọi bộ ba X, Y, Z, nếu X kết bạn với Y, Y kết bạn với Z thì X và Z cũng phải là bạn bè của
	  nhau trên mạng xã hội. Các bạn hãy xác định xem mạng xã hội hiện tại của Tý có là hoàn hảo hay không? Nếu có hãy in 
	  ra “YES”, “NO” trong trường hợp ngược lại.

	- Input Format: Mỗi test bắt đầu bởi 2 số nguyên N và M. M dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v (u #v) cho biết
	  u và v là kết bạn với nhau trên mạng xã hội của Tý.

	- Output Format: In ra kết quả của bài toán.

	- Constraints: 1<= N, M ≤ 100 000)

	- IP1:  4 3
			1 3
			3 4
			1 4

	- OP1:  YES
	
	- IP2:  4 4
			3 1
			2 3
			3 4
			1 2

	- OP2:  NO
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
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cnt = 0;
			DFS(i);
			res += 1ll * cnt * (cnt - 1) / 2;
		}
	}
	if (res == m) cout << "YES";
	else cout << "NO";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}