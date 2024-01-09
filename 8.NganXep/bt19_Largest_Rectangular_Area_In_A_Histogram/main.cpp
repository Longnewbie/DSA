#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
#define pii pair<int,int>
#define pip pair<int,pair<int,int>>
int mod = 1e9+7;

/*
	- Cho một biểu đồ gồm các cột với chiều cao H[i], nhiệm vụ của bạn là tìm hình chữ nhật có diện tích lớn nhất che phủ bởi
	  các cột trong biểu đồ.

	- Input Format: Dòng đầu tiên là N : số lượng cột trong biểu đồ. Dòng thứ 2 gồm N số là chiều cao các cột trong biểu đồ.

	- Output Format: In ra diện tích lớn nhất tìm được.

	- Constraints: 1<=N<=10^5; 1 <= H[i]<=10^6.

	- IP1:  7
			6 2 5 4 5 1 6

	- OP1:  12
*/

void right(int a[], int n, int d[]) {
	stack<int> st;
	for (int i = 0; i < n; i++) {
		while(!st.empty() && a[i] < a[st.top()]) {
			d[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty()) {
		d[st.top()] = n;
		st.pop();
	}
}

void left(int a[], int n, int d[]) {
	stack<int> st;
	for (int i = n - 1; i >= 0; i--) {
		while(!st.empty() && a[i] < a[st.top()]) {
			d[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty()) {
		d[st.top()] = -1;
		st.pop();
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    int R[n] = {0}, L[n] = {0};
    right(a, n, R); left(a, n, L);
    ll res = 0;
    for (int i = 0; i < n; i++) {
    	ll dt = 1ll * a[i] * (R[i] - L[i] - 1);
    	res = max(res, dt);
	}
	cout << res;
    return 0;
}