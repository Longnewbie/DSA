#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho dãy số nguyên A[] gồm N phần tử, nhiệm vụ của bạn là tính tổng của dãy con có tổng lớn nhất.

	- Input Format: Dòng đầu tiên chứa số nguyên dương N; Dòng thứ 2 chứa N số nguyên của dãy A[].

	- Output Format: In ra đáp án của bài toán.

	- Constraints: 1<=N<=10^5; 1<=abs(A[i])<=10^6.

	- IP1: 5
		  -3 6 1 -3 6 

	- OP1: 10
*/

ll MaximumCrossing(int a[], int l, int r, int m) {
	ll s_right = 0, s_left = 0, res_left = 0, res_right = 0;
	//Tong tu left -> mid;
	for (int i = m; i >= l; i--) {
		s_left += a[i];
		res_left = max(res_left, s_left);
	}
	//Tong tu mid -> right;
	for (int i = m + 1; i <= r; i++) {
		s_right += a[i];
		res_right = max(res_right, s_right);
	}
	return res_left + res_right;
}

ll MaximumSubArr(int a[], int l, int r) {
	if (l >= r) return 0;
	if (l == r) return a[l];
	int m = (l + r)/2;
	//Tong cac phan tu ben trai, tong cac phan tu ben phai, tong cac ptu di qua mid
	return max({MaximumSubArr(a, l, m), MaximumSubArr(a, m + 1, r), MaximumCrossing(a, l, r, m)});
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    cout << MaximumSubArr(a, 0, n - 1);
    return 0;
}