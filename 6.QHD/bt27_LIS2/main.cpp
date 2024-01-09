#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Bạn được cung cấp một mảng chứa n số nguyên. Nhiệm vụ của bạn là xác định dãy con dài nhất tăng dần trong mảng, tức là dãy 
	  con dài nhất mà mọi phần tử đều lớn hơn phần tử trước đó. Một dãy con là một dãy có thể được dẫn xuất từ mảng bằng cách xóa
	  một số phần tử mà không làm thay đổi thứ tự của các phần tử còn lại.

	- Input Format: Dòng đầu tiên chứa số nguyên n: kích thước của mảng. Sau đó có n số nguyên x1, x2,…, xn: nội dung của mảng.

	- Output Format: In ra chiều dài của dãy con tăng dài nhất.

	- Constraints: 1≤n≤2⋅10^5; 1≤xi≤10^9;

	- IP1: 6
		   1 2 4 1 5 2

	- OP1: 4
	
	- IP2: 5
		   1 1 1 1 1

	- OP2: 1
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<int> v;
    v.pb(mod);
    for (int i = 0; i < n; i++) {
    	int x; cin >> x;
    	auto it = lower_bound(v.begin(), v.end(), x);
    	if (it == v.end()) v.pb(x);
    	else *it = x;
	}
	cout << v.size();
    return 0;
}