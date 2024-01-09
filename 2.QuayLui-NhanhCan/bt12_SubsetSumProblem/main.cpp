#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho mảng A[] gồm n phần tử, hãy xác định xem có thể chia mảng A[] thành 2 tập sao cho tổng của 2 tập bằng nhau hay không ?

	- Input Format: Dòng đầu tiên là số nguyên n; Dòng thứ 2 gồm n số nguyên của mảng A[]

	- Output Format: In ra 1 nếu có thể chia mảng thành 2 phần bằng nhau, ngược lại in 0.

	- Constraints: 1<=n<=20; 1<=A[i]<=100;

	- IP1: 5
		   9 9 4 4 5 

	- OP1: 0
	
	- IP1: 4
		   1 2 3 4

	- OP1: 1
*/

int n, a[101], ok, s;

void Try(int i, int bd, int sum) {
	if (ok) return; //nhanh can
	for (int j = bd; j <= n; j++) {
		if (sum + a[j] <= s) {
			if (sum + a[j] == s) {
				ok = 1;
				return;
			} else Try(i + 1, j + 1, sum + a[j]);
		}
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    	s += a[i];
	}
    if (s % 2 == 0) {
    	s /= 2;
    	Try(1, 1, 0);
    	cout << ok;
	} else cout << "0";
    return 0;
}