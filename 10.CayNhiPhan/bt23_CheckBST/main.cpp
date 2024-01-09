#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
#define pii pair<int,int>
#define pip pair<int,pair<int,int>>
int mod = 1e9+7;

/*
	- Cho thự tự duyệt Inorder của một cây nhị phân, hãy xác định xem thứ tự này có phải là thứ tự duyệt inorder của một cây 
	  nhị phân tìm kiếm hay không.

	- Input Format: Dòng đầu tiên là N : số lượng node trên cây; Dòng thứ 2 gồm N node theo thứ tự duyệt inorder.

	- Output Format: In ra YES nếu cây nhị phân đã cho là cây nhị phân tìm kiếm, ngược lại in ra NO.

	- Constraints: 1<=N<=1000; 1<=A[i]<=10^6;

	- IP1:  8
		 	1 3 5 7 9 11 14 16 

	- OP1:  YES
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}