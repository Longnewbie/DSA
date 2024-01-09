#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Có N nhóm học sinh, mỗi nhóm học sinh có từ 1 tới 4 người. Các nhóm học sinh này dự định sẽ đi thăm quan vườn bách thú 
	  bằng những chiếc xe taxi, mỗi xe taxi trở được tối đa 4 người. Hãy tìm số lượng taxi tối thiểu để có thể trở hết N nhóm
	  học sinh này, biết rằng những học sinh ở cùng 1 nhóm sẽ đi cùng 1 taxi.

	- Input Format: Dòng đầu tiên chứa số nguyên dương N là số nhóm học sinh; Dòng thứ 2 gồm N số là số lượng của các nhóm 
	  .học sinh

	- Output Format: In ra số lượng xe taxi tối thiểu cần dùng.

	- Constraints: 1<=N<=10000; Số lượng học sinh của mỗi nhóm là 1 số dương không quá 4

	- IP1: 6
		   2 1 3 1 2 2 

	- OP1: 3
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int a[n], cnt[5] = {0};
    for (int &x : a) {
           cin >> x;
           cnt[x]++;
    }
    int d4 = cnt[4];
    int d31 = 0;
    if (cnt[3] >= cnt[1]) {
        d31 = cnt[3];
        cnt[1] = 0;
    } else {
        d31 = cnt[3];
        cnt[1] -= cnt[3];
        cnt[3] = 0;
    }
    int d22 = cnt[2]/2;
    int d211 = 0;
    if (cnt[2] % 2 == 1) {
        d211 = 1;
        cnt[1] -= min(2, cnt[1]);
    }
    int d1111 = cnt[1]/4;
    if (cnt[1] % 4 != 0) d1111++;
    cout << d4 + d31 + d22 + d211 + d1111;
    return 0;
}
