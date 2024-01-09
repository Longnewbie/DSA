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
	- Cho một quân mã trên bàn cờ vua tại vị trí ST. Nhiệm vụ của bạn là hãy tìm số bước di chuyển ít nhất để đưa quân mã 
	  tới vị trí EN.

	- Input Format: Dòng đầu tiên là số lượng bộ test T (T ≤ 20). Mỗi test gồm 2 xâu dạng “xy” và “uv”, trong đó x, y là 
	  kí tự trong “abcdefgh” còn y, v là số thuộc 1, 2, 3, 4, 5, 6, 7, 8.

	- Output Format: Với mỗi test, in ra đáp án tìm được trên một dòng. Nếu không thể tìm được đường in ra -1.

	- Constraints: N/A

	- IP1:  5
			b2 c6
			h4 b3
			g1 b2
			e2 c3
			f6 b2

	- OP1:  3
			3
			4
			1
			4
*/

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int d[100][100];
int visited[100][100];
int s, t, u, v;

int BFS(int i, int j) {
	queue<pii> q;
	q.push({i, j});
	visited[i][j] = 1;
	while(!q.empty()) {
		pii top = q.front(); q.pop();
		if (top.first == u && top.second == v) return d[top.first][top.second];
		for (int k = 0; k < 8; k++) {
			int i1 = top.first + dx[k], j1 = top.second + dy[k];
			if (0 <= i1 && i1 < 8 && 0 <= j1 && j1 < 8 && !visited[i1][j1]) {
				visited[i1][j1] = 1;
				q.push({i1, j1});
				d[i1][j1] = d[top.first][top.second] + 1;
			}
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) {
    	string x, y; cin >> x >> y;
    	s = x[1] - '0' - 1;
    	t = x[0] - 'a';
    	u = y[1] - '0' - 1;
    	v = y[0] - 'a';
    	memset(visited, 0, sizeof(visited));
    	memset(d, 0, sizeof(d));
    	cout << BFS(s, t) << "\n";
	}
    return 0;
}