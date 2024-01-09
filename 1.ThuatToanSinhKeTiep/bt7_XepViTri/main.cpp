#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho N bạn học sinh, giáo viên muốn xếp các bạn học sinh này vào một hàng ngang gồm N chiếc ghế. Nhiệm vụ của bạn là
	  liệt kê các cách sắp xếp N bạn học sinh này theo thứ tự tên người tăng dần về thứ tự từ điển.

	- Input Format: Dòng đầu tiên là số N. Dòng thứ 2 là N tên học sinh, mỗi tên chỉ bao gồm một từ.

	- Output Format: In ra các cách xếp trên từng dòng.

	- Constraints: 1<=N<=10;

	- IP1: 3
		   Lan Ngoc Nhung 

	- OP1: Lan Ngoc Nhung 
		   Lan Nhung Ngoc 
		   Ngoc Lan Nhung 
		   Ngoc Nhung Lan 
		   Nhung Lan Ngoc 
		   Nhung Ngoc Lan 
*/

//Làm thủ công:

int n, ok, a[101];

void ktao() {
	for (int i = 1; i <= n; i++) a[i] = i;
}

void sinh() {
	int i = n - 1;
	while(i >= 1 && a[i] > a[i + 1]) --i;
	if (i == 0) ok = 1;
	else {
		int j = n;
		while(a[i] > a[j]) --j;
		swap(a[i], a[j]);
		reverse(a + i + 1, a + n + 1);
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    string s[n + 2];
    for (int i = 1; i <= n; i++) cin >> s[i];
    sort(s + 1, s + n + 1);
    ktao(); 
    while(!ok) {
    	for (int i = 1; i <= n; i++) cout << s[a[i]] << " ";
    	cout << "\n";
    	sinh();
	}
    return 0;
}
