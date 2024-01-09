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
	- Cho số tự nhiên n. Hãy in ra tất cả các số nhị phân từ 1 đến n. Chú ý không in thừa các bit 0 ở đầu.

	- Input Format: Một số tự nhiên n được ghi trên một dòng.

	- Output Format: In ra các số nhị phân tử 1 tới n.

	- Constraints: 1<=n<=100000;

	- IP1: 7

	- OP1: 1 10 11 100 101 110 111 
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<string> v;
    queue<string> q;
    q.push("1");
    while(1) {
    	string res = q.front(); q.pop();
    	v.pb(res); 
    	if (v.size() == n) break;
        q.push(res + "0");
    	q.push(res + "1");
	}
	for (string x : v) cout << x << " ";
    return 0;
}