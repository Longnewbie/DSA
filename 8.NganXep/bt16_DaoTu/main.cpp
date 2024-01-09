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
	- Cho một đoạn văn có không quá 10000 từ, nhiệm vụ của bạn là in ra các từ trong đoạn văn theo thứ tự ngược.

	- Input Format: Gồm nhiều dòng, mỗi dòng gồm nhiều từ.

	- Output Format: In ra các từ trong đoạn văn theo thứ tự ngược.

	- Constraints: Có không quá 10000 từ trong input.

	- IP1:  C      
			special word C++ word    28tech   
			word programming   
			word    programming C   
			Python C++    

	- OP1:  C++ Python C programming word programming word 28tech word C++ word special C 
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    stack<string> st;
    while(cin >> s) {
    	st.push(s);
	}
	while(!st.empty()) {
		cout << st.top() << " "; st.pop();
	}
    return 0;
}