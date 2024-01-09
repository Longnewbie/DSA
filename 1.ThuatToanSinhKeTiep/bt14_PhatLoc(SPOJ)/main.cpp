#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Một xâu ký tự số chỉ bao gồm các chữ số 6 và 8 sẽ được gọi là “phát lộc” nếu thỏa mãn các điều kiện sau: Chữ số đầu tiên
	  là chữ số 8, chữ số cuối cùng là chữ số 6. Không có 2 chữ số 8 nào ở cạnh nhau. Không có nhiều hơn 3 chữ số 6 ở cạnh
	  nhau. Viết chương trình liệt kê các xâu ký tự phát lộc độ dài N theo thứ tự tăng dần.

	- Input Format: Số nguyên dương N. 

	- Output Format: Các xâu lộc phát thỏa mãn điều kiện.

	- Constraints: 2<=N<=15;

	- IP1: 7 

	- OP1: 8666866
		   8668666
		   8668686
		   8686686
		   8686866
*/

int n, ok, a[101];

void ktao() {
	a[1] = 8; a[2] = 6; a[n] = 6;
	for (int i = 3; i <= n - 1; i++) a[i] = 6;
}

void sinh() {
	int i = n - 1;
	while(i >= 2 && a[i] == 8) {
		a[i] = 6;
		--i;
	} 
	if (i == 1) ok = 1;
	else a[i] = 8;
}

bool check() {
	int d6 = 0, d8 = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 6) {
			d6++;
			d8 = 0;
		} else {
			d8++;
			d6 = 0;
		}
		if (d8 >= 2 || d6 > 3) return false;
	}
	return true;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ktao();
    while(!ok) {
    	if (check()) {
	    	for (int i = 1; i <= n; i++) cout << a[i];
	    	cout << "\n";
	    }
    	sinh();
	} 
    return 0;
}
