#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho N sợi dây, biết chi phí nối 2 sợ dây là tổng độ dài của 2 sợi dây đó. Nhiệm vụ của bạn là nối N sợi
	 . dây này thành 1 sao cho chi phí nối dây là lớn nhất

	- Input Format: Dòng 1 chứa số nguyên N; Dòng 2 chứa N số nguyên là độ dài các sợ dây.

	- Output Format: Đáp án của bài toán chia dư với 10^9 + 7.

	- Constraints: 1<=N<=10^5; Các sợi dây có độ dài không quá 10^9;

	- IP1: 9
		   10 1 5 7 4 8 7 7 1 

	- OP1: 305
	
	- IP2: 3
		   5 6 1

	- OP2: 23
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    priority_queue<ll, vector<ll>> q;
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	q.push(x);
	}
	ll res = 0;
	while(q.size() > 1) {
		ll x = q.top(); q.pop();
		ll y = q.top(); q.pop();
		res += x + y;
		res %= mod;
		q.push(x + y);
	}
	cout << res;
    return 0;
}