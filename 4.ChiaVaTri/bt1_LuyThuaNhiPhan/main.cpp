#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Nhiệm vụ của bạn là tính N^P, kết quả được chia dư với 10^9 + 7.

	- Input Format: Dòng duy nhất chứa 2 số N và K.

	- Output Format: Kết quả của bài toán.

	- Constraints: 1<=N<=10^6; 1<=K<=10^9;

	- IP1: 9 9

	- OP1: 387420489
	
	- IP2: 994402 999992619

	- OP2: 925329307
*/

ll binpow(int a, int b) {
	if (b == 0) return 1;
	ll res = binpow(a, b/2);
	if (b % 2 == 0) return ((res % mod) * (res % mod)) % mod;
	else return (((res % mod) * (res % mod)) % mod) * (a % mod) % mod;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b; cin >> a >> b;
    cout << binpow(a, b);
    return 0;
}