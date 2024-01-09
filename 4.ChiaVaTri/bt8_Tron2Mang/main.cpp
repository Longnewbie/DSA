#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho hai mảng đã được sắp xếp A[], B[] gồm N, M phần tử theo thứ tự và số K. Nhiệm vụ của bạn là tìm phần tử ở vị
	  trí số K sau khi trộn hai mảng để nhận được một mảng được sắp xếp.

	- Input Format: Dòng đầu tiên chứa 3 số N, M, K; Dòng thứ 2 chứa N số nguyên của mảng A[]; Dòng thứ 3 chứa M 
	  số nguyên của mảng B[];

	- Output Format: In ra đáp án của bài toán.

	- Constraints: 1<=N,M<=10^4; 1<=K<=N+M; 1<=A[i],B[i]<=10^6.

	- IP1: 7 9 14
		   4 6 7 9 10 10 10 
		   1 1 2 5 7 8 8 9 10 

	- OP1: 10
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    int a[n], b[m];
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    vector<int> v;
    int i = 0, j = 0;
    while(i < n && j < m) {
    	if (a[i] <= b[j]) v.pb(a[i++]);
    	else v.pb(b[j++]);
	}
	while(i < n) v.pb(a[i++]);
	while(j < m) v.pb(b[j++]);
	cout << v[k - 1];
    return 0;
}