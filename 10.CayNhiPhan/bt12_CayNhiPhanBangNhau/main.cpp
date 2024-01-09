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
	- Cho 2 cây nhị phân, nhiệm vụ của bạn là kiểm tra xem 2 cây nhị phân đã cho có giống nhau hoàn toàn hay không ?

	- Input Format: Dòng đầu tiên là số N1 : Số lượng cạnh của cây nhị phân thứ 1. Các dòng tiếp theo mô tả cây nhị phân bằng 3 
	  số (x, y, z) : x là node cha, y là node con, z có thể nhận 1 trong 2 giá trị là L và R, tương ứng với y là node con bên 
	  trái hoặc node con bên phải của x. Dòng tiếp theo là số N2 : Số lượng cạnh của cây nhị phân thứ 2. Các dòng tiếp theo mô
	  tả cây nhị phân bằng 3 số (x, y, z) : x là node cha, y là node con, z có thể nhận 1 trong 2 giá trị là L và R, tương ứng 
	  với y là node con bên trái hoặc node con bên phải của x.

	- Output Format: In ra YES hoặc NO.

	- Constraints: 1<=N1,N2<=100;

	- IP1:  6
			1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R 
			6
			1 2 L 1 3 R 2 4 L 2 5 R 3 7 R 3 6 L 

	- OP1:  YES
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

void ip(node *&root) {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int u, v; char c;
		cin >> u >> v >> c;
		if (root == NULL) {
			root = new node(u);
			makeNode(root, u, v, c);
		} else insertNode(root, u, v, c);
	}
}

bool check(node *root1, node *root2) {
	if (root1 == NULL && root2 == NULL) return true;
	if (root1->data != root2->data) return false;
	if (!root1->left && root2->left || root1->left && !root2->left) return false;
    if (!root1->right && root2->right || root1->right && !root2->right) return false;
	return check(root1->left, root2->left) && check(root1->right, root2->right);
}

void solve() {
	node *root1 = NULL, *root2 = NULL;
	ip(root1); ip(root2);
	if (check(root1, root2)) cout << "YES";
	else cout << "NO";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}