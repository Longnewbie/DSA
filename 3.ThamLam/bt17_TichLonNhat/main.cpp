#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho dãy số A gồm N phần tử là các số nguyên. Hãy tính tích lớn nhất của 2 hoặc 3 phần tử trong dãy.

	- Input Format: Dòng đầu tiên là N; Dòng thứ 2 là N phần tử của mảng A.

	- Output Format: In ra tích lớn nhất của 2 hoặc 3 phần tử trong mảng.

	- Constraints: 1<=N<=1000; 0<=abs(A[i])<=10^6.

	- IP1: 5
		   -9 4 3 -3 1 

	- OP1: 108
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
	}
	sort(a, a + n);
	cout << max({abs(1ll * a[0] * a[1]) * a[n - 1],
			     abs(1ll * a[0] * a[1]),
				 abs(1ll * a[n - 1] * a[n - 2] * a[n - 3]),
				 abs(1ll * a[n - 1] * a[n - 2])});
    return 0;
}
