#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
#define pii pair<int,int>
#define pip pair<int,pair<int,int>>
int mod = 1e9+7;

/*
	- Ta gọi số nguyên dương K là một số BDN nếu các chữ số trong K chỉ bao gồm các 0 hoặc 1 có nghĩa. Ví dụ số K = 1, 10, 101.
	  Cho số tự nhiên N (N<=2^63). Hãy cho biết có bao nhiêu số BDN nhỏ hơn N. Ví dụ N=100 ta có 3 số BDN bao gồm các 
	  số: 1, 10, 11.

	- Input Format: Dòng đầu tiên ghi lại số tự nhiên T là số lượng Test; T dòng kế tiếp mỗi dòng ghi lại một bộ Test. Mỗi test 
	  là một số tự nhiên N.

	- Output Format: Đưa ra kết quả mỗi test theo từng dòng.

	- Constraints: 1<=T<=100; 1<=N<=2^63

	- IP1:  12
			27655
			16862
			30017
			12246
			26510
			6386
			3668
			6127
			27269
			24195
			20859
			5416

	- OP1:  31
			31
			31
			31
			31
			15
			15
			15
			31
			31
			31
			15
*/

vector<ll> v;
void init() {
	queue<ll> q;
	q.push(1);
	while(1) {
		ll res = q.front(); q.pop();
		if (res >= 1e18) break;
		v.pb(res);
		q.push(res * 10);
		q.push(res * 10 + 1);
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int t; cin >> t;
    while(t--) {
    	ll n; cin >> n;
    	int cnt = 0;
    	for (ll x : v) {
    		if (x >= n) break;
			cnt++; 
		}
		cout << cnt << "\n";
	}
    return 0;
}