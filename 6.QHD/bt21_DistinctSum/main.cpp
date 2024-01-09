#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho mảng A[] gồm N phần tử là số nguyên dương, xét tất cả các tập con của A[] và tính tổng các phần tử trong tập này 
	  (bao gồm cả tập rỗng), sau đó liệt kê các tổng khác nhau có thể tạo thành theo thứ tự tăng dần.

	- Input Format: Dòng đầu tiên là N : số lượng phần tử trong mảng; Dòng thứ 2 gồm N phần tử của mảng A[].

	- Output Format: In ra các tổng có thể tạo thành từ các tập con của A[].

	- Constraints: 1<=N<=100; 1<=A[i]<=100;

	- IP1: 3
		   4 1 2 

	- OP1: 0 1 2 3 4 5 6 7 
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
	int a[n], s = 0;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    	s += a[i];
	}
	int dp[s + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = s; j >= a[i]; j--) {
			if (dp[j - a[i]]) dp[j] = 1;
		}
	}
	for (int i = 0; i <= s; i++) {
		if (dp[i]) cout << i << " ";
	}
    return 0;
}