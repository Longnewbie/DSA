#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho số nguyên dương N và K, nhiệm vụ của bạn là liệt kê các xâu nhị phân có độ dài N và có K bit 1 theo thứ tự từ 
	  điển tăng dần. Sau đó tiếp tục liệt kê các xâu nhị phân mà chỉ có duy nhất K bit 1 liên tiếp.

	- Input Format: 1 dòng chứa 2 số nguyên dương N và K.

	- Output Format: Dòng đầu tiên in ra các xâu nhị phân có K bit 1. Dòng thứ 2 in ra các xâu nhị phân có duy nhất K 
	  bit 1 liên tiếp.

	- Constraints: 1<=K<=N<=15;

	- IP1: 3 2

	- OP1: 011 101 110 
		   011 110 
*/

int n, k, ok, a[101];

void ktao() {
	for (int i = 1; i <= n; i++) a[i] = 0;
}

void sinh() {
	int i = n;
	while(i >= 1 && a[i] == 1) {
		a[i] = 0;
		--i;
	}
	if (i == 0) ok = 1;
	else a[i] = 1;
}

bool check1() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i]) cnt++;
	}
	return cnt == k;
}

bool check2() {
	int cnt = 0, res = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i]) {
			cnt++;
		} else cnt = 0;
		if (cnt >= k) res++;
	}
	return res == 1;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    vector<vector<int>> v;
    ktao();
    while(!ok) {
    	if (check1()) {
    		for (int i = 1; i <= n; i++) cout << a[i];
    		cout << " ";
		}
		if (check2()) {
			vector<int> tmp(a + 1, a + n + 1);
			v.push_back(tmp);
		}
		sinh();
	}
	cout << "\n";
	for (auto x : v) {
		for (int it : x) {
			cout << it;
		}
		cout << " ";
	}
    return 0;
}
