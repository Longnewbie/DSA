#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho số nguyên dương N. Nhiệm vụ của bạn là hãy liệt kê tất cả các hoán vị của các số từ 1 tới N theo thứ tự ngược.

	- Input Format: Dòng duy nhất chứa số nguyên dương N.

	- Output Format: In ra các hoán vị của N phần tử theo thứ tự ngược.

	- Constraints: 1<=N<=10;

	- IP1: 3

	- OP1: 321
		   312
		   231
		   213
		   132
		   123
*/

//Sử dụng hàm có sẵn:

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int a[n];
    for (int i = 1; i <= n; i++) a[i] = n - i + 1;
    do {
    	for (int i = 1; i <= n; i++) cout << a[i];
    	cout << "\n";
	} while(prev_permutation(a + 1, a + n + 1));
    return 0;
}