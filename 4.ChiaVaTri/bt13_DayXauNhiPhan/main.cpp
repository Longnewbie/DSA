#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Xâu nhị phân S được định nghĩa như sau :
	
	  S[1] = “0”.

	  S[2] = “1”.
	  
	  S[i] = S[i-2] + S[i-1] với i>2.
	
	  Với phép cộng (+) là phép nối hai xâu với nhau. Hãy xác định ký tự thứ K trong xâu S[N] là ký tự ‘0’ hay ký tự ‘1’.

	- Input Format: 1 Dòng duy nhất chứa 2 số nguyên N và K.

	- Output Format: In ra kí tự là đáp án của bài toán.

	- Constraints: 2<=N<=92; 1<=K<=7e18 và đảm bảo là một vị trí hợp lệ trong xâu S.

	- IP1: 7 7

	- OP1: 0
	
	
	- IP1: 8 6

	- OP1: 1
*/

ll F[94];

void fibo() {
	F[0] = 0;
	F[1] = 1;
	for (int i = 2; i <= 93; i++) F[i] = F[i - 1] + F[i - 2];
}

ll find(int n, ll k) {
	if (n == 1) return 0;
	if (n == 2) return 1;
	if (k <= F[n - 2]) {
		return find(n - 2, k);
	} else return find(n - 1, k - F[n - 2]);
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fibo();
    int n;
    ll k;
    cin >> n >> k;
    cout << find(n, k);
    return 0;
}