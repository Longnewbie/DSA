#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho số nguyên dương N, gọi M là số đảo của N. Hãy tính lũy thừa với cơ số N và số mũ M và chia dư kết quả cho 10^9 + 7.

	- Input Format: Dòng duy nhất chứa số nguyên dương N.

	- Output Format: In ra đáp án của bài toán.

	- Constraints: 1<=N<=10^9.

	- IP1: 8

	- OP1: 16777216
	
	- IP1: 999995841

	- OP1: 987348397
*/

ll binpow(ll a, ll b) {
	if (b == 0) return 1;
	ll res = binpow(a, b/2);
	if (b % 2 == 0) return ((res % mod) * (res % mod)) % mod;
	else return (((res % mod) * (res % mod)) % mod) * (a % mod) % mod;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a; cin >> a;
    string b = a;
    reverse(b.begin(), b.end());
    cout << binpow(stoll(a), stoll(b));
    return 0;
}