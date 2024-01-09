#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cô bé Anna đi mua sắm cùng mẹ và cô băn khoăn không biết làm thế nào để cải thiện chất lượng dịch vụ.

	  Có n người trong hàng đợi. Đối với mỗi người, chúng tôi biết thời gian cần thiết t để phục vụ anh ta. Một người sẽ thất
	  vọng nếu thời gian anh ta chờ đợi nhiều hơn thời gian cần thiết để phục vụ anh ta. Thời gian một người chờ là tổng thời
	  gian tất cả những người đứng trong hàng đợi trước mặt anh ta được phục vụ. Anna nghĩ rằng nếu chúng ta hoán đổi một số 
	  người trong hàng đợi, thì chúng ta có thể giảm số người thất vọng.

	  Giúp Anna tìm ra con số tối đa mà những người không thất vọng có thể đạt được bằng cách hoán đổi những người trong hàng 
	  đợi.

	- Input Format: Dòng đầu tiên chứa số N là số người trong hàng đợi; Dòng thứ 2 chứa N số là thời gian cần phục vụ của
	  N người.

	- Output Format: In ra đáp án của bài toán.

	- Constraints: 1<=N<=10^5; 1<=t<=10^9;

	- IP1: 7
		   4 3 17 4 5 14 20 

	- OP1: 3
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    sort(a, a + n);
    int res = 0, s = 0;
    for (int i = 0; i < n; i++) {
    	if (s <= a[i]) {
    		s += a[i];
    		res++;
		}
	}
	cout << res;
    return 0;
}