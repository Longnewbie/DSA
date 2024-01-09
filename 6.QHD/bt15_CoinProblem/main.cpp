#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Ngân hàng XYZ hiện có N tờ tiền có mệnh giá khác nhau được lưu vào mảng C[], bạn hãy tìm cách đổi số tiền là S sao cho 
	  số tờ tiền cần dùng là ít nhất. Bạn được sử dụng một mệnh giá không giới hạn số lần.

	- Input Format: Dòng đầu tiên chứa 2 số N và S; Dòng thứ 2 chưa N số là mệnh giá các tờ tiền;

	- Output Format: In ra số tờ tiền nhỏ nhất cần đổi. Nếu không thể đổi được số tiền đúng bằng S thì in ra -1.

	- Constraints: 1<=N<=100; 1<=S<=10^6; 1<=C[i]<=10^6;

	- IP1: 3 10
		   4 5 8

	- OP1: 2
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, s; cin >> n >> s;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    int dp[s + 1];
    dp[0] = 0;
    for (int i = 1; i <= s; i++) {
    	dp[i] = 1e9;
    	for (int j = 1; j <= n; j++) {
    		if (i >= a[j]) {
    			dp[i] = min(dp[i], dp[i - a[j]] + 1);
			}
		}
	}
	if (dp[s] == 1e9) cout << -1;
	else cout << dp[s];
    return 0;
}