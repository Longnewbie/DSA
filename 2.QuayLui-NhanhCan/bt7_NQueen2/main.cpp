#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho một bàn cờ 8 x 8, mỗi ô có một giá trị A[i][j] nhất định (0 ≤ A[i][j] ≤ 100), tương ứng với điểm số đạt được nếu
	  như bạn đặt một quân cờ vào đó. Nhiệm vụ của bạn là đặt 8 quân hậu lên bàn cờ, sao cho không có 2 quân nào ăn nhau, và 
	  số điểm đạt được là lớn nhất.
	  
	- Input Format: Gồm 8 dòng, mỗi dòng gồm 8 số tương ứng với các số trên bàn cờ.
	
	- Output Format: In ra số điểm đạt được lớn nhất.
	
	- Constraints: 1<=A[i][j]<=100;
	
	- Sample Input 0:   12 29 80 91 56 46 97 13 
						54 88 27 84 85 9 32 77 
						48 80 88 74 30 77 38 98 
						6 82 20 95 7 86 12 43 
						100 82 15 7 95 9 5 84 
						51 40 65 98 86 38 30 63 
						96 78 98 76 33 11 2 58 
						33 51 35 68 62 87 67 39 
	
	- Sample Output 0: 653
*/

int n = 8, a[20][20], cot[20], xuoi[20], nguoc[20], res;

void Try(int i, int sum) {
	for (int j = 1; j <= n; j++) {
		if (!cot[j] && !xuoi[i - j + n] && !nguoc[i + j - 1]) {
			cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 1;
			if (i == n) {
				res = max(res, sum + a[i][j]);
			} else Try(i + 1, sum + a[i][j]);
			cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 0;
		}
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);    
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    		cin >> a[i][j];
		}
	}
	Try(1, 0);
	cout << res;
    return 0; 
}