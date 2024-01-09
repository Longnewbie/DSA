#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
#define pii pair<int,int> 
int mod = 1e9+7;

/*
	- Bạn được cung cấp một lưới 2D. Dấu '#' đại diện cho chướng ngại vật và dấu '.' đại diện cho không gian trống. Bạn cần 
	  tìm các khu vực của các thành phần bị ngắt kết nối. Các ô (i + 1, j), (i, j + 1), (i-1, j), (i, j-1) là các ô liền kề 
	  với ô (i, j).

	- Input Format: Dòng đầu tiên là n và m, tương ứng với số dòng và số cột của lưới 2D. N dòng tiếp theo, mỗi dòng là m
	  kí tự '#'' hoặc '.'.

	- Output Format: In ra diện tích các vùng không gian trống liền kề trên 1 dòng.

	- Constraints: 1<=N,M<=1000;

	- IP1:  10 10
			###.#.#..#
			.######...
			###..##.#.
			.##...###.
			##....#..#
			.#..###...
			..####.##.
			...##.....
			..#...####
			.#..##.##.

	- OP1:  1 1 8 1 11 1 17 9 1 1 
*/

int n, m, cnt;
char a[1001][1001];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void DFS(int i, int j) {
	cnt++;
	a[i][j] = '#';
	for (int k = 0; k < 4; k++) {
		int i1 = i + dx[k], j1 = j + dy[k];
		 if (1 <= i1 && i1 <= n && 1 <= j1 && j1 <= m && a[i1][j1] != '#') {
		 	DFS(i1, j1);	
		 }
	}
}

void BFS(int i, int j) {
	a[i][j] = '#';
	queue<pii> q;
	q.push({i, j});
	while(!q.empty()) {
		cnt++;
		pii x = q.front(); q.pop();
		int i = x.first, j = x.second;
		for (int k = 0; k < 4; k++) {
			int i1 = i + dx[k], j1 = j + dy[k];
			if (1 <= i1 && i1 <= n && 1 <= j1 && j1 <= m && a[i1][j1] != '#') {
		 		q.push({i1, j1});
		 		a[i1][j1] = '#';
			}
		}
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	vector<int> res;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cnt = 0;
			if (a[i][j] == '.') {
				DFS(i, j); //BFS(i, j);
				cout << cnt << " ";
			}
		}
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}