#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Một số được coi là số đẹp nếu nó chỉ bao gồm 2 số là 8 và 0. Bạn được cấp một số nguyên dương X, nhiệm vụ của bạn là tìm 
	  bội dương nhỏ nhất của X thỏa mãn bội này là số đẹp.

	- Input Format: Dòng đầu tiên là số bộ test T. T dòng tiếp theo mỗi dòng là một số nguyên dương N.

	- Output Format: Mỗi test in kết quả trên 1 dòng.

	- Constraints: 1<=T<=300; 1<=N<=300;

	- IP1: 6
		   240
		   19
		   55
		   47
		   287
		   247

	- OP1: 
*/

int n, ok, a[101];

void ktao() {
	for (int i = 1; i <= n; i++) a[i] = 0;
	a[n] = 8;
}

void sinh() {
	int i = n;
	while(i >= 1 && a[i] == 8) {
		a[i] = 0;
		--i;
	}
	if (i == 0) ok = 1;
	else a[i] = 8;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	n = 19;
	vector<ll> v;
	ktao();
	while(!ok) {
		ll tmp = 0;
		for (int i = 1; i <= n; i++) tmp = tmp * 10 + a[i];
		v.push_back(tmp);
		sinh();
	}
	int q; cin >> q;
	while(q--) {
		int k; cin >> k;
		for (ll x : v) {
			if (x % k == 0) {
				cout << x << "\n";
				break;
			}
		}
	} 
    return 0;
}