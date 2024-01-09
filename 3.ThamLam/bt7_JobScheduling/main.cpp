#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho hệ gồm N hành động. Mỗi hành động được biểu diễn như một bộ đôi tương ứng với thời gian bắt đầu và thời gian kết thúc
	  của mỗi hành động. Hãy tìm phương án thực hiện nhiều nhất các hành động nhất có thể, biết rắng 2 hành động phải được thực 
	  hiện một cách độc lập. 2 hành động được gọi là độc lập nếu thời gian kết thúc của hành động thứ nhất nhỏ hơn thời gian
	  bắt đầu của hành động thứ 2.

	- Input Format: Dòng đầu tiên là số nguyên dương N; N dòng tiếp theo chứa thời gian bắt đầu và kết thúc của N hành động;

	- Output Format: In ra số lượng hành động nhiều nhất có thể thực hiện.

	- Constraints: 1<=N<=10^6; 1<=Start[i]<=End[i]<=10^7;

	- IP1:  16
			1 5
			2 7
			3 7
			5 7
			6 7
			10 12
			10 13
			1 3
			7 8
			9 14
			5 6
			9 10
			3 5
			8 13
			1 6
			3 6

	- OP1:  4
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    pair<int,int> p[n];
    for (int i = 0; i < n; i++) {
    	cin >> p[i].first >> p[i].second;
	}
	sort(p, p + n, [](pair<int,int> x, pair<int,int> y){
		return x.second < y.second;
	});
	int ans = p[0].second, cnt = 1;
	for (int i = 1; i < n; i++) {
		if (p[i].first > ans) {
			cnt++;
			ans = p[i].second;
		}
	}
	cout << cnt;
    return 0;
}
