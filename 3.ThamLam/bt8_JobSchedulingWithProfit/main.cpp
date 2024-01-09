#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho N công việc. Mỗi công việc được biểu diễn như một bộ 3 số nguyên dương , trong đó JobId là mã của việc, Deadline là 
	  thời gian kết thúc của việc, Profit là lợi nhuận đem lại nếu hoàn thành việc đó đúng thời gian. Thời gian để hoàn toàn 
	  mỗi công việc là 1 đơn vị thời gian. Hãy cho biết lợi nhuận lớn nhất có thể thực hiện các việc với giả thiết mỗi việc 
	  được thực hiện đơn lẻ.

	- Input Format: Dòng thứ 1 chứa số nguyên dương N; N dòng tiếp theo mô tả id, deadline, profit của N công việc.

	- Output Format: In ra lợi nhuận lớn nhất

	- Constraints: 1<=N<=10^5; 1<=JobID<=N; 1<=Deadline<=N; 1<=Profit<=1000;

	- IP1:  4
			1 4 20
			2 1 10
			3 1 40
			4 1 30

	- OP1: 60
*/

struct jobs {
	int id, dl, pf;
};

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    jobs a[n];
    for (int i = 0; i < n; i++) {
    	cin >> a[i].id >> a[i].dl >> a[i].pf;
	}
	sort(a, a + n, [](jobs a, jobs b) -> bool {
		return a.pf > b.pf;
	});
	int used[n] = {0}, res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = a[i].dl - 1; j >= 0; j--) {
			if (!used[j]) {
				res += a[i].pf;
				used[j] = 1;
				break;
			}
		}
	}
	cout << res;
    return 0;
}