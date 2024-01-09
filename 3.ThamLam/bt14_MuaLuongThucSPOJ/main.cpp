#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Giả sử bạn là một người nghèo trong địa phương của bạn. Địa phương của bạn có duy nhất một cửa hàng bán lương thực. 
	  Cửa hàng của bạn mở cửa tất cả các ngày trong tuần ngoại trừ chủ nhật. Cho bộ ba số N, S, M thỏa mãn ràng buộc
	  sau: N : số đơn vị lương thực nhiều nhất bạn có thể mua trong ngày. S : số lượng ngày bạn cần được sử dụng lương thực
	  để tồn tại. M :số đơn vị lương thực cần có mỗi ngày để bạn tồn tại. Giả sử bạn đang ở ngày thứ 2 trong tuần và
	  cần tồn tại trong S ngày tới. Hãy cho biết số lượng ngày ít nhất bạn cần phải mua lương thực từ của hàng để tồn tại 
	  hoặc bạn sẽ bị chết đói trong S ngày tới.

	- Input Format: 1 dòng chứa 3 số N, S, M.

	- Output Format: In ra số ngày ít nhất cần mua lương thực, nếu không thể mua đủ lương thực để tồn tại thì in ra -1.

	- Constraints: 1<=S,N,M<=100.

	- IP1: 7 5 7

	- OP1: 5
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, s, m; cin >> n >> s >> m;
    int res = s*m/n;
    if (s * m % n != 0) res++;
    if (res <= s - s/7) cout << res;
    else cout << -1;
    return 0;
}
