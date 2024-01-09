#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho mảng các số nguyên A[] gồm N phần tử. Hãy chia mảng số nguyên A[] thành K tập con khác rỗng sao cho tổng các phần 
	  tử của mỗi tập con đều bằng nhau. Mỗi phần tử thuộc tập con xuất hiện duy nhất một lần trong tất cả các tập con. Ví dụ 
	  với A[] = {2, 1, 4, 5, 6}, K =3 ta có kết quả {2, 4}, {1, 5}, {6}.
	  
	- Input Format: Dòng thứ nhất là hai số N và K; Dòng tiếp theo đưa vào N số của mảng A[]; các số được viết cách nhau 
	  một vài khoảng trống.
	
	- Output Format: Đưa ra 1 nếu có thể chia tập con thành K tập thỏa mãn yêu cầu bài toán, ngược lại đưa ra 0
	
	- Constraints: 1≤N, K≤20; 0≤A[i]≤100.
	
	- Sample Input 0: 6 4
					  82 43 38 38 18 61 
	
	- Sample Output 0: 0
*/

int n, k, ok, x[101], a[101], used[101], s;

void Try(int i, int cnt, int sum) {
	if (ok) return;
	if (cnt == k) {
		ok = 1;
		return;
	}
	for (int j = 1; j <= n; j++) {
		if (!used[j] && sum + a[j] <= s) {
			x[i] = a[j];
			used[j] = 1;
			if (sum + a[j] == s) Try(i + 1, cnt + 1, 0);
			else Try(i + 1, cnt, sum + a[j]);
			used[j] = 0;
		}
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);    
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    	s += a[i];
	} 
	if (s % k == 0) {
		s /= k;
		Try(1, 0, 0);
		cout << ok;
	} else cout << 0;
    return 0; 
}