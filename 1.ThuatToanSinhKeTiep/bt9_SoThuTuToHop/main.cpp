#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho 2 số nguyên dương N và K và một tổ hợp K phần tử của tập N phần tử các số từ 1 tới N. Bạn hãy xác định xem tổ hợp 
	  đã cho có số thứ tự bao nhiêu nếu xếp các tổ hợp chập K của N theo thứ tự ngược. Ví dụ N = 5, K = 3 và tổ hợp đã cho
	  là (2, 3, 4) sẽ là tổ hợp có số thứ tự 4.

	- Input Format: Dòng đầu gồm 2 số nguyên dương N và K. Dòng thứ 2 gồm K số mô tả tổ hợp đã cho. Dữ liệu đảm bảo tổ hợp 
	  đã cho là hợp lệ.

	- Output Format: 1<=K<=N<=15;

	- Constraints: 1<=K<=N<=15;

	- IP1: 12 4
		   8 9 10 11  

	- OP1: 5
*/

int n, k, ok, a[101];

void sinh() {
    int i = k;
    while(i >= 1 && a[i] == n - k + i) --i;
    if (i == 0) ok = 1;
    else {
        a[i]++;
        for (int j = i + 1; j <= k; j++) a[j] = a[j - 1] + 1;
    }
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    string s = "";
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        s += to_string(a[i]) + " ";
    }
    s.pop_back();
    vector<string> v;
    while(!ok) {
        string tmp = "";
        for (int i = 1; i <= k; i++) {
            tmp += to_string(a[i]) + " ";
        }
        tmp.pop_back();
        v.push_back(tmp);
        sinh();
    }
    reverse(v.begin(), v.end());
    int d = 0;
    for (auto x : v) {
        d++;
        if (x == s) {
            cout << d;
            return 0;    
        }
    }
    return 0;
}