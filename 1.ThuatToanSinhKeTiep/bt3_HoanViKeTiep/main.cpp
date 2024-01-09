#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho số tự nhiên N, bạn được cung cấp một hoán vị của N phần tử từ 1 tới N. Nhiệm vụ của bạn là sinh ra hoán vị kế tiếp của
	  hoán vị được cho, nếu hoán vị được cho là hoán vị cuối cùng thì yêu cầu in ra hoán vị đầu tiên.

	- Input Format: Dòng đầu tiên là số tự nhiên N. Dòng thứ 2 là các số tự nhiên trong hoán vị hiện tại.

	- Output Format: In ra hoán vị kế tiếp trên một dòng.

	- Constraints: 1<=N<=1000;

	- IP1: 6
		   3 1 5 6 2 4 

	- OP1: 3 1 5 6 4 2 
*/

//Làm thủ công: 
int n, ok, a[1001];

void ktao() {
	for (int i = 1; i <= n; i++) cin >> a[i];
}

void sinh() {
	int i = n - 1;
	while(i >= 1 && a[i] > a[i + 1]) --i;
	if (i == 0) {
		for (int i = 1; i <= n; i++) cout << i << " ";
	} else {
		int j = n;
		while(a[i] > a[j]) --j;
		swap(a[i], a[j]);
		reverse(a + i + 1, a + n + 1);
		for (int i = 1; i <= n; i++) cout << a[i] << " ";
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ktao();
    sinh();
    return 0;
}