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
	- Cho một xâu kí tự S chỉ bao gồm kí tự in thường, nhiệm vụ của bạn là xóa các kí tự liền kề giống nhau khỏi xâu S. Ví dụ 
	  xâu aabbccc sau khi xóa các kí tự liền kề sẽ thành c, xâu abba sau khi xóa các kí tự liền kề sẽ thành xâu rỗng.

	- Input Format: Dòng duy nhất chứa xâu kí tự S.

	- Output Format: In ra xâu S sau khi xóa các kí tự liền kề giống nhau, nếu xâu sau khi xóa rỗng thì in ra EMPTY.

	- Constraints: 1<=len(S)<=10000;

	- IP1: dddbbabcb

	- OP1: dabcb
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    stack<char> st;
    for (char x : s) {
    	if (st.empty()) st.push(x);
		else if (st.top() == x) st.pop();
		else st.push(x); 
	}
	if (st.empty()) {
		cout << "EMPTY";
		return 0;
	}
	string res = "";
	while(!st.empty()) {
		res += st.top(); st.pop();
	}
	reverse(begin(res), end(res));
	cout << res;
    return 0;
}

