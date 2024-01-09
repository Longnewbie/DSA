#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Tèo đang chơi một game là nông trại vui vẻ, để tham gia game nông trại vui vẻ, các game thủ phải sử dụng 2 công vụ là cuốc
	  và liềm. Biết rằng để đổi lấy 1 cái cuốc thì cần 2 đồng xu và 1 kim cương, để đổi lấy 1 cái liềm thì cần 1 đồng xu và 
	  2 kim cương. Hãy xác định tổng số cuốc và liềm lớn nhất mà Tèo có thể đổi được biết rằng Tèo có a đồng xu và b kim cương.

	- Input Format: Dòng duy nhất chứa 2 số a và b.

	- Output Format: In ra đáp án của bài toán

	- Constraints: 0<=a,b<=10^9

	- IP1: 6 8

	- OP1: 4
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x1, x2; cin >> x1 >> x2;
    int a = min(x1, x2), b = max(x1, x2);
    if (a * 2 <= b) cout << a;
    else {
        int x = b - a;
        int y = (a - x)/3 * 2;
        if ((a - x) % 3 == 2) y++;
        cout << x + y;
    }
    return 0;
}