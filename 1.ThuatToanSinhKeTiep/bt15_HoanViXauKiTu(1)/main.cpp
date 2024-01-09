#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho một xâu kí tự S chỉ bao gồm các kí tự , hãy in ra các hoán vị của các kí tự khác nhau trong S theo thứ tự từ điển 
	  tăng dần.

	- Input Format: 1 dòng chứa xâu S.

	- Output Format: In ra các hoán vị của xâu S

	- Constraints: 1<=len(S)<=10;

	- IP1: lqk

	- OP1: klq
		   kql
		   lkq
		   lqk
		   qkl
		   qlk
*/

//Sử dụng hàm có sẵn:

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    set<char> se;
    for (char x : s) se.insert(x);
    s = "";
    for (char x : se) s += x;
    do {
    	for (int i = 0; i < s.size(); i++) cout << s[i];
    	cout << "\n";
	} while(next_permutation(s.begin(), s.end()));
    return 0;
}