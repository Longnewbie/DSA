#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Ở 28techland có n thành phố và m đường giữa chúng. Mục tiêu là xây dựng những con đường mới để có một tuyến đường giữa
	  hai thành phố bất kỳ. Nhiệm vụ của bạn là tìm ra số lượng đường tối thiểu cần thiết, đồng thời xác định những con đường
	  nào nên được xây dựng.

	- Input Format: Dòng đầu tiên có hai số nguyên n và m: số thành phố và đường. Các thành phố được đánh số từ 1 tới n. Sau đó,
	  có m dòng mô tả các con đường. Mỗi dòng có hai số nguyên a và b: có một con đường giữa các thành phố đó, các con đường này
	  là đường 2 chiều. Một con đường luôn nối hai thành phố khác nhau và có nhiều nhất một con đường giữa hai thành phố bất kỳ.

	- Output Format: Dòng đầu tiên in ra K là số con đường cần xây dựng. K dòng tiếp theo in ra các con đường được xây dựng, do
	  có nhiều cách xây dựng đường nên bạn sẽ lựa chọn ra các con đường có thứ tự từ điển nhỏ nhất để xây dựng nhưng với một 
	  điều kiện đó là, mỗi thành phố được lựa chọn là điểm xuất phát của con đường không quá 1 lần.

	- Constraints: 1<=n<=1000; 0<=m<=n*(n-1)/2; 1<=a,b<=n;

	- IP1:  6 3
			4 3
			4 1
			4 2

	- OP1:  2
			1 5
			5 6
			
	Explanation 0: Có thể có nhiều cách xây dựng đường đi ví dụ : xây dựng đường đi giữa thành phố 2 và 5, 1 và 6 sẽ kết nối
 	mọi thành phố. Tuy nhiên do yêu cầu của đầu bài, bạn sẽ phải xây dựng 2 con đường là 1->5, 5->6. Không thể xây dựng
    1->5, 1->6 vì như vậy thành phố 1 sẽ 2 lần là điểm khởi đầu của con đường.
*/

vector<int> adj[1001];
bool visited[1001];

void DFS(int u) {
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
	vector<int> res;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			DFS(i);
			res.pb(i);
		}
	}
	cout << res.size() - 1 << "\n";
	for (int i = 1; i < res.size(); i++) {
		cout << res[i - 1] << " " << res[i] << "\n";
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}