#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho một xâu kí tự S chỉ bao gồm các kí tự '(' hoặc kí tự ')'. S có độ dài là số chẵn có giá trị N. Xâu S gồm N / 2 kí tự
	  mở ngoặc và N / 2 kí tự đóng ngoặc. Ở mỗi thao tác các bạn được lựa chọn 1 kí tự bất kì của S để đưa về vị trí đầu tiên
	  hoặc vị trí cuối cùng của dãy. Các bạn hãy xác định số thao tác tối thiểu cần thực hiện để tạo được 1 xâu dấu ngoặc hợp 
	  lệ. Một số ví dụ về xâu hợp lệ : (), (((()))), ()((()))...

	- Input Format: Một dòng duy nhất chứa xâu S

	- Output Format: In ra số thao tác tối thiểu cần thực hiện.

	- Constraints: 1<=N<=1000;

	- IP1: )))((((())

	- OP1: 3
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    stack<char> st;
    int d = 0;
    for (char x : s) {
    	if (x == '(') st.push(x);
    	else {
    		if (!st.empty()) {
    			if (x == ')')st.pop();
    			} else d++;
			}
	}
	cout << d;
    return 0;
}
