#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho dãy số a[] có n phần tử là các số nguyên dương khác nhau từng đôi một. Hãy liệt kê tất cả các dãy con có từ 2 phần
	  tử trở lên của dãy a[] thỏa mãn tính chất tăng dần. Dãy con tạo được bằng cách lấy ra các phần tử trong dãy a[] nhưng
	  vẫn giữ nguyên thứ tự ban đầu. Coi mỗi dãy con như một xâu ký tự với các phần tử cách nhau một khoảng trống, hãy liệt kê 
	  theo thứ tự từ điển.

	- Input Format: Dòng đầu ghi số n (không quá 20); Dòng thứ 2 ghi n số của dãy a[]. Các số khác nhau từng đôi một và có 
	  giá trị không quá 100;

	- Output Format: Đưa ra các dãy con hợp lệ theo thứ tự từ điển tăng dần.	

	- Constraints: 2<=n<=20; 1<=a[i]<=100;

	- IP1:  7
		    4 8 6 7 3 5 2 

	- OP1:  3 5 
			4 5 
			4 6 
			4 6 7 
			4 7 
			4 8 
			6 7 
	
	- IP2:  15
		    16 8 6 7 13 5 14 4 2 10 12 15 11 3 9 

	- OP2:  10 11 
			10 12 
			10 12 15 
			10 15 
			12 15 
			13 14 
			13 14 15 
			13 15 
			14 15 
			2 10 
			2 10 11 
			2 10 12 
			2 10 12 15 
			2 10 15 
			2 11 
			2 12 
			2 12 15 
			2 15 
			2 3 
			2 3 9 
			2 9 
			3 9 
			4 10 
			4 10 11 
			4 10 12 
			4 10 12 15 
			4 10 15 
			4 11 
			4 12 
			4 12 15 
			4 15 
			4 9 
			5 10 
			5 10 11 
			5 10 12 
			5 10 12 15 
			5 10 15 
			5 11 
			5 12 
			5 12 15 
			5 14 
			5 14 15 
			5 15 
			5 9 
			6 10 
			6 10 11 
			6 10 12 
			6 10 12 15 
			6 10 15 
			6 11 
			6 12 
			6 12 15 
			6 13 
			6 13 14 
			6 13 14 15 
			6 13 15 
			6 14 
			6 14 15 
			6 15 
			6 7 
			6 7 10 
			6 7 10 11 
			6 7 10 12 
			6 7 10 12 15 
			6 7 10 15 
			6 7 11 
			6 7 12 
			6 7 12 15 
			6 7 13 
			6 7 13 14 
			6 7 13 14 15 
			6 7 13 15 
			6 7 14 
			6 7 14 15 
			6 7 15 
			6 7 9 
			6 9 
			7 10 
			7 10 11 
			7 10 12 
			7 10 12 15 
			7 10 15 
			7 11 
			7 12 
			7 12 15 
			7 13 
			7 13 14 
			7 13 14 15 
			7 13 15 
			7 14 
			7 14 15 
			7 15 
			7 9 
			8 10 
			8 10 11 
			8 10 12 
			8 10 12 15 
			8 10 15 
			8 11 
			8 12 
			8 12 15 
			8 13 
			8 13 14 
			8 13 14 15 
			8 13 15 
			8 14 
			8 14 15 
			8 15 
			8 9 
*/

int n, a[101], x[101];
vector<string> v;

void Try(int i, int bd) {
	for (int j = bd; j <= n; j++) {
		if (a[j] > x[i - 1]) {
			x[i] = a[j];
			if (i >= 2) {
				string res = "";
				for (int u = 1; u <= i; u++) res += to_string(x[u]) + " ";
				v.pb(res);
			} Try(i + 1, j + 1);
		}
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    Try(1, 1);
    sort(v.begin(), v.end());
    for (string x : v) cout << x << "\n";
    return 0;
}