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
	- Cho một ngăn xếp các số nguyên. Các thao tác gồm 3 lệnh: push, pop và show. Trong đó thao tác push kèm theo một giá trị 
	  cần thêm . Hãy viết chương trình ghi ra kết quả của các lệnh show. Trong trường hợp lệnh pop thì ngăn xếp rỗng sẽ không 
	  được thực hiện.

	- Input Format: Input: Dòng đầu là số thao tác T; T dòng tiếp theo mỗi dòng chứa một lệnh push, pop hoặc show. Input đảm 
	  bảo số lượng phần tử trong stack khi nhiều nhất cũng không vượt quá 100.

	- Output Format: Ghi ra màn hình các phần tử đang có trong stack theo thứ tự lưu trữ mỗi khi gặp lệnh show. Các số viết
	  cách nhau đúng một khoảng trống. Nếu stack rỗng thì in ra EMPTY

	- Constraints: 1<=T<=100;

	- IP1:  9
			show
			push 346
			push 196
			push 946
			show
			show
			push 943
			push 265
			push 225

	- OP1:  EMPTY
			346 196 946 
			346 196 946 
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
    		int x; cin >> x; st.push(x);
		} else if (tt == "show") {
			if (st.empty()) cout << "EMPTY\n";
			else {
				vector<int> res;
				while(!st.empty()) {
					res.pb(st.top()); st.pop();
				}
				if (res.size() == 0) cout << "EMPTY";
				else {
					reverse(begin(res), end(res));
					for (int x : res) {
						cout << x << " ";
						st.push(x);
					}
				}
				cout << "\n";
			}
		} else {
			if (!st.empty()) st.pop();
		}
	}
    return 0;
}

