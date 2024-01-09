#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho dãy A[] gồm N phần tử đã được sắp xếp và số nguyên dương K. Hãy kiểm tra xem K có xuất hiện trong mảng 
	  hay không, nếu có in ra YES, ngược lại in ra NO.

	- Input Format: Dòng 1 chứa 2 số N và K; Dòng 2 chứa N số nguyên của mảng A[].

	- Output Format: In ra đáp án của bài toán.

	- Constraints: 1<=N<=10^5; 1<=A[i], K<=10^6;

	- IP1: 7 2
		   1 8 9 10 10 12 17 

	- OP1: NO
	
	- IP2: 6 4
		   4 8 9 16 19 20 

	- OP2: YES
*/

int find(int a[], int l, int r, int x) {
	if (l > r) return 0;
	int m = (r + l)/2;
	if (a[m] == x) return 1;
	else if (a[m] > x) return find(a, l, m - 1, x);
	else return find(a, m + 1, r, x);
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x; cin >> n >> x;
    int a[n];
    for (int &x : a) cin >> x;
    if (find(a, 0, n - 1, x)) cout << "YES";
    else cout << "NO";
    return 0;
}