#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho một tập gồm N phần tử được đánh số từ 1 đến N. Nhiệm vụ của bạn là liệt kê tất cả các tập con khác rỗng của N theo  
	  thứ tự từ điển tăng dần.

	- Input Format: Dòng duy nhất chứa số nguyên dương N.

	- Output Format: In ra các tập con của N theo thứ tự từ điển tăng dần.

	- Constraints: 1<=N<=9;

	- IP1: 4

	- OP1: 1 
		   1 2 
		   1 2 3 
		   1 2 3 4 
		   1 2 4 
		   1 3 
		   1 3 4 
		   1 4 
		   2 
		   2 3 
		   2 3 4 
		   2 4 
		   3 
		   3 4 
		   4 
*/

int n, ok, a[101];

void ktao() {
	for (int i = 1; i <= n; i++) a[i] = 0;
}

void sinh() {
	int i = n; 
	while(i >= 1 && a[i] == 1) {
		a[i] = 0;
		--i;
	}
	if (i == 0) ok = 1;
	a[i] = 1;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //Cách 1: int
    cin >> n;
    vector<vector<int>> v;
    ktao();
    sinh();
    while(!ok) {
    	vector<int> tmp;
    	for (int i = 1; i <= n; i++) {
    		if (a[i]) tmp.push_back(i);
		}
		v.push_back(tmp);
		sinh();
	}
	sort(v.begin(), v.end());
	for (auto x : v) {
		for (auto it : x) {
			cout << it << " ";
		}
		cout << "\n";
	}
	
	//Cách 2: string
/*  
	cin >> n;
    vector<string> v;
    ktao();
    sinh();
    while(!ok) {
        string res = "";
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) res += to_string(i) + " ";
        }
        v.push_back(res);
        sinh();
    }
    sort(v.begin(), v.end());
    for (auto x : v) {
        cout << x << "\n";
    }
*/
    return 0;
}
