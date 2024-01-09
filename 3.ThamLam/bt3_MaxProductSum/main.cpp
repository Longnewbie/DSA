#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho mảng A[] gồm N phần tử, nhiệm vụ của bạn là sắp đặt lại vị trí các phần tử trong mảng và tính toán giá trị lớn nhất
	  của biểu thức :

	- Input Format: Dòng 1 chứa số nguyên dương N; Dòng 2 chứa N số nguyên của mảng A[] viết cách nhau một dấu cách.

	- Output Format: In ra kết quả của bài toán chia dư với 10^9 + 7 

	- Constraints: 1<=N<=10^6; 1<=A[i]<=10^9;

	- IP1: 6
		   8 1 7 9 8 1 

	- OP1: 116
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int a[n];
    ll s = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
    	s += 1ll * a[i] * i;
    	s %= mod;
	}
	cout << s;
    return 0;
}
