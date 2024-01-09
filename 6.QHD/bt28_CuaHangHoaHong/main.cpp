#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Có hoa hồng trong một cửa hàng. Mỗi bông hồng được chỉ định một ID. Những bông hồng này được sắp xếp theo thứ tự 
	  1, 2, 3... n. Mỗi bông hồng có một hệ số mùi được ký hiệu là smell[i] . Bạn muốn mua hoa hồng ở cửa hàng này với 
	  điều kiện phải mua hoa hồng theo phân khúc. Nói cách khác, bạn có thể mua hoa hồng từ đến l đến r. Bạn có thể loại
	  bỏ nhiều nhất một hoa hồng khỏi phân đoạn hoa hồng này. Như vậy, chiều dài cuối cùng của hoa hồng là n hoặc n - 1.
	  Nhiệm vụ của bạn là tính toán độ dài tối đa có thể có của dãy liền kề tăng dần các hệ số mùi của những bông hoa hồng này.

	- Input Format: Dòng 1 chứa số nguyên n; Dòng thứ 2 chứa n số smell[1], smell[2], .. smell[n].

	- Output Format: In ra đáp án của bài toán.

	- Constraints: 2<=n<=2.10^5; 1<=smell[i]<=10^9.

	- IP1: 5
		   1 2 5 3 4

	- OP1: 4
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);    
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    int F[n + 1] = {0}, G[n + 1] = {0};
    int res = 0;
    F[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] > a[i - 1]) F[i] = F[i - 1] + 1;
        else F[i] = 1;
        res = max(res, F[i]);
    }
    G[n] = 1;
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] < a[i + 1]) G[i] = G[i + 1] + 1;
        else G[i] = 1;
        res = max(res, G[i]);
    }
    for (int i = 2; i <= n - 1; i++) {
        if (a[i - 1] < a[i + 1]) res = max(res, F[i - 1] + G[i + 1]);
    }
    cout << res;
    return 0; 
}