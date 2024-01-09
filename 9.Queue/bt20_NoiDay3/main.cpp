#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
#define pii pair<int,int>
#define pip pair<int,pair<int,int>>
int mod = 1e9+7;

/*
	- Cho N sợi dây với độ dài khác nhau được lưu trong mảng A[]. Nhiệm vụ của bạn là nối N sợi dây thành một sợi sao cho tổng 
	  chi phí nối dây là nhỏ nhất. Biết chi phí nối sợi dây thứ i và sợi dây thứ j là tổng độ dài hai sợi dây A[i] và A[j] 
	  Gợi ý : Sử dụng hàng đợi ưu tiên.

	- Input Format: Dòng thứ nhất đưa vào số lượng sợi dây N; Dòng tiếp theo đưa vào N số A[i] là độ dài của các sợi dây; 
	  Các số được viết cách nhau một vài khoảng trống.

	- Output Format: In ra chi phí nhỏ nhất lấy dư với (10^9 + 7).

	- Constraints: 1≤N≤10^6; 1≤A[i]≤10^9.

	- IP1:  5
			4 2 7 6 9

	- OP1:  62
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int a[n];
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for (int &x : a) {
    	cin >> x;
    	q.push(x);
	}
	ll res = 0;
	while(q.size() > 1) {
		ll o1 = q.top(); q.pop();
		ll o2 = q.top(); q.pop();
		ll ans = ((o1 % mod) + (o2 % mod)) % mod;
		res += ans; res %= mod;
		q.push(o1 + o2);
	}
	cout << res;
    return 0;
}