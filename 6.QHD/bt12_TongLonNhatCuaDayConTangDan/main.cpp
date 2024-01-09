#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho dãy số A[] gồm N số. Nhiệm vụ của bạn là tìm tổng lớn nhất của dãy con được sắp theo thứ tự tăng dần của dãy A[].
	  Ví dụ với dãy A[] = {1, 101, 2, 3, 100, 4, 5} ta có kết quả là 106 = 1 + 2 + 3 + 100. Với dãy A[] = {10, 7, 5} ta có
	  kết quả là 10. Với dãy A[] = {1, 2, 3, 5} ta có kết quả là 11.

	- Input Format: Dòng đầu tiên đưa vào N là số phần tử của dãy A[]; Dòng tiếp theo đưa vào N số A[i]; các số được viết cách
	  nhau một vài khoảng trống.

	- Output Format: Đưa ra kết quả của bài toán trên 1 dòng.

	- Constraints: 1≤N≤1000; 0≤A[i]≤1000.

	- IP1:  8
			2 12 3 15 3 16 11 4 

	- OP1: 	45
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int a[n + 1];
    for (int i = 0; i < n; i++) cin >> a[i];
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
    	dp[i] = a[i];
    	for (int j = 0; j < i; j++) {
    		if (a[i] > a[j]) {
    			dp[i] = max(dp[i], dp[j] + a[i]);
			}
		}
	}
	cout << *max_element(dp, dp + n);
    return 0;
}