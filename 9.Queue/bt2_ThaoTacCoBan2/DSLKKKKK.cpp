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
	- Yêu cầu bạn xây dựng một queue với các truy vấn sau đây: “PUSH x”: Thêm phần tử x vào cuối của queue (0 ≤ x ≤ 1000). 
	  “PRINTFRONT”: In ra phần tử đầu tiên của queue. Nếu queue rỗng, in ra “NONE”. “POP”: Xóa phần tử ở đầu của queue. 
	  Nếu queue rỗng, không làm gì cả.

	- Input Format: Dòng đầu tiên là số lượng truy vấn Q (Q ≤ 100000). Mỗi truy vấn có dạng như trên.

	- Output Format: Với mỗi truy vấn “PRINT”, hãy in ra phần tử đầu tiên của queue. Nếu queue rỗng, in ra “NONE”.

	- Constraints: N/A

	- IP1:  10
			PUSH 681
			POP
			PUSH 405
			PUSH 983
			PUSH 147
			POP
			PUSH 417
			PUSH 918
			PRINTFRONT
			POP

	- OP1:  983
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    queue<int> q;
    int t; cin >> t;
    while(t--) {
    	string s; cin >> s;
    	if (s == "PUSH") {
    		int x; cin >> x;
    		q.push(x);
		} else if (s == "POP") {
			if (!q.empty()) q.pop();
		} else {
			if (q.empty()) cout << "NONE\n";
			else cout << q.front() << "\n";
		}
	}
    return 0;
}