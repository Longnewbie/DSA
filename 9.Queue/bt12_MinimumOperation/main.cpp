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
	- Cho hai số nguyên dương S và T và hai thao tác (a), (b) dưới đây: Thao tác (a): Trừ S đi 1 (S = S-1) ; Thao tác (b): Nhân
	  S với 2 ( S = S * 2); Hãy dịch chuyển S thành T sao cho số lần thực hiện các thao tác (a), (b) là ít nhất. Ví dụ với S =2,
	  T=5 thì số các bước ít nhất để dịch chuyển S thành T thông qua 4 thao tác sau: Thao tác (a): 2 * 2 = 4; 
	  Thao tác (b): 4-1 = 3; Thao tác (a): 3 * 2 = 6; Thao tác (b): 6-1 = 5;

	- Input Format: • Dòng đầu tiên ghi lại số tự nhiên T là số lượng Test; 
					• T dòng kế tiếp mỗi dòng ghi lại một bộ Test. Mỗi test là một bộ đôi S và T.

	- Output Format: Đưa ra kết quả mỗi test theo từng dòng.

	- Constraints: 1<=S,T<10000.

	- IP1:  6
			17 16
			16 10
			13 17
			13 10
			17 17
			16 19

	- OP1:  1
			6
			6
			3
			0
			8
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    while(n--) {
    	int s, t; cin >> s >> t;
    	set<int> se;
    	se.insert(s);
    	queue<pii> q;
    	q.push({s, 0});
    	while(1) {
    		pii top = q.front(); q.pop();
    		if (top.first == t) {
    			cout << top.second << "\n";
    			break;
			}
			if (top.first > 1 && !se.count(top.first - 1)) {
				q.push({top.first - 1, top.second + 1});
				se.insert(top.first - 1);
			}
			if (top.first < t && !se.count(top.first * 2)) {
				q.push({top.first * 2, top.second + 1});
				se.insert(top.first * 2);
			}
		}
	}
    return 0;
}