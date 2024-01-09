#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho 2 số nguyên dương N và K. Nhiệm vụ của bạn là sinh ra chỉnh hợp lặp chập K của N phần tử gồm các số tự nhiên từ 1 
	  đến N. Ví dụ N = 3, K = 2 bạn sẽ có các kết quả là : 11, 12, 13, 21, 22, 23, 31, 32, 33. Số chỉnh hợp lặp chập K của
	  N sẽ là N^K.

	- Input Format: 1 dòng duy nhất chứa 2 số nguyên dương N và K.	

	- Output Format: In ra các cấu hình của chỉnh hợp lặp chập K của N

	- Constraints: 1<=K,N<=8	

	- IP1: 2 4

	- OP1: 1111
		   1112
		   1121
		   1122
		   1211
		   1212
		   1221
		   1222
		   2111
		   2112
		   2121
		   2122
		   2211
		   2212
		   2221
		   2222
*/

int n, k, ok, a[101];

void ktao() {
	for (int i = 1; i <= n; i++) a[i] = 1;
}

void sinh() {
	int i = n;
	while(i >= 1 && a[i] == k) {
		a[i] = 1;
		--i;
	}
	if (i == 0) ok = 1;
	else a[i]++;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> k >> n;
    ktao();
    while(!ok) {
    	for (int i = 1; i <= n; i++) cout << a[i];
    	cout << "\n";
    	sinh();
	}
    return 0;
}
