#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho mảng đã được sắp xếp A[] gồm N phần tử không có hai phần tử giống nhau và số X. Nhiệm vụ của bạn là tìm floor(X). 
	  Trong đó, K=floor(X) là phần tử lớn nhất trong mảng A[] nhỏ hơn hoặc bằng X.

	- Input Format: Dòng 1 chứa 2 số N và X; Dòng 2 chứa N số của mảng A[].

	- Output Format: In ra đáp án của bài toán nếu tìm thấy số lớn hơn X, trường hợp không tìm thấy in -1.

	- Constraints: 1<=N<=10^5; 1<=X,A[i]<=10^6;

	- IP1: 9 8
		   1 2 3 4 5 6 7 8 9 

	- OP1: 8
*/

int find(int a[], int l, int r, int x) {
	if (l > r) return -1;
	int m = (r + l)/2;
	if (a[m] <= x) {
		int res = find(a, m + 1, r, x);
		if (res != -1) return res;
		return m;
	} 
	return find(a, l, m - 1, x);
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x; cin >> n >> x;
    int a[n];
    for (int &x : a) cin >> x;
    int k = find(a, 0, n - 1, x);
    if (a[k] != -1) cout << a[k];
    else cout << -1;
    return 0;
}