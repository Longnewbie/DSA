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
	- Cho một xâu kí tự S chỉ bao gồm kí tự in thường, nhiệm vụ của bạn là xóa k kí tự liền kề giống nhau khỏi xâu S. Ví dụ xâu 
	  aaabbbcccedddeeu sau khi xóa 3 kí tự liền kề giống nhau khỏi xâu S sẽ trở thành : u

	- Input Format: Dòng 1 chứa xâu kí tự S; Dòng 2 chứa số nguyên dương k.

	- Output Format: In ra xâu S sau khi xóa, in ra EMPTY nếu S trở thành xâu rỗng.

	- Constraints: 1<=len(S)<=10000; 2<=K<=len(S);

	- IP1:  aabbccedde
			2

	- OP1:  EMPTY
	
	- IP2:  aaaccddda
			3

	- OP2:  cca		
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    int k; cin >> k;
    stack<int> st;
    int d[s.length()] = {0};
    for (int i = 0; i < s.length(); i++) {
    	if (!st.empty() && s[i] == s[st.top()]) d[i] = d[st.top()] + 1;
    	else d[i] = 1;
    	st.push(i);
    	if (d[i] == k) {
    		for (int i = 0; i < k; i++) st.pop();
		}
	}
	if (st.empty()) cout << "EMPTY";
	else {
		string res = "";
		while(!st.empty()) {
			res += s[st.top()]; st.pop();
		}
		reverse(begin(res), end(res));
		cout << res;
	}
    return 0;
}

