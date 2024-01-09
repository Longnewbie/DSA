#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a,ll b) {ll r; while(b){r = a%b; a=b; b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int mod = 1e9+7;

/*
	- Cho xâu ký tự S. Ta gọi giá trị của xâu S là tổng bình phương số lần xuất hiện mỗi ký tự trong S. Hãy tìm giá trị nhỏ 
	  nhất của xâu S sau khi thực hiện K lần loại bỏ ký tự.

	- Input Format: Dòng 1 chứa số nguyên K; Dòng 2 chứa xâu S;

	- Output Format: In ra đáp án của bài toán.

	- Constraints: 1<=K<=100000; 1<=len(S)<=100000;

	- IP1: 2
		   adrwda

	- OP1: 4
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);    
    cin.tie(0);
    cout.tie(0);
    int k; cin >> k;
    string s; cin >> s;
    map<char,int> mp;
    for (char x : s) {
        mp[x]++;
    }
    priority_queue<int> q;
    for (auto x : mp) {
        q.push(x.second);
    }
    while(k--) {
        int t = q.top(); q.pop();
        t--;
        if (t == -1) break;
        q.push(t);
    }
    ll ans = 0;
    while(!q.empty()) { 
        ans += 1ll * q.top() * q.top();
        q.pop();
    }
    cout << ans;    
    return 0;
}