#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho số tự nhiên N, hiện tại bạn được cung cấp một hoán vị của N phần tử các số từ 1 đến N. Nhiệm vụ của bạn là xác định 
	  xem hoán vị này là hoán vị thứ bao nhiêu nếu bạn sinh ra tất cả các hoán vị của tập N phần tử. Ví dụ với N = 3, thì hoán
	  vị 132 là hoán vị thứ 2.

	- Input Format: Dòng đầu tiên là số nguyên dương N. Dòng thứ 2 là N số nguyên của cấu hình hiện tại.

	- Output Format: In ra số thứ tự của hoán vị được cho.

	- Constraints: 1<=N<=10;

	- IP1: 3
		   3 1 2 

	- OP1: 5
*/

int n, ok, a[101];

void ktao() {
	for (int i = 1; i <= n; i++) a[i] = i;
}

void sinh() {
	int i = n - 1;
	while(i >= 1 && a[i] > a[i + 1]) --i;
	if (i == 0) ok = 1;
	else {
		int j = n;
		while(a[i] > a[j]) --j;
		swap(a[i], a[j]);
		reverse(a + i + 1, a + n + 1);
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int b[101];
    for (int i = 1; i <= n; i++) cin >> b[i];
    ktao();
    int cnt = 0;
    while(!ok) {
    	cnt++;
    	bool mark = true;
    	for (int i = 1; i <= n; i++) {
    		if (a[i] != b[i]) mark = false; 
		}
		if (mark) {
			cout << cnt;
			return 0;
		}
		sinh();
	}
    return 0;
}
