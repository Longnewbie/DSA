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

//Sử dụng hàm có sẵn:

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    string s[n];
    for (int i = 0; i < n; i++) cin >> s[i];
    sort(s, s + n);
    do {
    	for (int i = 0; i < n; i++) cout << s[i] << " ";
    	cout << "\n";
	} while(next_permutation(s, s + n));
    return 0;
}