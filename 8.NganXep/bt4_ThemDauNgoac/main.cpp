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
	- Cho một xâu kí tự chỉ bao gồm dấu đóng mở ngoặc tròn. Hãy tìm số lượng dấu đóng mở ngoặc cần thêm tối thiểu để tạo thành 
	  một xâu cân bằng, bạn có thể thêm các kí tự đóng mở ngoặc vào bất kì vị trí nào của xâu.

	- Input Format: Xâu kí tự S trên 1 dòng.

	- Output Format: In ra số lượng dấu ngoặc cần bổ sung để xâu cân bằng.

	- Constraints: 1<=len(S)<=10000;

	- IP1: ))))()

	- OP1: 4
	
	- IP2: (((())))

	- OP2: 0
*/

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //Cách 1:
    string s; cin >> s;
    stack<char> st;
    for (char x : s) {
    	if (st.empty()) st.push(x);
    	else if (st.top() == '(' && x == ')') st.pop();
    	else st.push(x);
	}
	cout << st.size();
	//Cách 2:
/*
	string s; cin >> s;
    int d = 0;
    stack<char> st;
    for (char x : s) {
        if (st.empty()) st.push(x);
        else if (st.top() == '(' && x == ')') {
            st.pop();
            d+=2;
        } else st.push(x);
    }
    cout << s.size() - d;
*/	
    return 0;
}

