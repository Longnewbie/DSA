#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho hai số nguyên dương S và D, trong đó S là tổng các chữ số và D là số các chữ số của một số. Nhiệm vụ của bạn là
	  tìm số nhỏ nhất thỏa mãn S và D ?

	- Input Format: 1 dòng gồm 2 số S, D

	- Output Format: In ra số nhỏ nhất có D chữ số và có tổng bằng S, nếu không tìm được đáp án thì in ra -1.

	- Constraints: 1<=S,D<=1000;

	- IP1: 12 8

	- OP1: 10000029
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int s, d; cin >> s >> d;
    string res = string(d, '0');
    if (d * 9 < s || s == 0 && d > 1) {
    	cout << -1;
    	return 0;
	}
	for (int i = d - 1; i >= 0; i--) {
		if (s > 9) {
			res[i] = '9';
			s -= 9;
		} else {
			if (i == 0) res[0] = char(s + '0');
			else {
				res[0] = '1';
				res[i] = char(s - 1 + '0');
			}
			break;
		}
	}
	cout << res;
    return 0;
}
