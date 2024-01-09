#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- John có một đàn bò. Một ngày đẹp trời, anh ta quyết định mua xe tải với khả năng chở được C kg (1000 ≤ C ≤ 25000) để đưa
	  những con bò đi xem phim. Cho số con bò là N (20 ≤ N ≤ 100) và khối lượng w[i] của từng con (đều nhỏ hơn C), hãy cho biết
	  khối lượng bò lớn nhất mà John có thể đưa đi xem phim là bao nhiêu.

	- Input Format: Dòng 1: 2 số nguyên C và N cách nhau bởi dấu cách; Dòng 2: Ghi lần lượt các số nguyên: w[i]

	- Output Format: Một số nguyên là tổng khối lượng bò lớn nhất mà John có thể mang đi xem phim.

	- Constraints: 1000 ≤ C ≤ 25000; 20 ≤ N ≤ 100; w[i] <= C;

	- IP1:  259 5
			81 58 42 33 61

	- OP1: 242
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c, n; cin >> c >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<bool> dp(c + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = c; j >= a[i]; j--) {
            if (dp[j - a[i]]) {
                dp[j] = true;
            }
        }
    }
    for (int i = c; i >= 0; i--) {
        if (dp[i]) {
            cout << i;
            return 0;
        }
    }
    return 0;
}