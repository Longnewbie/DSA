#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho mảng 2 chiều A gồm N hàng và N cột, hàng được đánh số từ 1 đến N từ trên xuống dưới, cột được đánh số từ 1 tới N từ 
	  trái sang phải, hãy tìm 1 đường đi từ một ô ở cột 1 tới 1 ổ ở cột N sao cho các phần tử trên đường đi đó là lớn nhất có 
	  thể. Biết rằng ở mỗi bước đi từ ô hiện tại (i, j) chỉ có thể đi sang phải (i, j + 1) hoặc đi xuống ô dưới bên phải
	  (i + 1, j + 1), ô bên trên bên phải(i - 1, j + 1). Hãy tìm 1 đường đi có tổng các số trên đường đi là lớn nhất.

	- Input Format: +) Dòng 1 là N.
					+) N dòng tiếp theo mỗi dòng gồm N số.

	- Output Format: In ra đáp án của bài toán.

	- Constraints: 1<=N<=100
				  -100<=A[i][j]<=100

	- IP1:  5
			2 -8 2 9 0 
			-5 6 6 -1 6 
			3 5 0 2 9 
			9 -8 9 7 0 
			-4 6 1 -2 0 

	- OP1:  40
	
	- Explanation 1: Đường đi có tổng lớn nhất : 9 + 6 + 9 + 7 + 9 = 40
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);    
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int a[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        dp[0][i] = -1e9;
        dp[n + 1][i] = -1e9;
    }
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            if (j == 1) {
                dp[i][j] = a[i][j];
            } else {
                dp[i][j] = max({dp[i - 1][j - 1], dp[i][j - 1], dp[i + 1][j - 1]}) + a[i][j];
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, dp[i][n]);
    }
    cout << res;
    return 0; 
}