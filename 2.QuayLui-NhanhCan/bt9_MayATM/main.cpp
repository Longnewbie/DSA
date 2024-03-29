#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Một máy ATM hiện có n (n ≤ 30) tờ tiền có giá trị t[1], t[2], …, t[n]. Hãy tìm cách trả ít tờ nhất với số tiền đúng
	  bằng S (các tờ tiền có giá trị bất kỳ và có thể bằng nhau, mỗi tờ tiền chỉ được dùng một lần).

	- Input Format: Dòng 1 gồm 2 số nguyên n và S (S ≤ 10^9). Dòng thứ hai chứa n số nguyên t[1], t[2], …, t[n] (t[i] ≤ 10^9).

	- Output Format: In ra số tờ tiền ít nhất phải trả, nếu không thể tìm được ra kết quả thì in -1.

	- Constraints: 1<=N<=30; 1<=S<=10^9; 1<=t[i]<=10^9;

	- IP1: 6 30
		   10 4 10 5 8 8 

	- OP1: 4
*/

int n, s, min_val = 100, a[101];

void Try(int i, int bd, int sum) {
	if (i >= min_val) return;
	for (int j = bd; j <= n; j++) {
		if (sum + a[j] <= s) {
			if (sum + a[j] == s) {
				min_val = min(min_val, i);
			} else Try(i + 1, j + 1, sum + a[j]);
		} 
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    for (int i = 1; i <= n; i++) cin >> a[i];
    Try(1, 1, 0);
    if (min_val != 100) cout << min_val;
    else cout << "-1";
    return 0;
}
