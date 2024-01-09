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
	- Cho ma trận A[M][N]. Nhiệm vụ của bạn hãy tìm số bước đi ít nhất dịch chuyển từ vị trí A[1][1] đến vị trí A[M][N]. Biết 
	  mỗi bước đi ta chỉ được phép dịch chuyển đến vị trí A[i][j+A[i][j]] hoặc vị trí A[i+A[i][j]][j] bên trong ma trận.

	- Input Format: • Dòng đầu tiên đưa vào số lượng test T. 
					• Dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm hai 
	  				  phần: phần thứ nhất là hai số M, N; phần thứ hai là các phần tử của ma trận A[][]; các số được viết 
					  cách nhau một vài khoảng trống.

	- Output Format: Đưa ra kết quả mỗi test theo từng dòng. In ra -1 nếu không tìm được đáp án.

	- Constraints: T, M, N, A[i][j] thỏa mãn ràng buộc: 1≤T≤100; 1≤M, N, A[i][j]≤10^3.

	- IP1:  1
			3  3
			2  1  2
			1  1  1
			1  1  1

	- OP1:  2
*/

int a[1001][1001], d[1001][1001];
int n, m;
bool used[1001][1001];

void init() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		cin >> a[i][j];
		}
	}
}

int BFS(int i, int j) {
	queue<pii> q;
	q.push({i, j});
	d[i][j] = 0;
	while(!q.empty()) {
		pii top = q.front(); q.pop();
		int i = top.first, j = top.second;
		if (i == n && j == m) return d[i][j];
		if (i + a[i][j] <= n && !used[i + a[i][j]][j]) {
			q.push({i + a[i][j], j});
			d[i + a[i][j]][j] = d[i][j] + 1;
			used[i + a[i][j]][j] = true;
		}
		if (j + a[i][j] <= m && !used[i][j + a[i][j]]) {
			q.push({i, j + a[i][j]});
			d[i][j + a[i][j]] = d[i][j] + 1;
			used[i][j + a[i][j]] = true;
		}
	}
	return -1;
}		

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--) {
    	memset(d, 0, sizeof(d));
    	memset(used, false, sizeof(used));
    	init();
    	cout << BFS(1, 1) << "\n";
	}
    return 0;
}