#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Tại ngân hàng có các mệnh giá bằng 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000. Tổng số tiền cần đổi có giá trị bằng N. 
	  Hãy xác định xem có ít nhất bao nhiêu tờ tiền sau khi đổi tiền ?

	- Input Format: Dòng duy nhất chứa số nguyên N.

	- Output Format: In ra số tờ tiền tối thiểu.

	- Constraints: 1<=N<=10^9

	- IP1: 138

	- OP1: 6
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int n; cin >> n;
    int cnt = 0, i = 0;
    while(n) {
    	cnt += n / a[i];
    	n %= a[i];
    	i++;
	}
	cout << cnt;
    return 0;
}
