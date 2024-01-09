#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Bạn biết rằng một mảng có n số nguyên chỉ gồm các số từ 1 đến m và độ lệch giữa 2 phần tử liền kề trong mảng không được
	  vượt quá 1 đơn vị. Bài toán đặt ra đó là cho bạn một mảng trong đó một số giá trị trong mảng chưa được xác định giá trị,
	  nhiệm vụ của bạn là đếm số mảng phù hợp với mô tả, đó là các số liền kề trong mảng không lệch nhau quá 1 đơn vị và các
	  giá trị trong mảng chỉ được nằm trong đoạn từ 1 tới m.

	- Input Format: +) Dòng nhập đầu tiên có hai số nguyên n và m: kích thước mảng và giới hạn trên cho mỗi giá trị.
					+) Dòng tiếp theo có n số nguyên x1, x2,…, xn: nội dung của mảng. Giá trị 0 biểu thị một giá trị 
					   không xác định.

	- Output Format: In ra số lượng mảng phù hợp sau khi chia dư cho 1e9 + 7.

	- Constraints: 1≤n≤10^5;
				   1≤m≤100; 0≤xi≤m;

	- IP1: 3 5
		   2 0 2

	- OP1: 3
	
	- Explanation 1: Các mảng có thể thỏa mãn : [2, 1, 2], [2, 2, 2], [2, 3, 2]
*/

ll dp[100001][101];

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    	if (a[1]) dp[1][a[1]] = 1;
    	else {
    		for (int j = 1; j <= m; j++) dp[1][j] = 1;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (a[i]) {
			for (int j = 1; j <= m; j++) {
				dp[i][a[i]] = dp[i - 1][a[i] - 1] + dp[i - 1][a[i]] + dp[i - 1][a[i] + 1];
				dp[i][j] %= mod; 
			} 
		} else {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1];
				dp[i][j] %= mod;
			}
		}
	}
	ll res = 0;
	for (int i = 1; i <= m; i++) {
		res += dp[n][i];
		res %= mod;
	}
	cout << res;
    return 0;
}