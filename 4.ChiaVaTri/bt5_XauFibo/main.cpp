#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Xâu S chỉ bao gồm các kí tự A và B được gọi là xâu Fibonacci nếu S(1) = 'A', S(2) = 'B', S(n) = S(n - 2) + S(n - 1),
	  trong đó phép + là phép nối 2 xâu. Bài toán đặt ra là tìm kí tự thứ K trong xâu fibonacci thứ N.

	- Input Format: Dòng duy nhất chứa 2 số N và K.

	- Output Format: In ra kí tự tìm được.

	- Constraints: 1<=N<=92; 1<=K<=7e18 và đảm bảo là vị trí hợp lệ trong xâu fibonacci thứ N.

	- IP1: 5 3

	- OP1: B
	
	A B AB BAB ABBAB BABABBAB
	1 1 2  3   5     8
*/

ll F[94];

void Fibo() {
	F[1] = F[2] = 1;
	for (int i = 3; i <= 93; i++) F[i] = F[i - 1] + F[i - 2];
}

char Find(int n, ll k) {
	if (n == 1) return 'A';
	if (n == 2) return 'B';
	if (k <= F[n - 2]) {
		return Find(n - 2, k); //Tim kiem ben trai
	} else return Find(n - 1, k - F[n - 2]); //Tim kiem ben phai 
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Fibo();
    int n;
	ll k;
    cin >> n >> k;
    cout << Find(n, k);
    return 0;
}