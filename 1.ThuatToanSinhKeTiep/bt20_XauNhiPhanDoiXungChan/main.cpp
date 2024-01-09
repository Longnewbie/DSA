#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Nhiệm vụ của bạn là hãy liệt kê các xâu nhị phân thuận nghịch có độ dài chẵn theo thứ tự từ điển với chiều dài không 
	  quá n kí tự.

	- Input Format: Dòng duy nhất chứa số nguyên N.

	- Output Format: In ra các xâu nhị phân đối xứng có độ dài chẵn theo thứ tự từ điển.

	- Constraints: 2<=N<=30

	- IP1: 4

	- OP1: 00
		   0000
		   0110
		   1001
		   11
		   1111
*/

int n, ok, a[1001];

void ktao() {
	for (int i = 1; i <= n; i++) a[i] = 0;
}

void sinh() {
	int i = n;
	while(i >= 1 && a[i] == 1) {
		a[i--] = 0;
	}
	if (i == 0) ok = 1;
	a[i] = 1;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);    
    cin.tie(0);
    cout.tie(0);
    int m; cin >> m;
    vector<string> v;
    for (n = 1; n <= m/2; n++) {
        ktao();
        ok = 0;
        while(!ok) {
            string s = "";
            for (int i = 1; i <= n; i++) s += to_string(a[i]);
            string tmp = s;
            reverse(tmp.begin(), tmp.end());
            v.push_back(s + tmp);
            sinh();
        }
    }
    sort(v.begin(), v.end());
    for (string x : v) cout << x << "\n";
    return 0;
}