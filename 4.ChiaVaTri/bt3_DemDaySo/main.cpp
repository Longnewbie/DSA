#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho số nguyên dương n, bạn được phép sử dụng không giới hạn các số tự nhiên từ 1 tới n. Hỏi có bao nhiêu cách chọn ra
	  1 dãy có tổng các phần tử bằng n.

	- Input Format: Dòng duy nhất chứa số nguyên dương n.

	- Output Format: In ra đáp án của bài toán sau khi chia dư với 10^9 + 7.

	- Constraints: 1<=n<=10^12.

	- IP1: 6

	- OP1: 32
*/

ll binpow(int a, ll b) {
	if (b == 0) return 1;
	ll res = binpow(a, b/2);
	if (b % 2 == 0) return ((res % mod) * (res % mod)) % mod;
	else return (((res % mod) * (res % mod)) % mod) * (a % mod) % mod;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n; cin >> n;
    cout << binpow(2, n - 1);
    return 0;
}