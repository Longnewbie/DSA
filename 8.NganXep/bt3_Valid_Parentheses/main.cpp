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
	- Cho một xâu kí tự chỉ bao gồm các kí tự '(', ')', '{', '}', ']', "]", hãy xác định xem các dấu ngoặc trong xâu có cân bằng
	  hay không. Một vài ví dụ về xâu cân bằng : ((())), {{((()))}}[][][], (())(()())...

	- Input Format: Xâu kí tự S trên 1 dòng.

	- Output Format: In ra YES hoặc NO nếu xâu kí tự cân bằng hoặc không.

	- Constraints: 1<=len(S)<=10000.

	- IP1: ((((()))))

	- OP1: YES
*/

bool check(char x, char y) {
    return ((x == '(' && y == ')') || (x == '{' && y == '}') || (x == '[' && y == ']'));
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    stack<char> st;
    for (char x : s) {
        if (x == '(' || x == '{' || x == '[') st.push(x);
        else {
            if (st.empty()) {
                cout << "NO";
                return 0;
            } else {
                if (!check(st.top(), x)) {
                    cout << "NO";
                    return 0;
                } else {
                    st.pop();
                }
            }
        }
    }
    if (st.empty()) cout << "YES";
    else cout << "NO";
    return 0;
}

