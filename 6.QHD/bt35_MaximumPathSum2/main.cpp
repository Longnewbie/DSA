#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho mảng 2 chiều A gồm N hàng và N cột, hãy tìm 1 đường đi từ dòng 1 tới dòng N sao cho các phần tử trên đường đi đó là 
	  lớn nhất có thể. Biết rằng ở mỗi bước đi từ ô hiện tại chỉ có thể đi xuống ô dưới bên trái, ô dưới bên phải hoặc ô dưới 
	  của ô hiện tại. Hãy tìm 1 đường đi có tổng các số trên đường đi là lớn nhất.

	- Input Format: +) Dòng 1 là N.
					+) N dòng tiếp theo mỗi dòng gồm N số.

	- Output Format: In ra kết quả của bài toán.

	- Constraints: 

	- IP1:  5
			5 1 8 6 7 
			6 0 0 3 7 
			3 4 1 5 3 
			9 8 9 2 2 
			5 3 4 5 3 

	- OP1: 33
	
	- Explanation 0: Đường đi có tổng lớn nhất : 7 + 7 + 5 + 9 + 5 = 33.
*/

ll a[101][101];

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    		cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    		a[i][j] = max({a[i - 1][j - 1], a[i - 1][j], a[i - 1][j + 1]}) + a[i][j];
		}
	}
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		res = max(res, a[n][i]);
	}
	cout << res;
    return 0;
}