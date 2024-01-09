#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho ma trận A các số nguyên có N hàng và M cột. Tìm đường đi từ ở [1, 1] tới ô [N, M] sao cho tổng các số trên đường đi 
	  là lớn nhất có thể, biết rằng ở mỗi bước chỉ có thể đi từ ô hiện tại xuống ô phía dưới hoặc đi sang phải.

	- Input Format: Dòng đầu tiên N và M. N dòng tiếp theo mỗi dòng gồm M phần tử.

	- Output Format: In ra đường đi có tổng lớn nhất..

	- Constraints: 1≤N,M≤100; 1≤A[i][j]≤10^9

	- IP1:  3 3
			1 2 2
			3 10 2
			5 7 2

	- OP1:  23
	
	- Explanation 1: Đường đi được chọn (1, 1) -> (2, 1) -> (2, 2) -> (3, 2) -> (3, 3)
*/

ll a[101][101];

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		if (i == 1) a[i][j] = a[i][j - 1] + a[i][j];
    		else if (j == 1) a[i][j] = a[i - 1][j] + a[i][j];
    		else a[i][j] = max(a[i][j - 1], a[i - 1][j]) + a[i][j];
		}
	}
	cout << a[n][m];
    return 0;
}