#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back
#define pii pair<int,int>
#define pip pair<int,pair<int,int>>
int mod = 1e9+7;

/*
	- Yêu cầu bạn xây dựng một hàng đợi hai đầu với các truy vấn sau đây: - “PUSHFRONT x”: Thêm phần tử x vào đầu của dequeue
	  (0 ≤ x ≤ 1000). - “PRINTFRONT”: In ra phần tử đầu tiên của dequeue. Nếu dequeue rỗng, in ra “NONE”. - “POPFRONT”: Xóa 
	  phần tử đầu của dequeue. Nếu dequeue rỗng, không làm gì cả. - “PUSHBACK x”: Thêm phần tử x vào cuối của dequeue 
	  (0 ≤ x ≤ 1000). - “PRINTBACK”: In ra phần tử cuối của dequeue. Nếu dequeue rỗng, in ra “NONE”. - “POPBACK”: Xóa phần tử 
	  cuối của dequeue. Nếu dequeue rỗng, không làm gì cả.

	- Input Format: Dòng đầu tiên là số lượng truy vấn Q (Q ≤ 100000). Mỗi truy vấn có dạng như trên.

	- Output Format: Với mỗi truy vấn “PRINTFRONT” và “PRINTBACK”, hãy in ra kết quả trên một dòng.

	- Constraints: N/A 

	- IP1:  10
			PUSHBACK 327
			PUSHFRONT 354
			PRINTBACK
			PUSHBACK 999
			POPBACK
			POPBACK
			POPBACK
			PRINTBACK
			PUSHBACK 549
			POPFRONT

	- OP1:  327
			NONE
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    deque<int> dq;
    int t; cin >> t;
    while(t--) {
    	string s; cin >> s;
    	if (s == "PUSHFRONT") {
    		int x; cin >> x;
    		dq.pf(x);
		} else if (s == "PRINTFRONT") {
			if (dq.empty()) cout << "NONE\n";
			else cout << dq.front() << "\n";
		} else if (s == "POPFRONT") {
			if (!dq.empty()) dq.popf();
		} else if (s == "PUSHBACK") {
			int x; cin >> x;
			dq.pb(x);
		} else if (s == "PRINTBACK") {
			if (dq.empty()) cout << "NONE\n";
			else cout << dq.back() << "\n"; 
		} else {
			if (!dq.empty()) dq.popb();
		}
	}
    return 0;
}