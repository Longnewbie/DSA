#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho tập gồm N phần tử là các số từ 1 tới N và số K. Bạn hãy đưa ra tập con kế tiếp của tập con hiện tại. Nếu tập con hiện
	  tại là tập con cuối cùng thì bạn hãy đưa ra tập con kế tiếp là tập con đầu tiên.

	- Input Format: Dòng đầu tiên là 2 số nguyên dương N và K. Dòng thứ 2 là K số nguyên của tập con hiện tại.

	- Output Format: In ra tập con kế tiếp trên 1 dòng.

	- Constraints: 1<=K<=N<=1000;

	- IP1: 6 5
		   2 3 4 5 6 

	- OP1: 1 2 3 4 5 
	
	- IP2: 11 7
		   1 3 5 6 7 8 9 

	- OP2: 1 3 5 6 7 8 10 
*/

int n, k, a[1001], ok;

void ktao() {
	for (int i = 1; i <= k; i++) cin >> a[i];
}

void sinh() {
	int i = k;
	while(i >= 1 && a[i] == n - k + i) --i;
	if (i == 0) {
		for (int i = 1; i <= k; i++) cout << i << " ";
	} else {
		a[i]++;
		for (int j = i + 1; j <= k; j++) {
			a[j] = a[j - 1] + 1;
		}
		for (int j = 1; j <= k; j++) cout << a[j] << " ";
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> n >> k;
	ktao();
	sinh();
    return 0;
}