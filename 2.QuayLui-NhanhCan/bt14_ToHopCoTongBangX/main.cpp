#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho mảng A[] gồm N số nguyên dương phân biệt và số X. Nhiệm vụ của bạn là tìm phép tổ hợp các số trong mảng A[] có tổng 
	  bằng X. Các số trong mảng A[] có thể được sử dụng nhiều lần. Mỗi tổ hợp các số của mảng A[] được in ra theo thứ tự không
	  giảm các số. Ví dụ với A[] = {2, 4, 6, 8}, X = 8 ta có các tổ hợp các số như sau:
	  {2, 2, 2, 2}, {2, 2, 4}, {2, 6}, {4, 4}, {8}.

	- Input Format: Dòng thứ nhất là hai số N và X; dòng tiếp theo đưa vào N số của mmảng A[]; các số được viết cách nhau một 
	  vài khoảng trống

	- Output Format: In ra số tổ hợp thỏa mãn sau đó in ra các tổ hợp thỏa mãn trên từng dòng. Xem output để rõ hơn cách in.
	  Trong trường hợp không có tổ hợp thỏa mãn thì in ra -1.

	- Constraints: 1<=N<=20; 1<=X,A[i]<=100;

	- IP1:  3 10
		    4 2 3 

	- OP1:  5
			{2 2 2 2 2}
			{2 2 2 4}
			{2 2 3 3}
			{2 4 4}
			{3 3 4}
*/

int n, s, a[101], x[101];
vector<vector<int>> v;

void Try(int i, int bd, int sum) {
	for (int j = bd; j <= n; j++) {
		if (sum + a[j] <= s) {
			x[i] = a[j];
			if (sum + a[j] == s) {
				vector<int> tmp(x + 1, x + i + 1);
				v.pb(tmp);
			} else Try(i + 1, j, sum + a[j]);
		}
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    Try(1, 1, 0);
    if (!v.size()) cout << -1;
    else {
    	cout << v.size() << "\n";
    	for (auto x : v) {
    		cout << "{";
    		for (int j = 0; j < x.size(); j++) {
    			cout << x[j];
    			if (j < x.size() - 1) cout << " ";
			}
			cout << "}\n";
		}
	}
    return 0;
}