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
	- Cho hai số nguyên L, R. Hãy đưa ra số các số K nguyên dương trong khoảng [L, R] thỏa mãn điều kiện: 
	  • Tất cả các chữ số của K đều khác nhau. 
	  • Tất cả các chữ số của K đều nhỏ hơn hoặc bằng 5. Ví dụ với L = 4, R = 13 ta có 5 số thỏa mãn yêu cầu 
	    là 4, 5, 10, 12, 13,

	- Input Format: • Dòng đầu tiên đưa vào số lượng test T. 
					• Dòng tiếp theo đưa vào các bộ test. Mỗi bộ test được là một cặp L, R được viết trên một dòng.

	- Output Format: • Đưa ra kết quả mỗi test theo từng dòng.

	- Constraints: • T, L, R thỏa mãn ràng buộc: 1≤T≤100; 0≤L≤R≤10^5.

	- IP1:  8
			9 41
			91 163
			28 59
			12 38
			72 127
			48 68
			50 101
			22 100

	- OP1:  17
			20
			15
			14
			8
			5
			5
			18
*/

bool check(int n) {
	set<int> se;
	while(n) {
		if (se.count(n % 10)) return false;
		se.insert(n % 10);
		n /= 10;
	}
	return true;
}

vector<int> res;

void init() {
	queue<int> q;
	for (int i = 1; i <= 5; i++) q.push(i);
	while(1) {
		int top = q.front(); q.pop();
		res.pb(top);
		if (top >= 1e5) break;
		for (int i = 0; i <= 5; i++) {
			int tmp = top * 10 + i;
			if (check(tmp)) {
				q.push(tmp);
			}
		} 
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int t; cin >> t;
    while(t--) {
    	int l, r; cin >> l >> r;
    	int cnt = 0;
    	for (int x : res) {
    		if (x >= l && x <= r) cnt++;
		}
		cout << cnt << "\n";
	}
    return 0;
}