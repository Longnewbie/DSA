#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho số tự nhiên N, bạn được cung cấp một hoán vị của N phần tử từ 1 tới N. Nhiệm vụ của bạn là sinh ra hoán vị kế tiếp của
	  hoán vị được cho, nếu hoán vị được cho là hoán vị cuối cùng thì yêu cầu in ra hoán vị đầu tiên.

	- Input Format: Dòng đầu tiên là số tự nhiên N. Dòng thứ 2 là các số tự nhiên trong hoán vị hiện tại.

	- Output Format: In ra hoán vị kế tiếp trên một dòng.

	- Constraints: 1<=N<=1000;

	- IP1: 6
		   3 1 5 6 2 4 

	- OP1: 3 1 5 6 4 2 
*/

//Sử dụng hàm có sẵn: 

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    next_permutation(a, a + n);
    for (int &x : a) cout << x << " ";
    return 0;
}