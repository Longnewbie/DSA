#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Nhiệm vụ của bạn là hãy liệt kê các xâu nhị phân thuận nghịch có độ dài n theo thứ tự từ điển.

	- Input Format: Dòng duy nhất chứa số nguyên dương n.

	- Output Format: In ra các xâu thuận nghịch theo thứ tự từ điển.

	- Constraints: 1<=n<=15;

	- IP1: 4

	- OP1: 0000
		   0110
		   1001
		   1111
*/

int n, ok, a[101];

void ktao() {
	for (int i = 1; i <= n; i++) a[i] = 0;
}

void sinh() {
	int i = n;
	while(i >= 1 && a[i] == 1) {
		a[i--] = 0;
	}
	if (i == 0) ok = 1;
	else a[i] = 1;
}

bool check(string s) {
	string t = s;
	reverse(t.begin(), t.end());
	return t == s;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector<string> v;
    ktao();
    while(!ok) {
    	string s = "";
    	for (int i = 1; i <= n; i++) s += to_string(a[i]);
    	if (check(s)) v.push_back(s);
    	sinh();
	}
	for (string x : v) cout << x << "\n";
    return 0;
}
