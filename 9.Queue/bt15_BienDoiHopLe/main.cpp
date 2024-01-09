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
	- Cho cặp số S và T là các số nguyên tố có 4 chữ số (Ví dụ S = 1033, T = 8197 là các số nguyên tố có 4 chữ số). Hãy viết 
	  chương trình tìm cách dịch chuyển S thành T thỏa mãn đồng thời những điều kiện dưới đây: a. Mỗi phép dịch chuyển chỉ 
	  được phép thay đổi một chữ số của số ở bước trước đó (ví dụ nếu S=1033 thì phép dịch chuyển S thành 1733 là hợp lệ); 
	  b.Số nhận được cũng là một số nguyên tố có 4 chữ số (ví dụ nếu S=1033 thì phép dịch chuyển S thành 1833 là không hợp lệ, 
	  và S dịch chuyển thành 1733 là hợp lệ); c. Số các bước dịch chuyển là ít nhất. Ví dụ số các phép dịch chuyển ít nhất
	  để S = 1033 thành T = 8179 là 6 bao gồm các phép dịch chuyển như sau: 8179 8779 3779 3739 3733 1733 1033.

	- Input Format: • Dòng đầu tiên đưa vào số lượng test T (T≤100).
					• Những dòng kế tiếp mỗi dòng đưa vào một test. Mỗi test là một bộ đôi S, T.

	- Output Format: • Đưa ra kết quả mỗi test theo từng dòng.

	- Constraints: N/A

	- IP1:  8
			3727 4649
			3989 5347
			1249 5821
			9857 4603
			4903 7949
			3533 9337
			7949 1087
			8867 6277

	- OP1:  5
			5
			5
			6
			4
			4
			5
			4
*/

int P[10001];

void sieve() {
	for (int i = 1; i <= 10000; i++) P[i] = 1;
	P[0] = P[1] = 0;
	for (int i = 2; i <= sqrt(10000); i++) {
		if (P[i]) {
			for (int j = i * i; j <= 10000; j+=i) {
				P[j] = 0;
			}
		}
	}
}

int BFS(int s, int t) {
	queue<pii> q;
	q.push({s, 0});
	set<int> se;
	se.insert(s);
	while(!q.empty()) {
		pii top = q.front(); q.pop();
		int v = top.first, u = top.second;
		if (v == t) return u;
		string tmp = to_string(v);
		for (int i = 0; i < 4; i++) {
			char y = tmp[i];
			for (char x : {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}) {
				if (tmp[i] != x) {
					tmp[i] = x;
					int val = stoi(tmp);
					if (val >= 1000 && P[val]) {
						if (!se.count(val)) {
							q.push({val, u + 1});
							se.insert(val);
						}
					}
				}
			}
			tmp[i] = y;
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int t; cin >> t;
    while(t--) {
    	int s, t; cin >> s >> t;
    	cout << BFS(s, t) << "\n";
	}
    return 0;
}