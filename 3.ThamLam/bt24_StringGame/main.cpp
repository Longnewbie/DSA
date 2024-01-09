#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Tí vào Tèo chơi một trò chơi với xâu kí tự. Luật chơi như sau, ở mỗi lượt chơi 2 người có thể lựa chọn 1 trong 2 thao 
	  tác : 1. Hai người đi theo lượt, Tí là người đi trước, ở mỗi lượt đi 2 bạn nhỏ có thể lựa chọn 1 kí tự bất kỳ và xóa
	  kí tự này khỏi xâu S. 2.Lấy xâu S sau đó sắp đặt lại các kí tự trong xâu sao cho nó là một xâu đối xứng thì người đó
	  sẽ thắng. Biết rằng 2 bạn đều chơi tối ưu, bạn hãy xác định xem ai là người chiến thắng ?

	- Input Format: Dòng duy nhất chứa xâu S.

	- Output Format: Nếu Tí thắng in ra 1, ngược lại nếu Tèo thắng in ra 2.

	- Constraints: S chỉ bao gồm các kí tự in thường và có độ dài không quá 10000.

	- IP1: kpjdpgb

	- OP1: 1
	
	- IP2: safjaqih

	- OP2: 2
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    int d[256] = {0};
    for (char x : s) {
        d[(int)x]++;
    }
    int chan = 0, le = 0;
    for (int i = 0; i < 256; i++) {
        if (d[i]) {
            if (d[i] % 2 == 0) chan++;
            else le++;
        }
    }
    if (le % 2 == 1) cout << 1;
    else cout << 2;
    return 0;
}