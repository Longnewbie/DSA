#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Hãy xem xét một hệ thống tiền tệ của ngân hàng XYZ bao gồm n đồng xu. Mỗi đồng xu có một giá trị nguyên dương. Nhiệm vụ
	  của bạn là tính số cách riêng biệt mà bạn có thể tạo ra số tiền x bằng cách sử dụng số xu có sẵn. Ví dụ: nếu số xu 
	  là {2,3,5} và tổng mong muốn là 9, có 8 cách: 2 + 2 + 5; 2 + 5 + 2; 5 + 2 + 2; 3 + 3 + 3; 2 + 2 + 2 + 3; 2 + 2 + 3 + 2;
	  2 + 3 + 2 + 2; 3 + 2 + 2 + 2;

	- Input Format: Dòng nhập đầu tiên có hai số nguyên n và x: số xu và số tiền mong muốn. Dòng thứ hai có n số nguyên phân 
	  biệt c1, c2,…, cn: giá trị của mỗi đồng xu.

	- Output Format: In ra kết quả lấy dư với 10^9 + 7.

	- Constraints: 1≤n≤100; 1≤x≤10^6; 1≤ci≤10^6;

	- IP1: 3 9
		   2 3 5

	- OP1: 8
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, s; cin >> n >> s;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    int dp[s + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= s; i++) {
    	for (int j = 1; j <= n; j++) {
    		if (i >= a[j]) {
    			dp[i] += dp[i - a[j]]; 
    			dp[i] %= mod;
			}
		}
	}
	cout << dp[s];
    return 0;
}