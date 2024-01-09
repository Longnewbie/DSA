#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
#define pii pair<int,int>
int mod = 1e9+7;

/*
	- Ở 28techland có n thành phố và ban đầu không có đường giữa chúng. Tuy nhiên, mỗi ngày một con đường mới sẽ được xây dựng 
	  và sẽ có tổng cộng m con đường. Một cụm thành phố là một nhóm các thành phố trong đó có một tuyến đường giữa hai thành 
	  phố bất kỳ bằng cách sử dụng các con đường. Sau mỗi ngày, nhiệm vụ của bạn là tìm ra số lượng cụm thành phố và kích thước
	  của cụm thành phố lớn nhất.

	- Input Format: Dòng đầu tiên có hai số nguyên n và m: số thành phố và đường. Các thành phố được đánh số 1,2,…, n. Sau đó,
	  có m dòng mô tả các con đường mới. Mỗi dòng có hai số nguyên a và b: một con đường mới được xây dựng giữa các thành phố 
	  a và b. Bạn có thể cho rằng mọi con đường sẽ được xây dựng giữa hai thành phố khác nhau.

	- Output Format: In m dòng: thông tin cần thiết sau mỗi ngày.

	- Constraints: 1≤n≤10^5; 1≤m≤2⋅10^5; 1≤a,b≤n; 

	- IP1:  5 3
			1 2
			1 3
			4 5

	- OP1:  4 2
			3 3
			2 3
*/

int parent[100001], sz[100001];
int res;

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
		res = max(res, sz[u]);
	} else {
		parent[u] = v;
		sz[v] += sz[u];
		res = max(res, sz[v]);
	}
	return true;
}
 
void solve() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		sz[i] = 1;
	}
	int d = n;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		d -= DSU(x, y);
		cout << d << " " << res << "\n";
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}