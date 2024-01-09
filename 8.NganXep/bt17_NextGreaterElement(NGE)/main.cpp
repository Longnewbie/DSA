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
	- Cho mảng A[] gồm N phần tử, nhiệm vụ của bạn làm tìm phần tử đầu tiên bên phải lớn hơn của mọi phần tử A[i] trong mảng,
	  nếu phần tử nào không có phần tử bên phải lớn hơn thì in ra -1.

	- Input Format: Dòng đầu tiên chứa N : Số lượng phần tử trong mảng. Dòng thứ 2 chứa N số nguyên, mỗi số cách nhau một
	  khoảng trắng.

	- Output Format: In ra đáp án của bài toán trên 1 dòng.

	- Constraints: 1<=N<=10^6; 1<=A[i]<=10^6;

	- IP1:  8
			19 11 11 15 13 18 19 18 

	- OP1:  -1 15 15 18 18 19 -1 -1 
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int a[n], d[n] = {0};
    stack<int> st;
    for (int &x : a) cin >> x;
    for (int i = 0; i < n; i++) {
    	while(!st.empty() && a[i] > a[st.top()]) {
    		d[st.top()] = a[i];
    		st.pop();
		}
		st.push(i);
	}
	while(!st.empty()) {
		d[st.top()] = -1;
		st.pop();
	}
	for (int x : d) cout << x << " ";
    return 0;
}