#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Tí vào Tèo cùng chơi một trò chơi với xâu nhị phân S. Xâu nhị phân S chỉ bao gồm các kí tự 0 và 1. Ở mỗi bước đi, 2 bạn 
	  nhỏ có thể chọn 1 xâu con liên tiếp các kí tự giống nhau ở xâu S và xóa nó khỏi xâu S. Sau khi xóa 1 xâu thì 2 xâu bên
	  trái và phải của xâu vừa xóa sẽ trở thành liền kề. Ban đầu Tí là người đi trước, sau đó 2 bạn lần lượt thực hiện bước
	  đi của mình cho tới khi xâu S trở thành xâu rỗng. Bạn hãy xác định xem Tí có thể xóa tối đa bao nhiêu kí tự 1 biết rằng
	  cả 2 bạn đều chơi tối ưu.

	- Input Format: Dòng duy nhất chứa xâu S.

	- Output Format: In ra số lượng số 1 tối đa mà Tí có thể xóa được.

	- Constraints: 1<=len(S)<=100000;

	- IP1: 1000101110011111

	- OP1: 6
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    s += "0";
    int cnt = 0;
    vector<int> v;
    for (char x : s) {
    	if (x == '1') cnt++;
    	else if (x == '0' && cnt > 0) {
    		v.pb(cnt);
    		cnt = 0;
		}
	}
	sort(v.begin(), v.end(), greater<int>());
	int res = 0;
	for (int i = 0; i < v.size(); i+=2) res += v[i];
	cout << res;
    return 0;
}
