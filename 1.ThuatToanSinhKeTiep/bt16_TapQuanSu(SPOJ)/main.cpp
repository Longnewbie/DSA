#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Tại Malibu(Mai Lĩnh) Resort, vào nửa đêm, cả trung đội nhận lệnh tập trung ở sân. Mỗi chiến sỹ được đánh số từ 1 đến N.
	  Giám thị yêu cầu chọn ra một dãy K chiến sỹ để tập đội ngũ và cứ lần lượt duyệt hết tất cả các khả năng chọn K người như
	  vậy từ nhỏ đến lớn (theo số thứ tự). Bài toán đặt ra là cho một nhóm K chiến sỹ hiện đang phải tập đội ngũ, hãy tính xem
	  trong lượt chọn K người tiếp theo thì mấy người trong nhóm cũ sẽ được nghỉ. Nếu đã là nhóm cuối cùng thì tất cả đều được
	  nghỉ.

	- Input Format: Dòng 1: hai số nguyên dương N và K; Dòng 2 ghi K số thứ tự của các chiến sỹ đang phải tập đội ngũ
	  (viết từ nhỏ đến lớn).

	- Output Format: In ra số lượng chiến sỹ được nghỉ

	- Constraints: 1<=K<=N<=1000;

	- IP1: 8 3
		   4 6 7 

	- OP1: 1
*/

int n, k, ok, a[1001];

void sinh() {
	int i = k;
	while(i >= 1 && a[i] == n - k + i) --i;
	if (i == 0) ok = 1;
	a[i]++;
	for (int j = i + 1; j <= k; j++) a[j] = a[j - 1] + 1;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    int b[k];
    for (int i = 1; i <= k; i++) {
    	cin >> b[i];
    	a[i] = b[i];
	}
    sinh();
    int cnt = 0;
    for (int i = 1; i <= k; i++) {
    	if (a[i] != b[i]) cnt++;
	}
	cout << cnt;
    return 0;
}