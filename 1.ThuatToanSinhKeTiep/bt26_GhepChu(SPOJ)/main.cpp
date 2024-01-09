#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Trong 8 chữ cái Tiếng Anh đầu tiên (ABCDEFGH) thì có 2 nguyên âm là ‘A’, ‘E’, còn lại là phụ âm. Người ta muốn ghép các
	  chữ cái bắt đầu từ chữ cái ‘A’ cho đến chữ cái c (‘D’ <= c <= ‘H’) sao cho mỗi chữ cái được sử dụng đúng một lần và xâu
	  kết quả không có nguyên âm nào bị kẹp giữa bởi hai phụ âm. Hãy liệt kê các xâu thỏa mãn theo thứ tự từ điển.

	- Input Format: Chỉ có một dòng ghi chữ cái c.

	- Output Format: Liệt kê các xâu thỏa mãn, mỗi xâu trên một dòng.

	- Constraints: 'D' <= c <= 'H'

	- IP1: D

	- OP1: ABCD
		   ABDC
		   ACBD
		   ACDB
		   ADBC
		   ADCB
		   BCDA
		   BDCA
		   CBDA
		   CDBA
		   DBCA
	   	   DCBA
*/

string s;

bool check1(char x) {
	return x == 'A' || x == 'E';
}

bool check2(string s) {
	for (int i = 1; i < s.size() - 1; i++) {
		if (check1(s[i]) && !check1(s[i - 1]) && !check1(s[i + 1])) return false;
	}
	return true;
}
 
int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char c; cin >> c;
    for (char i = 'A'; i <= c; i++) s += i;
    do {
    	if (check2(s)) cout << s << "\n";
	} while(next_permutation(s.begin(), s.end()));
    return 0;
}
