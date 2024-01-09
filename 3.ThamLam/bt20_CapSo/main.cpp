#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Ta gọi một cặp số (x, y) là tương tự nhau nếu chúng có cùng tính chất chẵn lẻ hoặc có abs(x - y) = 1. Bạn được cung cấp
	  một mảng A[] có N phần tử, hãy kiểm tra xem có thể chia N phần tử này thành các cặp, sao cho mỗi cặp số đều tương tự nhau.

	- Input Format: Dòng đầu tiên chứa số nguyên dương N là số chẵn. Dòng 2 chứa N số nguyên của mảng A[]

	- Output Format: In ra YES nếu có thể chia thành các cặp tương tự, ngược lại in ra NO.

	- Constraints: 1<=N<=100; 1<=A[i]<=1000;

	- IP1: 6
		   78 17 17 42 11 43 

	- OP1: YES
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<int> chan, le;
    for (int i = 0; i < n; i++) {
    	int x; cin >> x;
    	if (x % 2 == 0) chan.pb(x);
    	else le.pb(x);
	}
	if (chan.size() % 2 == 0) cout << "YES";
	else {
		for (int c : chan) {
			for (int l : le) {
				if (abs(c - l) == 1) {
					cout << "YES";
					return 0;
				}
			}
		}
		cout << "NO";
	}
    return 0;
}
