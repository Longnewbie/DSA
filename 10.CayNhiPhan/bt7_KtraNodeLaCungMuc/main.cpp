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
	- Cho một cây nhị phân, nhiệm vụ của bạn là kiểm tra xem mọi node lá của cây có cùng mức hay không.

	- Input Format: Dòng đâu tiên là N : số lượng cạnh của cây. Các dòng tiếp theo mô tả cây nhị phân bằng 3 số (x, y, z) : x 
	  là node cha, y là node con, z có thể nhận 1 trong 2 giá trị là L và R, tương ứng với y là node con bên trái hoặc node con
	  bên phải của x.

	- Output Format: In YES nếu mọi node lá trên cây có cùng mức, ngược lại in NO.

	- Constraints: 1<=N<=1000; 1<=x,y<=10^5;

	- IP1: 6
		   1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R 
		   
	- OP1: YES
	
	- IP1: 7
		   1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R 6 8 L 
		   
	- OP1: NO
*/

struct node {
	int data;
	node *left, *right;
	node (int u) {
		data = u;
		left = right = NULL;
	}	
};

void makeNode(node *root, int u, int v, char c) {
	if (c == 'L') root->left = new node(v);
	else root->right = new node(v);
}

void insertNode(node *root, int u, int v, char c) {
	if (root == NULL) return;
	if (root->data == u) {
		makeNode(root, u, v, c);
	} else {
		insertNode(root->left, u, v, c);
		insertNode(root->right, u, v, c);
	}
}

int height(node *root) {
	if (root == NULL) return 0;
	return 1 + max(height(root->left), height(root->right));
}

bool check(node *root, int cnt, int h) {
	if (root == NULL) return true;
	if (!root->left && !root->right) {
		return cnt == h;
	}
	return check(root->left, cnt + 1, h) && check(root->right, cnt + 1, h);
}

void init() {
	node *root = NULL;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
    	int u, v; char c;
    	cin >> u >> v >> c;
    	if (root == NULL) {
    		root = new node(u);
    		makeNode(root, u, v, c);
		} else insertNode(root, u, v, c);
	}
	int h = height(root);
	if (check(root, 1, h)) cout << "YES";
	else cout << "NO";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	init();
    return 0;
}