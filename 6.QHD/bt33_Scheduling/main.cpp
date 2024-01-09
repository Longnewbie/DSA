#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Có n dự án bạn có thể tham dự. Đối với mỗi dự án, bạn biết ngày bắt đầu và ngày kết thúc của dự án và số tiền bạn sẽ nhận
	  được khi hoàn thành nó. Bạn chỉ có thể tham dự một dự án trong một ngày. Số tiền tối đa bạn có thể kiếm được là bao nhiêu?

	- Input Format: Dòng đầu tiên chứa số nguyên n: số lượng dự án. Sau đó, có n dòng. Mỗi dòng như vậy có ba số nguyên ai, bi 
	  và pi: ngày bắt đầu, ngày kết thúc và tiền thưởng.

	- Output Format: In ra đáp án của bài toán.

	- Constraints: 1≤n≤2⋅10^5; 1≤ai≤bi≤10^9; 1≤pi≤10^9;

	- IP1:  4
			2 4 4
			3 6 6
			6 8 2
			5 7 3

	- OP1:  7
*/

struct Job {
	int bd, kt, pro;
};

int last_pos(vector<pair<int,ll>> &v, Job x) {
	int l = 0, r = v.size() - 1, res = -1;
	while(l <= r) {
		int m = (r + l)/2;
		if (v[m].first < x.bd) {
			res = m;
			l = m + 1;
		} else r = m - 1;
	}
	return res;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    Job a[n + 1];
    for (int i = 1; i <= n; i++) {
    	cin >> a[i].bd >> a[i].kt >> a[i].pro;
	}
	sort(a + 1, a + n + 1, [](Job a, Job b)-> bool {
		return a.kt < b.kt;
	});
	vector<pair<int,ll>> v;
	ll dp[n + 1];
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		int t = last_pos(v, a[i]);
		if (t != -1) {
			dp[i] = max(dp[i], v[t].second + a[i].pro);
		} else {
			dp[i] = max(dp[i], 1ll * a[i].pro);
		}
		v.pb({a[i].kt, dp[i]});
	}
	cout << dp[n];
    return 0;
}