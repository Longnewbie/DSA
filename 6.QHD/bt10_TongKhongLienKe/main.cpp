#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho mảng A[] gồm N phần tử, nhiệm vụ của bạn là tính tổng lớn nhất của dãy con trong mảng với một điều kiện đó là trong 
	  dãy con này không được có 2 phần tử nằm liền kề nhau.

	- Input Format: Dòng đầu tiên là N : số lượng phần tử trong mảng; Dòng thứ 2 là A[i];

	- Output Format: In ra kết quả của bài toán.

	- Constraints: 1<=N<=10^6; 1<=A[i]<=1000;

	- IP1:  7
			314 514 148 451 896 589 296 
	- OP1:  1706
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n; int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[1] = a[1];
    for (int i = 2; i <= n; i++) {
    	dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
	}
	cout << dp[n];
    return 0;
}