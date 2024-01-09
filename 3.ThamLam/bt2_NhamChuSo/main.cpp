#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Trong một buổi học toán, giáo viên viết 2 số nguyên, A và B, và yêu cầu Tèo thực hiện phép cộng. Tèo không bao giờ tính
	  toán sai, nhưng thỉnh thoảng cậu ta chép các con số một cách không chính xác. Lỗi duy nhất của là ghi nhầm '5' thành '6' 
	  hoặc ngược lại. Cho hai số, A và B, tính tổng nhỏ nhất và lớn nhất mà Tèo có thể nhận được.

	- Input Format: 1 dòng duy nhất chứa 2 số A và B.

	- Output Format: In ra tổng lớn nhất và nhỏ nhất trên 1 dòng.

	- Constraints: 1<=A<=B<=10^16.

	- IP1: 891 746

	- OP1: 1637 1636
	
	- IP2: 1562 1865

	- OP2: 3528 3407
*/

ll solve(string s, char x, char y) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == x) s[i] = y;
	}
	return stoll(s);
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, t; cin >> s >> t;
    cout << solve(s, '5', '6') + solve(t, '5', '6') << " ";
    cout << solve(s, '6', '5') + solve(t, '6', '5') << " ";
    return 0;
}
