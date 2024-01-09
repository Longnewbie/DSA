#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho xâu kí tự S chỉ bao gồm các kí tự in thường, hãy kiểm tra xem có thể sắp đặt lại các kí tự trong xâu sao 
	  cho không có 2 kí tự kề nhau nào giống nhau hay không?

	- Input Format: Dòng duy nhất chứa xâu S.

	- Output Format: Nếu có thể sắp đặt lại xâu kí tự in ra YES, ngược lại in ra NO.

	- Constraints: 1<=len(S)<=10000;

	- IP1: aqeaaqwq

	- OP1: YES
	
	- IP2: aabb

	- OP2: YES
	
	- IP3: aabbb

	- OP3: YES
	
	- IP4: ababaa

	- OP4: NO
*/
int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    int d[256] = {0}, res = 0;
    for (char x : s) {
    	d[(int)x]++;
    	res = max(res, d[(int)x]);
	}
	if (res <= (s.size() + 1)/2) cout << "YES";
	else cout << "NO";
    return 0;
}
