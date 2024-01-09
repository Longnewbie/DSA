#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho 4 số nguyên X, Y, Z, T. Nhiệm vụ của bạn là tìm giá trị lớn nhất của biểu thức X o1 Y o2 Z o3 T, trong đó o1, o2, o3 
	  có thể là các dấu +, -.

	- Input Format: Dòng duy nhất gồm 4 số X, Y, Z, T.

	- Output Format: In ra giá trị lớn nhất của biểu thức.

	- Constraints: -10^5<=X,Y,Z,T<=10^4

	- IP1: 59 71 80 -3

	- OP1: 213
*/

int x, y, z, t, ok, a[1001];

void ktao() {
	cin >> x >> y >> z >> t;
	for (int i = 1; i <= 3; i++) a[i] = 0;
}

void sinh() {
	int i = 3;
	while(i >= 1 && a[i] == 1) {
		a[i--] = 0;
	}
	if (i == 0) ok = 1;
	else a[i] = 1;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ktao();
    ll res = -1e9;
    while(!ok) {
    	ll ans = x;
    	if (a[1]) ans += y;
    	else ans -= y;
    	if (a[2]) ans += z;
    	else ans -= z;
    	if (a[3]) ans += t;
    	else ans -= t;
    	res = max(res, ans);
    	sinh();
	}
	cout << res;
    return 0;
}
