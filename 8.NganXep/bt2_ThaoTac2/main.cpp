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
	- Yêu cầu bạn xây dựng một stack với các truy vấn sau đây: “push x”: Thêm phần tử x vào stack. “top”: In ra phần tử đầu tiên
	  của stack. Nếu stack rỗng, in ra “NONE”. “pop”: Xóa phần tử đầu tiên của stack. Nếu stack rỗng, không làm gì cả.

	- Input Format: Dòng đầu tiên là số lượng truy vấn T T≤ 1000). Mỗi truy vấn có dạng như trên.

	- Output Format: Với mỗi truy vấn “top”, hãy in ra phần tử đầu tiên của stack. Nếu stack rỗng, in ra “NONE”.

	- Constraints: N/A.

	- IP1:  8
			push 815
			push 30
			top
			push 242
			push 502
			top
			push 876
			top

	- OP1:  30
			502
			876
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    stack<int> st;
    while(n--) {
    	string tt; cin >> tt;
    	if (tt == "push") {
    		int x; cin >> x;
    		st.push(x);
		} else if (tt == "top") {
			if (st.empty()) cout << "NONE\n";
			else cout << st.top() << "\n";
		} else {
			if (!st.empty()) st.pop();
		}
	}
    return 0;
}

