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
	- Cho cây nhị phân, nhiệm vụ của bạn là duyệt cây theo thứ tự Preorder. Thứ tự duyệt Preorder của cây nhị phân bên dưới
	  xuất hiện trong test case mẫu.

	- Input Format: Dòng đâu tiên là N : số lượng cạnh của cây. Các dòng tiếp theo mô tả cây nhị phân bằng 3 số (x, y, z) : x
	  là node cha, y là node con, z có thể nhận 1 trong 2 giá trị là L và R, tương ứng với y là node con bên trái hoặc node 
	  con bên phải của x.

	- Output Format: In ra thứ tự duyệt cây Preorder.

	- Constraints: 1<=N<=1000; 1<=x,y<=10^5;

	- IP1:  6
			1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R

	- OP1:  1 2 4 5 3 6 7 
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

void Preorder(node *root) {
	if (root != NULL) {
		cout << root->data << " ";
		Preorder(root->left);
		Preorder(root->right);
	}
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
		} else {
			insertNode(root, u, v, c);
		}
	}
	Preorder(root);
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    return 0;
}