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
	- Cho biểu thức S ở dạng hậu, hãy biến đổi S về dạng tiền tố và in ra màn hình.

	- Input Format: Dòng duy nhất chứa biểu thức S.

	- Output Format: In ra biểu thức tiền tố tương ứng.

	- Constraints: 1<=len(S)<=1000.

	- IP1: AB+UV-/

	- OP1: /+AB-UV
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    stack<string> st;
    for (int i = 0; i < s.length(); i++) {
    	if (isalpha(s[i])) st.push(string(1, s[i]));
    	else {
    		string op1 = st.top(); st.pop();
    		string op2 = st.top(); st.pop();
    		string res = s[i] + op2 + op1;
    		st.push(res);
		}
	}
	cout << st.top();
    return 0;
}