#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho xâu nhị phân S, hãy in ra xâu nhị phân kế tiếp của S. Trong trường hợp S là xâu nhị phân cuối cùng thì in ra xâu nhị 
	  phân đầu tiên.

	- Input Format: 1 dòng duy nhất chưa xâu nhị phân S.

	- Output Format: In ra xâu nhị phân kế tiếp.

	- Constraints: 1<=len(S)<=1000;

	- IP1: 1110010

	- OP1: 1110011
	
	- IP2: 11111

	- OP2: 00000
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    int i = s.size() - 1;
    while(i >= 0 && s[i] == '1') {
    	s[i] = '0';
    	i--;
	}
	if (i != -1) {
		s[i] = '1';
	}
	cout << s;
    return 0;
}