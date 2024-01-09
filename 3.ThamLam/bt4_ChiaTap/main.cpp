#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho mảng A[] gồm N số nguyên không âm và số K. Nhiệm vụ của bạn là hãy chia mảng A[] thành hai mảng con có kích cỡ
	  K và N-K sao cho hiệu giữa tổng hai mảng con là lớn nhất. Ví dụ với mảng A[] = {8, 4, 5, 2, 10}, K=2 ta có kết quả là
	  17 vì mảng A[] được chia thành hai mảng {4, 2} và { 8, 5,10} có hiệu của hai mảng con là 23-6=17 là lớn nhất.

	- Input Format: Dòng duy nhất chứa 2 số nguyên N và K; Dòng thứ 2 gồm N số của mảng A[].

	- Output Format: In ra đáp án của bài toán.

	- Constraints: 1<=K<=N<=10^6; 0<=A[i]<=10^9;

	- IP1: 6 4
		   3 10 10 7 5 2 

	- OP1: 27
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    int a[n];
    for (int &x : a) cin >> x;
    sort(a, a + n);
    k = min(k, n - k);
    ll s1 = 0, s2 = 0;
    for (int i = 0; i < k; i++) s1 += a[i];
    for (int i = k; i < n; i++) s2 += a[i];
    cout << s2 - s1;
    return 0;
}
