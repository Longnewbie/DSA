#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho mảng A[] gồm N phần tử chỉ bao gồm các số 0 và 1. Các số 0 được đặt trước các số 1. Hãy đếm các số 0 với thời gian 
	  log(N).

	- Input Format: Dòng 1 chứa số nguyên dương N; Dòng thứ 2 chứa N số nguyên của mảng A[]

	- Output Format: In ra đáp án của bài toán, nếu số 0 không xuất hiện in ra 0.

	- Constraints: 1<=N<=10^6; 0<=A[i]<=1;

	- IP1: 6
		   0 0 1 1 1 1 

	- OP1: 2
*/

int find(int a[], int l, int r, int x) {
	int res = -1;
	while(l <= r) {
		int m = (r + l)/2;
		if (a[m] == x) {
			res = m;
			r = m - 1;
		} else l = m + 1;
	}
	return res;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    cout << find(a, 0, n - 1, 1);
    return 0;
}