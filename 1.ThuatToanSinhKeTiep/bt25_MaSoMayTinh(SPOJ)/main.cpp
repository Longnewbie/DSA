#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Số lượng máy tính ở các phòng thực hành tăng lên nhanh chóng. Để gán mã cho các máy tính của trường đó người ta sử dụng
	  mã gồm 2*N ký tự, trong đó: N ký tự đầu tiên là hoán vị của N chữ cái in hoa đầu tiên, tính từ A. N ký tự tiếp theo là
	  các ký tự số bất kỳ từ 1 đến N (có thể trùng nhau). Người ta ước tính chỉ cần N = 5 là đủ để gán mã cho toàn bộ máy tính
	  kể cả khi mở rộng quy mô các phòng thực hành. Hãy viết chương trình liệt kê các mã tạo được với giá trị N cho trước.

	- Input Format: Số nguyên dương N

	- Output Format: Ghi ra lần lượt các mã khác nhau tạo được theo thứ tự từ điển, mỗi mã ghi trên một dòng.

	- Constraints: 1 < N < 6

	- IP1: 2

	- OP1: AB11
	  	   AB12
		   AB21
		   AB22
		   BA11
		   BA12
		   BA21
		   BA22
*/

string s;
vector<string> v1, v2;
int n, ok;

void sinh() {
	int i = s.size() - 1;
	while(i >= 0 && s[i] == ('0' + n)) {
		s[i--] = '1';
	}
	if (i == -1) ok = 1;
	else s[i]++;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) s += (char)(i + 65);
    do {
    	v1.push_back(s);
	} while(next_permutation(s.begin(), s.end()));
	s = "";
	s = string(n, '1');
	while(!ok) {
		v2.push_back(s);
		sinh();
	}
	for (auto x1 : v1) {
		for (auto x2: v2) {
			cout << x1 << x2 << "\n";
		}
	}
    return 0;
}
