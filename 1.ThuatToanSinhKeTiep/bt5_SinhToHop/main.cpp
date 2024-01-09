#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho hai số nguyên dương N và K. Nhiệm vụ của bạn là hãy liệt kê tất cả các tập con K phần tử của các số từ 1 tới N.

	- Input Format: 2 số nguyên dương N và K.

	- Output Format: In ra các tổ hợp trên từng dòng.

	- Constraints: 1<=K<=N<=15;

	- IP1: 5 2

	- OP1: 12
		   13
		   14
		   15
		   23
		   24
		   25
		   34
		   35
		   45
*/

int n, k, ok, a[101];

void ktao() {
	for (int i = 1; i <= k; i++) a[i] = i;
}

void sinh() {
	int i = k;
	while(i >= 1 && a[i] == n - k + i) --i;
	if (i == 0) ok = 1;
	else {
		a[i]++;
		for (int j = i + 1; j <= k; j++) a[j] = a[j - 1] + 1;
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ktao();
    while(!ok) {
    	for (int i = 1; i <= k; i++) cout << a[i];
    	cout << "\n";
    	sinh();
	}
    return 0;
}