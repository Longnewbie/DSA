#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Có n quả táo với khối lượng đã biết. Nhiệm vụ của bạn là chia táo thành hai nhóm sao cho sự khác biệt giữa trọng lượng
	  của 2 nhóm là nhỏ nhất.

	- Input Format: Dòng 1 là số nguyên dương N : số lượng quả táo. Dòng thứ 2 là N số nguyên p1,p2,...,pn là trọng lượng tương
	  ứng của các quả táo.

	- Output Format: In ra độ chênh lệch nhỏ nhất giữa 2 nhóm táo.

	- Constraints: 1<=N<=20; 1<=pi<=10^9;

	- IP1: 5
		   3 2 7 4 1

	- OP1: 1
*/

int n, ok, a[101], b[101];

void sinh() {
	int i = n;
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
    cin >> n;
    for (int i = 1; i <= n; i++) {
    	cin >> b[i];
		a[i] = 0;	
	}
	ll res = 1e9;
	while(!ok) {
		ll s1 = 0, s2 = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0) s1 += b[i];
			else s2 += b[i];
		}
		res = min(res, abs(s1 - s2));
		sinh();
	}
	cout << res;
    return 0;
}
