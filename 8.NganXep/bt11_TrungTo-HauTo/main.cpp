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
	- Cho biểu thức S ở dạng trung tố, hãy biến đổi S về dạng hậu tố và in ra màn hình.

	- Input Format: Dòng duy nhất chứa biểu thức S chỉ chứa các toán tử +, -, *, / và các chữ cái.

	- Output Format: In ra biểu thức hậu tố tương ứng.

	- Constraints: 1<=len(S)<=1000.

	- IP1: (X+(Y-Z))

	- OP1: XYZ-+
*/

int uutien(char x) {
	if (x == '^') return 3;
	else if (x == '*' || x == '/') return 2;
	else if (x == '+' || x == '-') return 1;
	return 0;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    string res = "";
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
    	if (isalpha(s[i])) res += s[i];
		else if (s[i] == '(') st.push(s[i]);
		else if (s[i] == ')') {
			while(st.top() != '(') {
				res += st.top(); st.pop();
			} 
			st.pop();
		} else {
			while(!st.empty() && uutien(st.top()) >= uutien(s[i])) {
				res += st.top(); st.pop();
			}
			st.push(s[i]);
		}
	}
	while(!st.empty()) {
		res += st.top(); st.pop();
	}
	cout << res;
    return 0;
}