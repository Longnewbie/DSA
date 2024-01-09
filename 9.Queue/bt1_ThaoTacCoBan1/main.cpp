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
	- Ban đầu cho một queue rỗng. Bạn cần thực hiện các truy vấn sau: 1.Trả về kích thước của queue 2.Kiểm tra xem queue có 
	  rỗng không, nếu có in ra “YES”, nếu không in ra “NO”. 3.Cho một số nguyên và đẩy số nguyên này vào cuối queue. 4.Loại 
	  bỏ phần tử ở đầu queue nếu queue không rỗng, nếu rỗng không cần thực hiện. 5.Trả về phần tử ở đầu queue, nếu queue rỗng 
	  in ra -1. 6.Trả về phần tử ở cuối queue, nếu queue rỗng in ra -1.

	- Input Format: Dòng đầu tiên chứa số nguyên n - lượng truy vấn (1 ≤ n ≤ 1000) N dòng tiếp theo, mỗi dòng sẽ ghi loại truy 
	  vấn như trên, với truy vấn loại 3 sẽ có thêm một số nguyên, không quá 10^6.

	- Output Format: In ra kết quả của các truy vấn trên từng dòng.

	- Constraints: N/A

	- IP1:  7
			2
			6
			2
			5
			6
			3 495
			5

	- OP1:  YES
			-1
			YES
			-1
			-1
			495
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    queue<int> q;
    int t; cin >> t;
    while(t--) {
    	int tt; cin >> tt;
    	if (tt == 1) {
    		cout << q.size() << "\n";
		} else if (tt == 2) {
			if (q.empty()) cout << "YES\n";
			else cout << "NO\n";
		} else if (tt == 3) {
			int x; cin >> x;
			q.push(x);
		} else if (tt == 4) {
			if (!q.empty()) {
				q.pop();
			}
		} else if (tt == 5) {
			if (q.empty()) cout << "-1\n";
			else cout << q.front() << "\n";
		} else {
			if (q.empty()) cout << "-1\n";
			else cout << q.back() << "\n";
		}
	}
    return 0;
}