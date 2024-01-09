#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho N sợi dây, biết chi phí nối 2 sợ dây là tổng độ dài của 2 sợi dây đó. Nhiệm vụ của bạn là nối N sợi dây này thành 1 
	  sao cho chi phí nối dây là nhỏ nhất.

	- Input Format: Dòng 1 chứa số nguyên N; Dòng 2 chứa N số nguyên là độ dài các sợ dây

	- Output Format: In ra chi phí nối dây tối thiểu.

	- Constraints: 1<=N<=10^5; Các sợi dây có độ dài không quá 10^5;
	
	- IP1: 7
		   7 7 6 10 4 8 3 
		   
	- OP1: 124
	
	- IP2: 4
		   4 3 2 6
		   
	- OP2: 29
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for (int i = 0; i < n; i++) {
    	int x; cin >> x;
    	q.push(x);
	}
	ll res = 0;
	while(q.size() > 1) {
		ll x = q.top(); q.pop();
		ll y = q.top(); q.pop();
		res += x + y;
		q.push(x + y);
	}
	cout << res;
    return 0;
}