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
	  là lớp trưởng lớp 10A1, vì không thích việc chia bè kéo cánh trong lớp nên Tèo quyết định tìm các bạn nhóm trưởng của các
	  nhóm để bàn việc hợp nhất các nhóm. Tèo biết rằng trong các nhóm nhỏ, nhóm trưởng là người có nhiều quan hệ thân thiết với
	  các thành viên khác trong nhóm nhất và là người có số thứ tự nhỏ nhất. Nếu một bạn nào đó không chơi với ai cả thì bạn đó
	  là nhóm trưởng của chính mình. Bạn hãy giúp tèo in ra thứ tự của các trưởng nhóm theo thứ tự từ nhỏ đến lớn nhé.

	- Input Format: Dòng đầu tiên là n và m, tương ứng với số lượng sinh viên trong lớp và số lượng tình bạn giữa các bạn trong
	  lớp. Các sinh viên được đánh số từ 1 tới n. M dòng tiếp theo mỗi dòng gồm 2 số a, b thể hiện tình bạn thân thiết giữa bạn
	  a và bạn b, a và b khác nhau.

	- Output Format: In ra thứ tự của các trưởng nhóm theo thứ tự từ nhỏ đến lớn nhé.

	- Constraints: 1<=n<=1000; 1<=m<=n*(n-1)/2; 1<=a,b<=n;

	- IP1:  10 6
			4 3
			4 1
			8 5
			8 6
			4 2
			8 2

	- OP1:  4 7 9 10 
*/

int bac[1001], tmp;
vector<int> adj[1001];
bool visited[1001];

void DFS(int u) {
	if (bac[u] > bac[tmp] || bac[u] == bac[tmp] && u < tmp) tmp = u;
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
		bac[x]++; bac[y]++;
	}
	vector<int> res;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            tmp = i;
            DFS(i);
            res.pb(tmp);
        }
    }
	sort(begin(res), end(res));
	for (int x : res) cout << x << " ";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}