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
	- Cho mảng A[] có n phần tử, nhiệm vụ của bạn là đối với mỗi phần tử A[i] trong mảng phải tìm ra phần tử nhỏ hơn đầu tiên 
	  nằm bên phải của phần tử lớn hớn hơn đầu tiên nằm bên phải của A[i]. Đối với những phần tử không có phần tử lớn hơn bên 
	  phải thì in ra -1 . Ví dụ A[] = {1, 5, 3, 3, 4, 1}, 1->5->3, 5->-1->-1, 3->4->-1, 3->4->-1, 4->-1->-1, 1->-1->-1.

	- Input Format: Dòng đầu tiên chứa N : Số lượng phần tử trong mảng. Dòng thứ 2 chứa N số nguyên, mỗi số cách nhau một 
	  khoảng trắng.

	- Output Format: In ra đáp án của bài toán trên 1 dòng.

	- Constraints: 1<=N<=10^6; 1<=A[i]<=10^6;

	- IP1:  5
			11 18 12 18 10 

	- OP1:  12 -1 10 -1 -1 
*/

void GR(int a[], int n, int d[]) {
	stack<int> st;
	for (int i = 0; i < n; i++) {
		while(!st.empty() && a[i] > a[st.top()]) {
			d[st.top()] = i; st.pop();
		}
		st.push(i);
	}
	while(!st.empty()) {
		d[st.top()] = -1;
		st.pop();
	}
}

void SR(int a[], int n, int d[]) {
	stack<int> st;
	for (int i = 0; i < n; i++) {
		while(!st.empty() && a[i] < a[st.top()]) {
			d[st.top()] = a[i]; st.pop();
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
    int G[n] = {0}, S[n] = {0};
    GR(a, n, G); SR(a, n, S);
    for (int i = 0; i < n; i++) {
    	if (G[i] != -1) {
    		cout << S[G[i]] << " ";
		} else cout << -1 << " ";
	}
    return 0;
}