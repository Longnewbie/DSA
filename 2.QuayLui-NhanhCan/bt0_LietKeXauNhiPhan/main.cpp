#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Nhập vào một số nguyên dương N (1 ≤ N ≤ 20) hãy đưa ra tất cả các chuỗi nhị phân độ dài N, một chuỗi ghi trên một
	  dòng, các chuỗi được sắp xếp từ bé đến lớn theo thứ tự từ điển,

	- Input Format: Nhập độ dài N.

	- Output Format: In ra theo yêu cầu.

	- Constraints: 1 <= N <= 20.

	- IP1:  3

	- OP1:  000
			001
			010
			011
			100
			101
			110
			111
*/

int n, a[101];

void Try(int i) {
	for (int j = 0; j <= 1; j++) {
		a[i] = j;
		if (i == n) {
			for (int u = 1; u <= n; u++) cout << a[u];
			cout << "\n";
		} else Try(i + 1);
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    Try(1);
    return 0;
}
