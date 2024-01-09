#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho mảng A[] gồm N số nguyên. Nhiệm vụ của bạn là sắp xếp lại mảng số với số lượng bước là ít nhất. Tại mỗi bước, bạn
	  chỉ được phép chèn phần tử bất kỳ của mảng vào vị trí bất kỳ trong mảng. Ví dụ A[] = {2, 3, 5, 1, 4, 7, 6 }sẽ cho ta 
	  số phép chèn ít nhất là 3 bằng cách lấy số 1 chèn trước số 2, lấy số 4 chèn trước số 5, lấy số 6 chèn trước số 7 ta 
	  nhận được mảng được sắp.

	- Input Format: Dòng đầu tiên là N; Dòng thứ 2 gồm N phần tử của mảng A;

	- Output Format: Đưa ra kết quả trên 1 dòng.

	- Constraints: 1<=N<=1000; 1<=A[i]<=1000;

	- IP1: 13
		   143 340 571 845 211 228 274 443 666 594 491 814 24 

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
    		if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	cout << n - *max_element(dp, dp + n);
    return 0;
}