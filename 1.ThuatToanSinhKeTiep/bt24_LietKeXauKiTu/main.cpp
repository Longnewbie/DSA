#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho chữ cái c in hoa và số nguyên K; Hãy tìm cách liệt kê tất cả các xâu có K ký tự khác nhau được tạo ra bởi các chữ cái
	  tính từ ‘A’ đến ký tự c. Các ký tự được phép lặp lại nhưng không tính các xâu là hoán vị của xâu nào đó đã liệt kê trước
	  đó.

	- Input Format: Chữ cái c và K

	- Output Format: Ghi ra lần lượt các xâu ký tự kết quả theo thứ tự từ điển trên từng dòng.

	- Constraints: 'A' < c <='H'; 0 < K < (c – ‘A’);

	- IP1: C 2

	- OP1: AA
		   AB
		   AC
		   BA
		   BB
		   BC
		   CA
		   CB
		   CC
*/

char c; int k, ok;
string s;

void ktao() {
	cin >> c >> k;
	s = string(k, 'A');
}

void sinh() {
	int i = s.size() - 1;
	while(i >= 0 && s[i] == c) {
		s[i--] = 'A';
	}
	if (i == -1) ok = 1;
	else s[i]++;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ktao();
    while(!ok) {
    	cout << s << "\n";
    	sinh();
	}
    return 0;
}