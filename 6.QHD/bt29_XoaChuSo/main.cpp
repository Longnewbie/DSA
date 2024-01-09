#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Bạn được cung cấp một số nguyên n. Trên mỗi bước, bạn có thể trừ một trong các chữ số khỏi số. Cần thực hiện bao nhiêu 
	  bước để số đó bằng 0?

	- Input Format: Dòng duy nhất chứa số nguyên n.

	- Output Format: In ra số bước tối thiểu.

	- Constraints: 1<=n<=10^6;

	- IP1: 4

	- OP1: 1
	
	- IP2: 27

	- OP2: 5
	
	Explanation 1: Các bước thực hiện : 27→20→18→10→9→0
*/

int F[1000001];

int solve(int n) {
	if (n == 0) return 0;
	if (F[n]) return F[n];
	int m = n, res = 1e9;
	while(m) {
		int r = m % 10;
		if (r != 0) res = min(res, solve(n - r) + 1);
		m /= 10;
	}
	return F[n] = res;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    cout << solve(n);
    return 0;
}