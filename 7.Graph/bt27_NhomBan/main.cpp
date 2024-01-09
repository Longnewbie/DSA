#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Trong một lớp học luôn tồn tại những nhóm học sinh, các học sinh trong nhóm này sẽ thân thiết với nhau hơn. Giả sử trong 
	  1 nhóm, nếu bạn a chơi thân vs bạn b và bạn b chơi thân với bạn c, thì bạn a và bạn c sẽ chơi thân với nhau. Hiện nay Tèo
	  là lớp trưởng lớp 10A1, vì không thích việc chia bè kéo cánh trong lớp nên Tèo quyết định tìm ra nhóm có số bạn chơi thân
	  với nhau nhất trong nhóm để đưa các thành viên của các nhóm khác vào trong nhóm có số lượng thành viên cao nhất này.
	  Bạn hãy giúp Tèo tìm ra số lượng thành viên lớn nhất của 1 nhóm chơi thân bất kỳ trong lớp nhé !

	- Input Format: Dòng đầu tiên là n và m, tương ứng với số lượng sinh viên trong lớp và số lượng tình bạn giữa các bạn trong
	  lớp. Các sinh viên được đánh số từ 1 tới n. M dòng tiếp theo mỗi dòng gồm 2 số a, b thể hiện tình bạn thân thiết giữa bạn
	  a và bạn b, a và b khác nhau.

	- Output Format: In ra nhóm có số lượng bạn lớn nhất.

	- Constraints: 1<=n<=1000; 1<=m<=n*(n-1)/2; 1<=a,b<=n;

	- IP1:  10 6
			8 2
			4 1
			8 6
			8 7
			8 1
			8 5

	- OP1:  7
	
	- IP2:  10 7
			4 1
			2 4
			6 4
			1 5
			6 8
			3 7
			7 9

	- OP2:  6
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

void BFS(int u) {
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()) {
		cnt++;
		int u = q.front(); q.pop();
		for (int v : adj[u]) {
			if (!visited[v]) {
				q.push(v);
				visited[v] = true;
			}
		}
	}
}

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		adj[x].pb(y); adj[y].pb(x);
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		cnt = 0;
		memset(visited, false, sizeof(visited));
		if (!visited[i]) BFS(i); //DFS(i);
		res = max(res, cnt);
	}
	cout << res;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}