#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Hoàng yêu thích các số may mắn. Ta biết rằng một số là số may mắn nếu biểu diễn thập phân của nó chỉ chứa các chữ số may 
	  mắn là 4 và 7. Ví dụ, các số 47, 744, 4 là số may mắn và 5, 17, 467 không phải. Hoàng muốn tìm số may mắn bé nhất có tổng 
	  các chữ số bằng n. Hãy giúp anh ấy.

	- Input Format: Dòng duy nhất chứa số nguyên dương n.

	- Output Format: In ra đáp án của bài toán, nếu không tồn tại đáp án thì in ra -1.

	- Constraints: 1<=n<=10^6; 

	- IP1: 16

	- OP1: 4444
	
	- IP2: 14

	- OP2: 77
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    for (int y = n/7; y >= 0; y--) {
    	if ((n - 7 * y) % 4 == 0) {
    		int x = (n - 7 * y)/4;
    		for (int i = 0; i < x; i++) cout << 4;
    		for (int i = 0; i < y; i++) cout << 7;
    		return 0;
		}
	}
	cout << -1;
    return 0;
}