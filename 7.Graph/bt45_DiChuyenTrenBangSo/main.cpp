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
	- Cho một bảng số kích thước N x M. Chi phí khi đi qua ô (i,j) bằng A[i][j]. Nhiệm vụ của bạn là hãy tìm một đường đi 
	  từ ô (1, 1) tới ô (N, M) sao cho chi phí là nhỏ nhất. Tại mỗi ô, bạn được phép đi sang trái, sang phải, đi lên trên 
	  và xuống dưới.

	- Input Format: +) Dòng 1 bắt đầu bởi hai số nguyên N và M.
					+) N dòng tiếp theo, mỗi dòng gồm M số nguyên A[i][j].

	- Output Format: In ra một số nguyên là chi phí nhỏ nhất cho đường đi tìm được.

	- Constraints: +) 1 ≤ N, M ≤ 500.
				   +) (0 ≤ A[i][j] ≤ 9).

	- IP1:  6 7
			0 3 6 0 5 9 1 
			6 5 4 4 0 7 6 
			4 0 2 1 5 6 1 
			2 7 7 3 3 1 6 
			4 4 9 6 9 7 2 
			3 6 4 4 1 9 2 

	- OP1:  28
	
	- IP2:  4 5
			0 3 1 2 9
			7 3 4 9 9
			1 7 5 5 3
			2 3 4 2 5

	- OP2:  24
*/

const int OO = 1e9;
int a[501][501], d[501][501];

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		cin >> a[i][j];
    		d[i][j] = OO;
		}
	}
	priority_queue<pip, vector<pip>, greater<pip>> q;
	d[1][1] = a[1][1];
	q.push({d[1][1], {1, 1}});
	while(!q.empty()) {
		pip it = q.top(); q.pop();
		int len = it.first, i = it.second.first, j = it.second.second;
		if (len > d[i][j]) continue;
		for (int k = 0; k < 4; k++) {
			int i1 = i + dx[k], j1 = j + dy[k];
			if (1 <= i1 && i1 <= n && 1 <= j1 && j1 <= m && d[i1][j1] > d[i][j] + a[i1][j1]) {
				d[i1][j1] = d[i][j] + a[i1][j1];
				q.push({d[i1][j1], {i1, j1}});
			}
		}
	}
	cout << d[n][m];
    return 0;
}

