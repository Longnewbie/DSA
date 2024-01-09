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

//Làm thủ công: 

int n, ok, a[101];

void ktao() {
	for (int i = 1; i <= n; i++) a[i] = i;
}

void sinh() {
	int i = n - 1;
	while(i >= 1 && a[i] > a[i + 1]) --i;
	if (i == 0) ok = 1;
	else {
		int j = n;
		while(a[i] > a[j]) --j;
		swap(a[i], a[j]);
		reverse(a + i + 1, a + n + 1);
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    set<char> se;
    for (char x : s) se.insert(x);
    s = "";
    for (char x : se) s += x;
    n = s.size();
    ktao();
    while(!ok) {
    	for (int i = 1; i <= n; i++) {
    		cout << s[a[i] - 1];
		}
		cout << "\n";
		sinh();
	}
    return 0;
}
