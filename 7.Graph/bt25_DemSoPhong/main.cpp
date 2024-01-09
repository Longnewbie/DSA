#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Bạn được đưa cho một bản đồ của một tòa nhà và nhiệm vụ của bạn là đếm số lượng phòng của tòa nhà đó. Kích thước của bản
	  đồ là n × m hình vuông và mỗi hình vuông là sàn hoặc tường. Bạn có thể đi bộ sang trái, phải, lên và xuống qua các ô sàn.

	- Input Format: Dòng nhập đầu tiên có hai số nguyên n và m: chiều cao và chiều rộng của bản đồ. Khi đó có n dòng gồm m ký 
	  tự mô tả bản đồ. Mỗi ký tự là một trong hai ký tự '.' hoặc '#' tương ứng với sàn nhà và tường.

	- Output Format: In ra số nguyên duy nhất là số phòng của tòa nhà.

	- Constraints: 1≤n,m≤1000

	- IP1:  6 6
			..###.
			...#..
			#..#..
			.##.#.
			######
			.#.##.

	- OP1:  7
	
	- IP2:  6 6
			####.#
			.#..##
			.#..##
			####..
			#...##
			.##..#

	- OP2:  6
*/

char a[1001][1001];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int n, m;

void DFS(int i, int j) { 
	a[i][j] = '#';
	for (int k = 0; k < 4; k++) {
		int i1 = i + dx[k], j1 = j + dy[k];
		if (1 <= i1 && i1 <= n && 1 <= j1 && j1 <= m && a[i1][j1] == '.') {
			DFS(i1, j1);
		}
	}
}

void BFS(int i, int j) {
	queue<pair<int,int>> q;
	q.push({i, j});
	while(!q.empty()) {
		pair<int,int> x = q.front(); q.pop();
		for (int k = 0; k < 4; k++) {
			int i1 = x.first + dx[k], j1 = x.second + dy[k];
			if (1 <= i1 && i1 <= n && 1 <= j1 && j1 <= m && a[i1][j1] == '.') {
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
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == '.') {
				cnt++;
				DFS(i, j); //BFS(i, j);
			}
		}
	}
	cout << cnt;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}