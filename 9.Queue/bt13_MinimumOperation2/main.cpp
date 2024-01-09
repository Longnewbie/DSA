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
	- Cho số tự nhiên N và hai phép biến đổi (a), (b) dưới đây. • Thao tác (a): Trừ N đi 1 (N=N-1). Ví dụ N=17, thao tác (a)
	  biến đổi N = N-1 =16. • Thao tác (b): N = max(u,v) nếu u * v =N (u>1, v>1). Ví dụ N=16, thao tác (b) có thể biến đổi 
	  N = max(2, 8)=8 hoặc N=max(4, 4)=4. Chỉ được phép sử dụng hai thao tác (a) hoặc (b), hãy biến đổi N thành 1 sao số các 
	  thao tác (a), (b) được thực hiện ít nhất. Ví dụ với N=17, số các phép (a), (b) nhỏ nhất biến đổi N thành 1 là 4 bước như 
	  sau: - Thao tác (a): N = N-1 = 17-1 = 16. - Thao tác (b): 16 = max(4,4) = 4. - Thao tác (b): 4 = max(2,2) = 2. - Thao tác 
	  (a): 2 = 2-1 = 1.

	- Input Format: • Dòng đầu tiên ghi lại số tự nhiên T là số lượng Test; 
					• T dòng kế tiếp mỗi dòng ghi lại một bộ Test. Mỗi test là một số N;

	- Output Format: • Đưa ra kết quả mỗi test theo từng dòng

	- Constraints: 1<=T<=100; 1<=N<10^9;

	- IP1:  7
			896
			99
			841
			880
			227
			870
			291

	- OP1:  5
			6
			6
			5
			7
			5
			6
*/

int BFS(int n) {
	queue<pii> q;
	q.push({n, 0});
	unordered_map<int,int> um;
	um[n] = 1;
	while(!q.empty()) {
		pii tmp = q.front(); q.pop();
		if (tmp.first == 1) return tmp.second;
		for (int i = 2; i <= sqrt(tmp.first); i++) {
			if (tmp.first % i == 0) {
				int m = max(i, tmp.first / i);
				if (um[m] == 0) {
					q.push({m, tmp.second + 1});
					um[m] = 1;
				}
			}
		}
		if (um[tmp.first - 1] == 0) {
			q.push({tmp.first - 1, tmp.second + 1});
			um[tmp.first - 1] = 1;
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--) {
    	int n; cin >> n;
    	cout << BFS(n) << "\n";
	}
    return 0;
}