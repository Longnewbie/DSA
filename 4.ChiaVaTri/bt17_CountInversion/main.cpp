#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- Cho mảng A[] gồm N phần tử, hãy đếm số lượng cặp A[i], A[j] sao cho i < j và A[i] > A[j];

	- Input Format: Dòng đầu tiên chứa số nguyên dương N; Dòng thứ 2 gồm N phần tử của mảng A.

	- Output Format: In ra đáp án của bài toán.

	- Constraints: 1<=N<=10^6; 1<=A[i]<=10^6;

	- IP1: 9
		   16 14 10 13 19 14 17 18 16 

	- OP1: 12
*/

int merge(int a[], int l, int r, int m) {
	vector<int> trai(a + l, a + m + 1);
	vector<int> phai(a + m + 1, a + r + 1);
	int res = 0;
	int i = 0, j = 0;
	while(i < trai.size() && j < phai.size()) {
		if (trai[i] <= phai[j]) a[l++] = trai[i++];
		else {
			a[l++] = phai[j++];
			res += trai.size() - i;
		} 
	}
	while(i < trai.size()) a[l++] = trai[i++];
	while(j < phai.size()) a[l++] = phai[j++];
	return res;
}

ll mergeSort(int a[], int l, int r) {
	if (l < r) {
		int m = (r + l)/2;
		ll res1 = mergeSort(a, l, m);
		ll res2 = mergeSort(a, m + 1, r);
		return res1 + res2 + merge(a, l, r, m);
	}
	return 0;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    cout << mergeSort(a, 0, n - 1);
    return 0;
}