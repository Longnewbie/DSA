#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
#define pii pair<int,int>
int mod = 1e9+7;

/*
	- Ở 28techland có n thành phố và m đường giữa chúng. Thật không may, tình trạng của những con đường quá kém nên chúng không
	  thể được sử dụng. Nhiệm vụ của bạn là sửa chữa một số con đường để có một con đường tốt giữa hai thành phố bất kỳ. Đối với
	  mỗi con đường, bạn biết chi phí sửa chữa của nó và bạn nên tìm giải pháp sao cho tổng chi phí càng nhỏ càng tốt.

	- Input Format: Dòng đầu tiên có hai số nguyên n và m: số thành phố và đường. Các thành phố được đánh số 1,2,…, n. Sau đó,
	  có m dòng mô tả các con đường. Mỗi dòng có ba số nguyên a, b và c: có một con đường giữa các thành phố a và b, và chi phí
 	  sửa chữa của nó là c. Tất cả các con đường đều là đường hai chiều. Mọi con đường đều nằm giữa hai thành phố khác nhau và
	  có nhiều nhất một con đường giữa hai thành phố.

	- Output Format: In một số nguyên: tổng chi phí sửa chữa tối thiểu. Nếu không có giải pháp nào, hãy in "IMPOSSIBLE".

	- Constraints: 1≤n≤10^5; 1≤m≤2⋅10^5; 1≤a,b≤n; 1≤c≤10^9.

	- IP1:  5 6
			1 2 3
			2 3 5
			2 4 2
			3 4 8
			5 1 7
			5 4 4

	- OP1:  14
*/

struct edge {
	int x, y, w;
};

int n, m;
int parent[200006], sz[200006];
vector<edge> E;

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

bool DSU(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return false;
	if (sz[u] > sz[v]) {
		parent[v] = u;
		sz[u] += sz[v];
	} else {
		parent[u] = v;
		sz[v] += sz[u];
	}
	return true;
}

void Kruskal() {
	vector<edge> MST;
	sort(begin(E), end(E), [](edge a, edge b) -> bool {
		return a.w < b.w;
	});
	ll res = 0;
	for (edge e : E) {
		if (MST.size() == n - 1) break;
		if (DSU(e.x, e.y)) {
			MST.pb(e);
			res += e.w;
		}
	}
	if (MST.size() < n - 1) cout << "IMPOSSIBLE";
	else cout << res;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		sz[i] = 1;
	}
	for (int i = 1; i <= m; i++) {
		int x, y, w; cin >> x >> y >> w;
		edge e{x, y, w};
		E.pb(e);
	}
	Kruskal();
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}