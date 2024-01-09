#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho mảng số nguyên gồm N phần tử, các phần tử trong mảng không quá 100. Hãy liệt kê các hoán vị của các phần tử khác 
	  nhau trong mảng theo thứ tự ngược.

	- Input Format: Dòng đầu tiên là N; Dòng thứ 2 là các phần tử trong mảng;

	- Output Format: In ra các hoán vị ngược của các phần tử khác nhau trong mảng.

	- Constraints: 1<=N<=15;

	- IP1: 2
		   1 2

	- OP1: 2 1
		   1 2
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    set<int> se;
    vector<int> v;
    for (int i = 0; i < n; i++) {
    	int x; cin >> x;
    	if (!se.count(x)) {
    		se.insert(x);
    		v.push_back(x);
		}
	}
	sort(v.begin(), v.end(), greater<int>());
	do {
		for (int x : v) cout << x << " ";
		cout << "\n";
	} while(prev_permutation(v.begin(), v.end()));
    return 0;
}
