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
	- Cho một biểu thức số học đúng nhưng có thể dư thừa dấu ngoặc, nhiệm vụ của bạn là kiểm tra xem biểu thức này có dư
	  thừa dấu đóng mở ngoặc hay không.

	- Input Format: Dòng duy nhất chứa biểu thức cần kiểm tra.

	- Output Format: In ra YES nếu biểu thức dư thừa dấu ngoặc, ngược lại in ra NO.

	- Constraints: Biểu thức chỉ chứa kí tự đóng mở ngoặc, các chữ cái in thường và các phép toán + - * / không quá 100 kí tự.

	- IP1: ((x+y))

	- OP1: YES
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    stack<int> st;
    int ok = 0;
    for (int i = 0; i < s.length(); i++) {
    	if (s[i] == '(') st.push(i);
    	else if (s[i] == ')') {
    		int x = st.top(); st.pop();
    		if (s[x + 1] == '(' && s[i - 1] == ')' || i - x == 2) {
    			ok = 1;
			}
		}
	}
	if (ok) cout << "YES";
	else cout << "NO";
    return 0;
}

