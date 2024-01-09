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
	- Cho xâu S chỉ bao gồm dấu đóng mở ngoặc, hãy tìm số lượng dấu ngoặc tối thiểu cần phải đổi chiều để tạo thành một xâu 
	  hợp lệ.

	- Input Format: Dòng duy nhất chứa xâu S.

	- Output Format: In ra số lượng dấu ngoặc cần phải đổi chiều.

	- Constraints: Xâu S có độ dài là số chẵn và có không quá 1000 kí tự.

	- IP1: )))())()()

	- OP1: 2
	
	- IP2: (())(())()

	- OP2: 0
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    stack<int> st;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
    	if (s[i] == '(') st.push(i);
    	else if (s[i] == ')') {
    		if (st.empty()) {
    			st.push(i);
    			cnt++;
			} else st.pop();
		}
	}
	cnt += st.size()/2;
	cout << cnt;
    return 0;
}