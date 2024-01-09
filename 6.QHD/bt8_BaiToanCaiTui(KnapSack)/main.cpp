#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Một tên trộm có 1 cái túi có thể mang các đố vật với trọng lượng tối đa là V. Hiện tại tên trộm muốn lựa chọn các đồ vật
	  trong N đồ vật để ăn trộm, mỗi đồ vật có trọng lượng là w[i] và giá trị là v[i]. Hãy xác định tổng giá trị lớn nhất của
	  các đồ vật mà tên trộm này lựa chọn sao cho trọng lượng của chúng không vượt quá V.

	- Input Format: Dòng đầu ghi 2 số N và V. Dòng tiếp theo ghi N số của mảng w. Sau đó là một dòng ghi N số của mảng v.

	- Output Format: In ra giá trị lớn nhất có thể đạt được.

	- Constraints: V<=1000; N≤1000; 1<=w[i], c[i]<=500;

	- IP1:  6 22
			39 44 4 59 91 70 
			47 26 92 33 6 69 

	- OP1: 92
	
	- IP2:  7 22
			10 3 22 50 83 16 41 
			99 97 54 19 50 70 48 

	- OP2: 196
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, kg; cin >> n >> kg;
    int w[n + 1], v[n + 1];
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) cin >> v[i];
    int dp[n + 1][kg + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= kg; j++) {
    		dp[i][j] = dp[i - 1][j];
    		if (j >= w[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
 		}
	}
	cout << dp[n][kg];
    return 0;
}