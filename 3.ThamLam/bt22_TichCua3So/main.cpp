#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho số nguyên dương N, nhiệm vụ của bạn là kiểm tra xem có thể viết N = a * b * c hay không, trong đó a, b, c là 3 
	  số nguyên dương lớn hơn hoặc bằng 2 khác nhau.

	- Input Format: Dòng duy nhất chứa số nguyên dương N.

	- Output Format: In ra YES nếu có thể biểu diễn N dưới dạng tích của 3 số, ngược lại in ra NO.

	- Constraints: 2<=N<=10^9.

	- IP1: 11

	- OP1: NO
	
	- IP1: 24

	- OP1: YES
*/

bool check(int n) {
	int d = 0, se = 0;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			d++;
			int e = 0;
			while(n % i == 0) {
				e++;
				n /= i;
			}
			se += e;
		}
	}
	if (n != 1) {
		d++; se++;
	}
	if (d >= 3 || d == 2 && se >= 4 || d == 1 && se >= 6) return true;
	return false;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    if (check(n)) cout << "YES";
    else cout << "NO";
    return 0;
}
