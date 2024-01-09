#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Nhiệm vụ của bạn ở bài tập này là sinh ra các xâu chỉ bao gồm 2 kí tự A và B theo thứ tự từ điển giảm dần.

	- Input Format: Dòng duy nhất chứa số nguyên dương N là độ dài của xâu.

	- Output Format: In ra các xâu AB, mỗi xâu được in trên 1 dòng.

	- Constraints: 1<=N<=10;

	- IP1: 3

	- OP1: BBB
		   BBA
		   BAB
		   BAA
		   ABB
		   ABA
		   AAB
		   AAA
*/

int n, ok; 
char a[101];

void ktao() {
	for (int i = 1; i <= n; i++) a[i] = 'B';	
}

void sinh() {
	int i = n;
	while(i >= 1 && a[i] == 'A') {
		a[i] = 'B';
		i--;
	}
	if (i == 0) ok = 1;
	else {
		a[i] = 'A';
	}
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ktao();
    while(!ok) {
    	for (int i = 1; i <= n; i++) cout << a[i];
    	cout << "\n";
    	sinh();
	}
    return 0;
}