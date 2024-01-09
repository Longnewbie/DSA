#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho đồ thị vô hướng G = được biểu diễn dưới dạng danh sách kề. Hãy chuyển đổi đồ thị dưới dạng danh sách kề này sang danh 
	  sách cạnh tương ứng.

	- Input Format: Dòng đầu tiên là số nguyên dương n, tương ứng với số đỉnh của đồ thị. N dòng tiếp theo mỗi dòng chứa nhiều 
	  số nguyên, dòng thứ i tương ứng với các đỉnh trong danh sách kề của đỉnh i.

	- Output Format: In ra các cạnh trong đồ thị trên từng dòng, các cạnh được liệt kê tăng dần. Chú ý mỗi cạnh chỉ liệt kê 
	  một lần.

	- Constraints: 1<=n<=1000;

	- IP1:  5
			4 
			3 4 5 
			2 5 
			1 2 
			2 3 

	- OP1:  1 4
			2 3
			2 4
			2 5
			3 5
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    cin.ignore();
    vector<pair<int,int>> v;
    for (int i = 1; i <= n; i++) {
    	string s, tmp; getline(cin, s);
    	stringstream ss(s);
    	while(ss >> tmp) {
    		if (i < stoi(tmp)) v.pb({i, stoi(tmp)});
		}
	}
	for (pair<int,int> x : v) cout << x.first << " " << x.second << "\n";
    return 0;
}