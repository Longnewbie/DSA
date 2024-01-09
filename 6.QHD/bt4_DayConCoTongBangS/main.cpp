#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho mảng số nguyên A[] gồm N phần tử và số nguyên dương S, nhiệm vụ của bạn hãy xác định xem có thể tạo ra một tập con
	  các phần tử trong mảng có tổng bằng S hay không? Chú ý mỗi phần tử trong mảng chỉ được sử dụng một lần.

	- Input Format: Dòng đầu tiên gồm 2 số N và S; Dòng thứ 2 gồm N số của mảng A;

	- Output Format: In ra 1 nếu có tập con của A có tổng bằng S, ngược lại in ra 0.

	- Constraints: 1<=N<=200; 1<=S<=50000; 1<=A[i]<=500;

	- IP1: 8 92
		   69 16 82 170 31 24 45 112 

	- OP1: 1
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, s; cin >> n >> s;
    int a[n + 1];
    for (int i = 0; i < n; i++) cin >> a[i];
    int dp[s + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
    	for (int j = s; j >= a[i]; j--) {
    		if (dp[j - a[i]]) dp[j] = 1;
		}
	}
	if (dp[s]) cout << 1;
	else cout << 0;
    return 0;
}