#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Một dãy số tự nhiên bắt đầu bởi con số 1 và được thực hiện N-1 phép biến đổi “gấp đôi” dãy số như sau: Với dãy số A hiện
	  tại, dãy số mới có dạng A, x, A trong đó x là số tự nhiên bé nhất chưa xuất hiện trong A.

	  Ví dụ với 2 bước biến đổi, ta có [1] - [1 2 1] - [1 2 1 3 1 2 1].

	  Các bạn hãy xác định số thứ K trong dãy số cuối cùng là bao nhiêu ?

	- Input Format: Dòng duy nhất chứa 2 số nguyên dương N và K.

	- Output Format: In ra đáp án của bài toán.

	- Constraints: 1<=N<=50; 1<=K<=2^N - 1.

	- IP1: 3 2

	- OP1: 2
	
	- Explanation1:  1
				   1 2 1
				1 2 1 3 1 2 1 (vi tri thu k can tim tinh tu trai qua => 2);
				
	- IP2: 4 8

	- OP2: 4
	
	- Explanation1:  1
				   1 2 1
			   1 2 1 3 1 2 1
	   1 2 1 3 1 2 1 4 1 2 1 3 1 2 1 (vi tri thu k can tim tinh tu trai qua => 4);			
*/

ll find(int n, int k) {
	if (k % 2 == 1) return 1;
	if (k == (ll)pow(2, n - 1)) return n;
	if (k < (ll)pow(2, n - 1)) {
		return find(n - 1, k); //Nua ben trai
	} else return find(n - 1, k - (ll)pow(2, n - 1)); //Nua ben phai
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    cout << find(n, k);
    return 0;
}