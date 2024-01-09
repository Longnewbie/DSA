#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
#define pii pair<int,int>
int mod = 1e9+7;

/*
	- Cho một bảng S[][] kích thước N x M, bao gồm các ô trống, các vật cản. Ban đầu bạn ở vị trí S. Nhiệm vụ của bạn là hãy 
	  di chuyển tới vị trí T, sao cho số lần đổi hướng không quá hai lần. Các bạn có thể di chuyển từ 1 ô sang 4 ô chung cạnh 
	  với ô hiện tại và không có vật cản.

	- Input Format: Dòng 1 bắt đầu bởi hai số nguyên N và M. N dòng tiếp theo, mỗi dòng gồm M kí tự mô tả bảng S. Trong 
	  đó: ‘.’ là một ô trống, ‘*’ là vật cản, ‘S’ là vị trí xuất phát và ‘T’ là vị trí đích. (Chỉ có một vị trí S và T duy nhất).

	- Output Format: In ra “YES” nếu tìm được đường đi, ra in “NO” trong trường hợp ngược lại.

	- Constraints: (1 ≤ N, M ≤ 500);

	- IP1:  9 6
			**.*..
			.**..T
			.*..*.
			.....*
			...***
			...*S.
			*.....
			****..
			.....*

	- OP1:  NO
	
	- IP2:  6 10
			S...*...**
			...*.*....
			......*.T.
			.........*
			...*.***..
			....*.*...

	- OP2:  YES
*/

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int n, m, s1, s2, t1, t2, ok;
char a[501][501];

char xuli(int k) {
	if (k == 0) return 'U';
	if (k == 1) return 'L';
	if (k == 2) return 'R';
	return 'D';
}

void Try(int i, int j, char prev, int cnt) {
	if (cnt >= 4) return;
	if (ok) return;
	if (i == t1 && j == t2) {
		ok = 1;
		return;
	}
	for (int k = 0; k < 4; k++) {
		int i1 = i + dx[k], j1 = j + dy[k];
		if (1 <= i1 && i1 <= n && 1 <= j1 && j1 <= m && a[i][j] != '*') {
			if (xuli(k) == prev) Try(i1, j1, xuli(k), cnt);
			else Try(i1, j1, xuli(k), cnt + 1);
		}
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'S') {
				s1 = i; s2 = j;
			}
			if (a[i][j] == 'T') {
				t1 = i; t2 = j;
			}
		}
	}
	Try(s1, s2, '0', 0);
	if (ok) cout << "YES";
	else cout << "NO";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}