#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Bạn được cung cấp một mảng A gồm N giá trị nguyên dương. Một mảng con của mảng này được gọi là mảng con Chẵn lẻ nếu số
	  lượng các số nguyên lẻ trong mảng con này bằng số lượng các số nguyên chẵn trong mảng con này.

	  Tìm số mảng con Lẻ-Chẵn cho mảng đã cho.

	- Input Format: Dòng đầu chứa N; Dòng thứ 2 chứa N số nguyên trong dãy.

	- Output Format: In ra đáp án của bài toán

	- Constraints: 1<=N<=2.10^5; 1<=A[i]<=10^9;

	- IP1: 4
		   1 2 1 2

	- OP1: 4
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    map<int,int> mp;
    mp[0] = 1;
    int c = 0, l = 0;
    ll res = 0;
    for (int i = 0; i < n; i++) {
    	int x; cin >> x;
    	if (x % 2 == 0) c++;
    	else l++;
    	if (mp.count(c - l)) res += mp[c - l];
    	mp[c - l]++;
	}
	cout << res;
    return 0;
}