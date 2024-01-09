#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho một mê cung được mô tả dưới dạng một ma trận nhị phân có N hàng và N cột. Một con chuột bắt đầu tử ô (1, 1) và muốn di
	  chuyển tới ô (N, N). Con chuột chỉ được di chuyển xuống dưới hoặc sang phải và chỉ được di chuyển tới ô nào đó nếu ô đó có
	  giá trị là 1. Bạn hãy in ra các cách đi hợp lệ của con chuột, trong đó nếu con chuột đi sang phải thì nước đi được mô tả
	  là chữ R, và nếu con chuột đi xuống dưới thì nước đi được mô tả là chữ D. Nếu con chuột không thể đi xuống ô (N, N) 
	  thì in ra -1. Chú ý trên mỗi đường đi con chuột chỉ có thể đi qua 1 ô nào đó đúng 1 lần.
	  
	- Input Format: Dòng thứ nhất đưa vào N; N dòng tiếp theo mỗi dòng gồm N số.
	
	- Output Format: Đưa ra các đường đi hợp lệ theo thứ tự từ điển tăng dần trên từng dòng.
	
	- Constraints: 1<=N<=12; Dữ liệu đảm bảo ô (1, 1) là số 1.
	
	- Sample Input 0: 4
					  1 1 0 1 
					  1 1 1 1 
					  1 0 1 1 
					  1 1 1 1 
	
	- Sample Output 0: DDDRRR
					   DRRDDR
					   DRRDRD
					   DRRRDD
					   RDRDDR
					   RDRDRD
					   RDRRDD
*/

int n, a[20][20], ok;

void Try(int i, int j, string s) {
	if (i == n && j == n) {
		cout << s << "\n";
		ok = 1;
	}
	if (i + 1 <= n && a[i + 1][j]) Try(i + 1, j, s  + "D");
	if (j + 1 <= n && a[i][j + 1]) Try(i, j + 1, s + "R");
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);    
    cin.tie(0);
    cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	Try(1, 1, "");
	if (!ok) cout << -1;
    return 0; 
}