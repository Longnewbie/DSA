#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
#define pii pair<int,int>
#define pip pair<int,pair<int,int>>
int mod = 1e9+7;

/*
	- Cho đơn đồ thị vô hướng liên thông G = (V, E) gồm N đỉnh và M cạnh, các đỉnh được đánh số từ 1 tới N và các cạnh được đánh
	  số từ 1 tới M. Có Q truy vấn, mỗi truy vấn yêu cầu bạn tìm đường đi ngắn nhất giữa đỉnh X tới Y.

	- Input Format: +) Dòng đầu tiên hai số nguyên N và M;
					+) M dòng tiếp theo, mỗi dòng gồm 3 số nguyên u, v, c cho biết có cạnh nối giữa đỉnh u và v có độ dài bằng c.
					+) Tiếp theo là số lượng truy vấn Q.
					+) Q dòng tiếp theo, mỗi dòng gồm 2 số nguyên X, Y.

	- Output Format: Với mỗi truy vấn, in ra đáp án là độ dài đường đi ngắn nhất tìm được.

	- Constraints: (1 ≤ N ≤ 100, 1 ≤ M ≤ N*(N-1)/2); (1 ≤ c ≤ 1000); Q (1 ≤ Q ≤ 100 000);

	- IP1:  5 6
			1 2 6
			1 3 7
			2 4 8
			3 4 9
			3 5 1
			4 5 2
			3
			1 5
			2 5
			4 3

	- OP1:  8
			10
			3
*/

const int OO = 1e9+7;
int a[101][101];
int n, m;

void Floyd() {
	for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
}

void TestCase(int s, int t) {
	cout << a[s][t] << "\n";
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) a[i][j] = 0;
            else a[i][j] = OO;
        }
    }
	for (int i = 1; i <= m; i++) {
        int x, y, z; cin >> x >> y >> z;
        a[x][y] = a[y][x] = z;
    }
	Floyd();
	int q; cin >> q;
	while(q--) {
		int s, t; cin >> s >> t;
		TestCase(s, t);
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

