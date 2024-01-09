#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho ma trận A[M][N]. Nhiệm vụ của bạn là đếm tất cả các đường đi từ phần tử A[0][0] đến phần tử A[M-1][N-1]. Bạn chỉ được
	  phép dịch chuyển xuống dưới hoặc sang phải phần tử liền kề với vị trí hiện tại.
	  
	- Input Format: Dòng 1 là hai số M, N tương ứng với số hàng và số cột của ma trận; Dng tiếp theo đưa vào các phần tử của 
	  ma trận A[][]; các số được viết cách nhau một vài khoảng trống.
	
	- Output Format: Đưa ra số cách di chuyển
	
	- Constraints: 1≤M, N, <=10; A[i][j]≤100;
	
	- Sample Input 0: 3 5
					  4 6 8 3 1 
					  9 8 8 9 1 
					  10 6 3 4 5 
	
	- Sample Output 0: 15
*/

int n, m, cnt, a[101][101];

void Try(int i, int j) {
	if (i == n && j == m)  cnt++;
	if (i + 1 <= n && a[i + 1][j]) Try(i + 1, j);
	if (j + 1 <= m && a[i][j + 1]) Try(i, j + 1);
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);    
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m; 
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		cin >> a[i][j];
		}
	}
	Try(1, 1);
	cout << cnt;
    return 0; 
}