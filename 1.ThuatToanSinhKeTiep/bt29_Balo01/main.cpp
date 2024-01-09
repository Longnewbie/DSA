#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Một tên trộm đột nhập vào 28techland và muốn lấy đi 1 số đồ vật có giá trị lớn nhất. Ở 28techland tồn tại n đồ vật, đồ 
	  vật thứ i sẽ có trọng lượng w[i] và có giá trị là v[i], tên trộm mang theo cái balo có thể chứa được trọng lượng tối đa
	  là S, nhiệm vụ của bạn là hãy giúp tên trộm lựa chọn các đồ vật sao cho tổng trọng lượng của chúng không vượt quá S và 
	  có giá trị lớn nhất. Chú ý tên trộm chỉ có thể chọn hoặc không chọn 1 đồ vật.

	- Input Format: Dòng đầu tiên là N và S; Dòng thứ 2 là N số tương ứng với trọng lượng của các đồ vật; Dòng thứ 3 là N số
	  tương ứng với giá trị của các đồ vật; 

	- Output Format: In ra tổng giá trị của các đồ vật trong balo.

	- Constraints: 1<=N<=15; 1<=S<=800; 1<=w[i]<=200; 1<=v[i]<=200;

	- IP1: 12 356
		   174 153 127 156 156 5 132 161 170 26 181 50 
		   103 32 102 85 54 166 187 173 137 54 24 91 

	- OP1: 617
*/

int n, s, ok, w[202], v[202], a[202];

void ktao() {
	cin >> n >> s;
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) cin >> v[i];
}

void sinh() {
	int i = n;
	while(i >= 1 && a[i] == 1) {
		a[i--] = 0;
	}
	if (i == 0) ok = 1;
	else a[i] = 1;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ktao();
    ll res = -1e9;	
    while(!ok) {
    	ll ans = 0, val = 0;
    	for (int i = 1; i <= n; i++) {
    		if (a[i]) {
    			ans += w[i];
    			val += v[i];
			}
		}
		if (ans <= s) res = max(res, val);
		sinh();
	}
	cout << res;
    return 0;
}
