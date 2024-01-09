#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho mảng số nguyên A[] gồm N phần tử, hãy tìm dãy con (không nhất thiết các phần tử phải liên tiếp) tăng chặt 
	  dài nhất của mảng A.

	- Input Format: Dòng đầu tiên là N; Dòng thứ 2 gồm N phần tử của mảng A;

	- Output Format: In ra độ dài của dãy con tăng dài nhất

	- Constraints: 1<=N<=1000; 1<=A[i]<=1000;

	- IP1: 14
		   128 104 53 876 660 961 754 775 290 231 224 915 392 994 

	- OP1: 6
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
    	dp[i] = 1;
    	for (int j = 0; j < i; j++) {
    		if (a[i] > a[j]) {
    			dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	cout << *max_element(dp, dp + n);
    return 0;
}