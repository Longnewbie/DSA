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
	- Một số được gọi là lộc phát nếu chỉ có 2 chữ số 6 và 8. Cho số tự nhiên N. Hãy liệt kê các số lộc phát có không quá 
	  N chữ số.

	- Input Format: • Dòng đầu tiên ghi lại số tự nhiên T là số lượng bộ test (T<20);
					 • T dòng kế tiếp mỗi dòng ghi số N.

	- Output Format: Dòng đầu tiên là số lượng số lộc phát tìm được. Dòng thứ hai in ra đáp án theo thứ tự giảm dần.

	- Constraints: N/A

	- IP1:  2
			2
			3

	- OP1:  6
			88 86 68 66 8 6
			14
			888 886 868 866 688 686 668 666 88 86 68 66 8 6
*/

vector<string> v;

void init() {
	queue<string> q;
	q.push("6");
	q.push("8");
	while(1) {
		string res = q.front(); q.pop();
		if (res.size() == 19) break;
		v.pb(res);
		q.push(res + "6");
		q.push(res + "8");
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int t; cin >> t;
    while(t--) {
    	int n, cnt = 0; cin >> n;
    	vector<string> res;
    	for (string x : v) {
    		if (x.size() > n) break;
    		cnt++; res.pb(x);
		}
		reverse(begin(res), end(res));
		cout << cnt << "\n";
		for (string x : res) cout << x << " ";
		cout << "\n";
	}
    return 0;
}