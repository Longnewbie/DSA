#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho ma trận kề A[][] của đồ thị có hướng G = (V, E) chỉ bao gồm các số 0 hoặc 1. Hãy chuyển đổi đồ thị này thành danh
	  sách cạnh và danh sách kề tương ứng.

	- Input Format: Dòng đầu tiên là n tương ứng với số lượng đỉnh của đồ thị. n dòng tiếp theo mỗi dòng gồm n số mô tả ma
	  trận A.

	- Output Format: Những dòng đầu tiên liệt kê danh sách cạnh theo thứ tự từ điển tăng dần. Sau đó cách ra 1 dòng và liệt
	  kê danh sách kề, trong đó các đỉnh trong danh sách kề được in ra theo thứ tự tăng dần. Xem output mẫu để rõ hơn.

	- Constraints: 1<=n<=1000.

	- IP1:  5
			0 0 0 1 0 
			1 0 1 1 1 
			1 0 0 1 1 
			1 0 0 0 0 
			0 1 0 1 0 

	- OP1:  1 4
			2 1
			2 3
			2 4
			2 5
			3 1
			3 4
			3 5
			4 1
			5 2
			5 4
			
			1 : 4 
			2 : 1 3 4 5 
			3 : 1 4 5 
			4 : 1 
			5 : 2 4
*/

vector<int> adj[1001];

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //Cach 1:
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    		int x; cin >> x;
    		if (x) {
    			cout << i << " " << j << "\n";
    			adj[i].pb(j);
			}
		}
	}
	cout << "\n";
	for (int i = 1; i <= n; i++) {
		sort(begin(adj[i]), end(adj[i]));
		cout << i << " : ";
		for (int x : adj[i]) cout << x << " ";
		cout << "\n";
	}
	
/*  Cach 2: 
	int n; cin >> n;
    vector<pair<int,int>> p;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            if (x) {
                p.push_back({i, j});
                v[i].push_back(j);
            }
        }
    }
    sort(p.begin(), p.end());
    for (auto x : p) {
        cout << x.first << " " << x.second << "\n";
    }
    cout << "\n";
    for (int i = 1; i <= n; i++) {
        cout << i << " : ";
        sort(v[i].begin(), v[i].end());
        for (auto x : v[i]) cout << x << " ";
        cout << "\n";
    }
*/	
    return 0;
}