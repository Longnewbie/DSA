#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho đồ thị vô hướng G = được biểu diễn dưới ma trận trọng số A[][], trong đó A[i][j] khác không có nghĩa có cạnh nối giữa 
	  2 đỉnh i, j. Hãy chuyển đồ thị đã cho thành danh sách cạnh tương ứng.

	- Input Format: Dòng đầu tiên là n, tương ứng là số lượng đỉnh của đồ thị. N dòng tiếp theo là ma trận A[][].

	- Output Format: In ra danh sách cạnh và trọng số theo thứ tự đỉnh tăng dần.

	- Constraints: 1<=n<=1000; 1<=A[i][j]<=10^6;

	- IP1:  5
			0 0 9 4 1 
			0 0 1 0 6 
			9 1 0 3 1 
			4 0 3 0 8 
			1 6 1 8 0

	- OP1:  1 3 9
			1 4 4
			1 5 1
			2 3 1
			2 5 6
			3 4 3
			3 5 1
			4 5 8
*/

struct graph {
	int x, y, z;	
};

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<graph> v;
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    		int x; cin >> x;
    		if (x && i < j) v.pb({i, j, x});
		}
	}
	for (graph x : v) cout << x.x << " " << x.y << " " << x.z << "\n";
    return 0;
}