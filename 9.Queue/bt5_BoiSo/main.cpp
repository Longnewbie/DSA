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
	- Cho số tự nhiên N. Hãy tìm số nguyên dương X nhỏ nhất được tạo bởi số 8 và số 0 chia hết cho N. Ví dụ với N = 5 ta 
	  sẽ tìm ra X = 80.

	- Input Format: Dòng đầu tiên ghi lại số lượng test T (T≤100). Những dòng kế tiếp mỗi dòng ghi lại một test. Mỗi test 
	  là một số tự nhiên N được ghi trên một dòng (N≤200).

	- Output Format: Đưa ra theo từng dòng số X nhỏ nhất chia hết cho N tìm được.

	- Constraints: N/A

	- IP1:  6
			61
			79
			45
			129
			5
			176

	- OP1:  800808
			80080088
			8888888880
			800800008
			80
			880
*/

vector<ll> v;
void init() {
	queue<ll> q;
	q.push(8);
	while(1) {
		ll res = q.front(); q.pop();
		v.pb(res);
		if (res >= 1e18) break;
		q.push(res * 10);
		q.push(res * 10 + 8);
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    vector<ll> res(201); 
    for (int i = 1; i <= 200; i++) {
    	for (ll x : v) {
    		if (x % i == 0) {
    			res[i] = x;
    			break;
			}
		}
	}
    int t; cin >> t;
    while(t--) {
    	int n; cin >> n;
		cout << res[n] << "\n";
	}
    return 0;
}