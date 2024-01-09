#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho bảng A[] kích thước N x M (N hàng, M cột). Bạn được phép đi xuống dưới, đi sang phải và đi xuống ô chéo dưới về bên 
	  phải. Khi đi qua ô (i, j), điểm nhận được bằng A[i][j]. Hãy tìm đường đi từ ô (1, 1) tới ô (N, M) sao cho tổng điểm là 
	  lớn nhất.

	- Input Format: Dòng 1 gồm số nguyên dương N và M; N dòng tiếp theo, mỗi dòng gồm M số nguyên A[i][j];

	- Output Format: In ra kết quả của bài toán.

	- Constraints: 1<=N,M<=500; 1<=A[i][j]<=1000;

	- IP1:  5 5
			1 0 31 5 25 
			28 26 32 46 7 
			26 40 36 13 16 
			7 26 14 6 11 
			42 45 11 10 21 

	- OP1:  208
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    int a[n + 1][m + 1];
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		cin >> a[i][j];
		}
	}
	int dp[n + 1][m + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		if (i == 1 && j == 1) dp[i][j] = a[i][j];
    		else if (i == 1) dp[i][j] = dp[i][j - 1] + a[i][j];
    		else if (j == 1) dp[i][j] = dp[i - 1][j] + a[i][j];
    		else dp[i][j] = max({dp[i- 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + a[i][j];
		}
	}
	cout << dp[n][m];
	
	/*Cách 2:
	for (int i = 1; i <= n; i++) {
           for (int j = 1; j <= m; j++) {
               if (i == 1 && j == 1) a[i][j] = a[i][j];
               else if (i == 1) a[i][j] += a[i][j - 1];
               else if (j == 1) a[i][j] += a[i - 1][j];
               else a[i][j] += max({a[i - 1][j - 1], a[i - 1][j], a[i][j - 1]});
           }
       }
	*/
    return 0;
}