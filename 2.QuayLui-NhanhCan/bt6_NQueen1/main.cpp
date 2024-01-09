#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho một bàn cờ vua có kích thước n * n. Vấn đề đặt ra rằng, có n quân hậu, bạn cần đếm số cách đặt n quân hậu này lên 
	  bàn cờ sao cho với 2 quân hậu bất kì, chúng không “ăn” nhau.
	  
	- Input Format: Dòng duy nhất chứa n là kích thước của bàn cờ.
	
	- Output Format: In ra số cách xếp hậu hợp lệ
	
	- Constraints: 1<=N<=12
	
	- Sample Input 0: 8
	
	- Sample Output 0: 92
*/

int n, cot[20], xuoi[20], nguoc[20], cnt;

//đường chéo xuôi : i - j + n; 
//đường chéo ngược : i + j - 1;
void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (!cot[j] && !xuoi[i - j + n] && !nguoc[i + j - 1]) {
			cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 1;
			if (i == n) cnt++;
			else Try(i + 1);
			cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 0;
		}
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);    
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(cot, 0, sizeof(cot));
    memset(xuoi, 0, sizeof(xuoi));
    memset(nguoc, 0, sizeof(nguoc));
    Try(1);
    cout << cnt;
    return 0; 
}