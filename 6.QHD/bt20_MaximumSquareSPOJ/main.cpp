#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Bạn được cung cấp một ma trận nhị phân có N dòng và M cột chỉ bao gồm các số 0 và 1, hãy tìm hình vuông lớn nhất trong
	  ma trận mà chỉ chứa toàn số 1.

	- Input Format: Dòng đầu tiên gồm 2 số N và M; N dòng tiếp theo mỗi dòng M số nguyên;

	- Output Format: In ra kết quả đáp án của bài toán.

	- Constraints: 1<=N,M<=500; 0<=A[i][j]<=1;

	- IP1:  4 4
			1 1 0 0
			1 1 1 1
			1 1 0 1
			1 0 1 0

	- OP1:  2
*/

int a[502][502], dp[502][502];

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		cin >> a[i][j];
    		dp[i][j] = a[i][j];
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j]) {
				dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
			} else dp[i][j] = 0;
			res = max(res, dp[i][j]);
		}
	}
	cout << res;
    return 0;
}