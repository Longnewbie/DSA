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
	- Cho xâu ký tự S[] bao gồm các ký tự in hoa [A, B, …,Z]. Ta định nghĩa giá trị của xâu S[] là tổng bình phương số lần xuất
	  hiện mỗi ký tự trong xâu. Ví dụ với xâu S[] = “AAABBCD” ta có F(S) = 3^2 + 2^2 + 1^2 + 1^2 = 15. Hãy tìm giá trị nhỏ nhất 
	  của xâu S[] sau khi loại bỏ K ký tự trong xâu.

	- Input Format: Dòng đầu tiên đưa vào số lượng test T. Mỗi test được tổ chức thành 2 dòng. Dòng thứ nhất ghi lại số K. Dòng 
	  thứ 2 ghi lại xâu ký tự S[] có độ dài không vượt quá 10^6.

	- Output Format: Đưa ra giá trị nhỏ nhất của mỗi test theo từng dòng.

	- Constraints: T≤100; 1<=K<=10^6; 1<=len(S)<=10^6; Xâu S chỉ bao gồm các kí tự in hoa hoặc in thường.

	- IP1:  2
			0
			ABCC
			1
			ABCC

	- OP1:  6
			3
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--) {
    	int k; cin >> k;
    	string s; cin >> s;
    	map<char,int> mp;
    	for (char x : s) mp[x]++;
    	priority_queue<int> q;
    	for (auto x : mp) q.push(x.second);
    	while(k--) {
    		int tmp = q.top(); q.pop();
    		tmp--;
    		q.push(max(tmp, 0));
		}
		ll res = 0;
		while(!q.empty()) {
			ll ans = q.top(); q.pop();
			res += 1ll * ans * ans;
		}
		cout << res << "\n";
	}
    return 0;
}