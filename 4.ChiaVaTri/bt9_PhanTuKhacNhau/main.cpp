#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
#define pb push_back
int mod = 1e9+7;

/*
	- 

	- Input Format: 

	- Output Format: 

	- Constraints: 

	- IP1: 8
		   1 2 3 4 5 6 7 8 
		   1 2 3 4 5 6 8 

	- OP1: 7
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int a[n], b[n - 1];
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    for (int i = 0; i < n; i++) {
    	if (a[i] != b[i]) {
    		cout << i + 1;
    		break;
		}
	}
    return 0;
}