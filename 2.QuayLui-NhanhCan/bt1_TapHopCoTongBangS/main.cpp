#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Xét tất cả các tập hợp các số nguyên dương có các phần tử khác nhau và không lớn hơn số n cho trước. Nhiệm vụ của bạn
	  là hãy đếm xem có tất cả bao nhiêu tập hợp có số lượng phần tử bằng k và tổng của tất cả các phần tử trong tập hợp bằng
	  s? Các tập hợp là hoán vị của nhau chỉ được tính là một. Ví dụ với n = 9, k = 3, s = 23, {6, 8, 9} là tập hợp duy nhất
	  thỏa mãn.
	  
	- Input Format: 1 dòng gồm 3 số nguyên n, k, s.
	
	- Output Format: In ra số lượng các tập hợp thỏa mãn điều kiện đề bài.
	
	- Constraints: 1 ≤ n ≤ 20, 1 ≤ k ≤ 10 và 1 ≤ s ≤ 155.
	
	- Sample Input 0: 16 8 91
	
	- Sample Output 0: 28
*/

int n, k, s, a[101], cnt;

void Try(int i, int bd, int sum) {
	for (int j = bd; j <= n; j++) {
		if (sum + j <= s) {
			a[i] = j;
			if (i == k) {
				if (sum + j == s) cnt++;
			} else {
				Try(i + 1, j + 1, sum + j);
			}
		}
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);    
    cin.tie(0);
    cout.tie(0);
   	cin >> n >> k >> s;
   	Try(1, 1, 0);
   	cout << cnt;
    return 0; 
}