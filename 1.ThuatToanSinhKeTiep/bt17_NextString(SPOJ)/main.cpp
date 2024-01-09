#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Hãy viết chương trình nhận vào một chuỗi S(có thể khá dài) các ký tự số và đưa ra màn hình hoán vị kế tiếp của các ký
	  tự số đó (với ý nghĩa là hoán vị có giá trị lớn hơn tiếp theo nếu ta coi chuỗi đó là một giá trị số nguyên). Chú ý: Các
	  ký tự số trong dãy có thể trùng nhau. Ví dụ:123 -> 132, 279134399742 -> 279134423799 Cũng có trường hợp sẽ không thể có
	  hoán vị kế tiếp. Ví dụ như khi đầu vào là chuỗi 987.

	- Input Format: Dòng duy nhất chứa xâu S.

	- Output Format: In ra xâu hoán vị kế tiếp của S, hoặc in ra "NOT EXIST" nếu S là xâu hoán vị cuối cùng.

	- Constraints: 1<=len(S)<=10000;

	- IP1: 99877541

	- OP1: NOT EXIST
	
	
	
	- IP2: 76090400736422

	- OP2: 76090400742236
*/

int n, ok;
string s;

void sinh() {
	int i = n - 1;
	while(i >= 0 && s[i] >= s[i + 1]) --i;
	if (i == -1) ok = 1;
	else {
		int j = n;
		while(s[i] >= s[j]) --j;
		swap(s[i], s[j]);
		reverse(s.begin() + i + 1, s.end());
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    n = s.size() - 1;
    sinh();
    if (!ok) {
    	cout << s;
	} else cout << "NOT EXIST";
    return 0;
}