#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho mảng A[], B[] đều có N phần tử. Nhiệm vụ của bạn là tìm giá trị lớn nhất của biểu thức
	  P = A[0]*B[0] + A[1]*B[1] + ..+A[N-1]*B[N-1] bằng cách tráo đổi vị trí các phần tử của cả mảng A[] và B[].

	- Input Format: Dòng 1 chứa số nguyên dương N; Dòng 2 chứa N số nguyên của mảng A[]; Dòng 3 chứa N số nguyên của mảng B[];

	- Output Format: In ra đáp án của bài toán.

	- Constraints: 1<=N<=10^5; 0<=A[i], B[i]<=10^6;

	- IP1: 7
		   9 4 5 3 9 4 10 
		   9 5 3 1 10 1 5 
		   
	- OP1: 270
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    ll s = 0;
    for (int i = 0; i < n; i++) {
    	s += a[i] * b[i];
	}
	cout << s;
    return 0;
}
