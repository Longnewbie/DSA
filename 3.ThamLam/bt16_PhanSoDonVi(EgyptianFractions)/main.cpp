#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Một phân số đơn vị nếu tử số của phân số đó là 1. Mọi phân số nguyên dương đều có thể biểu diễn thành tổng các phân số 
	  đơn vị. Ví dụ 2/3 = 1/2 + 1/6. Cho phân số nguyên dương P/Q bất kỳ , hãy biểu diễn phân số nguyên dương thành tổng phân 
	  số đơn vị với số hạng tử là ít nhất.

	- Input Format: 1 dòng duy nhất chứa 2 số P, Q.

	- Output Format: Đưa ra đáp án trên 1 dòng.

	- Constraints: 1<=P,Q<=200.

	- IP1: 9 6

	- OP1: 1/1 + 1/2
	
	- IP2: 5 6

	- OP2: 1/2 + 1/3
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll p, q; cin >> p >> q;
    while(p) {
        if (q % p == 0) {
            cout << "1/" << q/p;
            return 0;
        } else {
            ll x = q/p + 1;
            cout << "1/" << x << " + ";
            p = p * x - q;
            q = q * x;
        }
    }
    return 0;
}
