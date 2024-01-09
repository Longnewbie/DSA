#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Tèo có N thẻ bài, mỗi thẻ ghi một con số từ 1 tới N. Không có 2 thẻ nào ghi hai số trùng nhau. Tèo muốn xếp thứ tự các 
	  thẻ bài sao cho không có hai con số nào liền kề nhau ở cạnh nhau.

	- Input Format: Số nguyên dương N.

	- Output Format: In ra các cấu hình thỏa mãn theo thứ tự từ điển tăng dần.

	- Constraints: 4<=N<=10;

	- IP1: 4

	- OP1: 2413
		   3142
*/

//Sử dụng hàm có sẵn:

int n, ok, a[101];

void ktao() {
    cin >> n;
	for (int i = 1; i <= n; i++) a[i] = i;
}

bool check() {
	for (int i = 2; i <= n; i++) {
		if (abs(a[i] - a[i - 1]) == 1) return false;
	}
	return true;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ktao();
	do {
		if (check()) {
			for (int i = 1; i <= n; i++) cout << a[i];
			cout << "\n";
		}
	} while(next_permutation(a + 1, a + n + 1));
    return 0;
}