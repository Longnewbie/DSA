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
	- Ta gọi số nguyên dương K là một số BDN nếu các chữ số trong K chỉ bao gồm các 0 hoặc 1 có nghĩa. Ví dụ số K = 101 là số 
	  BDN, k=102 không phải là số BDN. Số BDN của N là số P =M´N sao cho P là số BDN. Cho số tự nhiên N, hãy tìm số BDN nhỏ 
	  nhất của N. Ví dụ. Với N=2, ta tìm được số BDN của N là P = 5´2=10. N = 17 ta tìm được số BDN của 17 là P = 653´17=11101.

	- Input Format: Dòng đầu tiên ghi lại số tự nhiên T là số lượng Test; • T dòng kế tiếp mỗi dòng ghi lại một bộ Test. 
	  Mỗi test là một số tự nhiên N.

	- Output Format: Đưa ra kết quả mỗi test theo từng dòng.

	- Constraints: 1<=T<=100; 1<=N<=500;

	- IP1:  14
			19
			18
			9
			10
			27
			23
			14
			22
			40
			38
			6
			13
			30
			43

	- OP1:  11001
			1111111110
			111111111
			10
			1101111111
			110101
			10010
			110
			1000
			110010
			1110
			1001
			1110
			1101101
*/

vector<ll> v;

void init() {
	queue<ll> q;
	q.push(1);
	while(1) {
		ll res = q.front(); q.pop();
		v.pb(res);
		if (res >= 9e18) break;
		q.push(res * 10);
		q.push(res * 10 + 1);
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    vector<ll> res(500);
    for (int i = 1; i <= 500; i++) {
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