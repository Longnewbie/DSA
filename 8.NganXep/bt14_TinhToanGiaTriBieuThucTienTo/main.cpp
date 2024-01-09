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
	- Cho biểu thức tiền tố S, các số trong biểu thức chỉ là số có 1 chữ số, yêu cầu tính toán giá trị của biểu thức.

	- Input Format: Dòng duy nhất chứa biểu thức S.

	- Output Format: In ra giá trị của biểu thức S.

	- Constraints: S có độ dài không quá 1000.

	- IP1: +-7/451
	- OP1: 8
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    stack<int> st;
    for (int i = s.length() - 1; i >= 0; i--) {
    	if (isdigit(s[i])) st.push(s[i] - '0');
    	else {
    		int op1 = st.top(); st.pop();
    		int op2 = st.top(); st.pop();
    		if (s[i] == '+') st.push(op1 + op2);
    		else if (s[i] == '-') st.push(op1 - op2);
    		else if (s[i] == '*') st.push(op1 * op2);
    		else st.push(op1 / op2);
		}
	}
	cout << st.top();
    return 0;
}