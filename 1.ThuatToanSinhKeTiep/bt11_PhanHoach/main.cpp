#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho số nguyên dương N, bạn hãy in ra các cách biểu diễn N dưới dạng tổng của các số tự nhiên không vượt quá N.

	- Input Format: Số nguyên dương N.

	- Output Format: Dòng đầu tiên in ra số lượng cách biểu diễn. Các dòng tiếp theo in ra cách biểu diễn được liệt kê theo 
	  thứ tự từ từ điển giảm dần.

	- Constraints: 1<=N<=20;

	- IP1: 5

	- OP1: 7
		   5
		   4+1
		   3+2
		   3+1+1
		   2+2+1
		   2+1+1+1
		   1+1+1+1+1
*/
int n, cnt, ok, a[1001];

void ktao() {
	cnt = 1;
	a[cnt] = n;
}

void sinh() {
	int i = cnt;
	while(i >= 1 && a[i] == 1) --i;
	if (i == 0) ok = 1;
	else {
		a[i]--;
		int d = cnt - i + 1;
		for (int j = i + 1; j <= i + d/a[i]; j++) a[j] = a[i];
		cnt = i + d/a[i];
		if (d % a[i] != 0) {
			cnt++;
			a[cnt] = d % a[i];
		}
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
	ktao();
    vector<vector<int>> v;
    while(!ok) {
    	vector<int> tmp(a + 1, a + cnt + 1);
    	v.push_back(tmp);
    	sinh();
	}
	cout << v.size() << "\n";
	for (auto x : v) {
		for (int i = 0; i < x.size(); i++) {
			cout << x[i];
			if (i < x.size() - 1) cout << "+"; 
		}
		cout << "\n";
	}
    return 0;
}
