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
	- Cho một bảng kích thước NxM, được chia thành lưới ô vuông đơn vị N dòng M cột. Trên các ô của bảng ghi số 0 hoặc 1. 
	  Nhiệm vụ của bạn là tìm hình chữ nhật gồm các ô của bảng thoả mãn các điều kiện sau: - Hình chữ nhật đó chỉ gồm các 
	  số 1. - Cạnh hình chữ nhật song song với cạnh bảng. - Diện tích hình chữ nhật là lớn nhất.

	- Input Format: Dòng đầu tiên là N và M; N dòng tiếp theo mỗi dòng gồm M số 0 hoặc 1.

	- Output Format: In ra đáp án của bài toán

	- Constraints: 1<=N, M<=500; Các phần tử trong bảng là 0 hoặc 1.

	- IP1:  6 6
			1 0 0 1 1 0 
			0 1 0 0 0 0 
			0 0 1 0 0 1 
			0 0 1 1 0 1 
			0 1 1 0 0 1 
			0 0 1 1 0 1 

	- OP1:  4
*/

int n, m, a[501][501];
vector<int> v[501];

void right(vector<int> &a, int n, int d[]) {
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

void left(vector<int> &a, int n, int d[]) {
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

void solve() {
    for (int j = 0; j < m; j++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i][j]) cnt++;
            else cnt = 0;
            v[i].pb(cnt);
        }
    }
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);    
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    solve();
    int res = 0;
    for (int i = 0; i < n; i++) {
        int R[m] = {0}, L[m] = {0};
        right(v[i], v[i].size(), R);
        left(v[i], v[i].size(), L);
        for (int k = 0; k < v[i].size(); k++) {
            int dt = v[i][k] * (R[k] - L[k] - 1);
            res = max(res, dt);
        }
    }
    cout << res;
    return 0;
}