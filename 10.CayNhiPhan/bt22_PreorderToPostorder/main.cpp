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
	- Cho thứ tự duyệt Preorder của cây nhị phân tìm kiếm, hãy in ra thứ tự duyệt postorder.

	- Input Format: Dòng đầu tiên là N : số lượng node trên cây; Dòng thứ 2 là các node theo thứ tự duyệt preorder.

	- Output Format: In ra thứ tự duyệt postorder.

	- Constraints: 1<=N<=1000; Các node có giá trị dương <= 10^6;

	- IP1:  8
			8 7 5 2 1 4 3 6 

	- OP1:  1 3 4 2 6 5 7 8 
*/

struct node {
	int data;
	node *left, *right;
	node (int u) {
		data = u;
		left = right = NULL;
	}
};

node *insert(node *root, int key) {
	if (root == NULL) return new node(key);
	if (root->data > key) root->left = insert(root->left, key);
	else root->right = insert(root->right, key);
	return root;
}

void Postorder(node *root) {
	if (root != NULL) {
		Postorder(root->left);
		Postorder(root->right);
		cout << root->data << " ";
	}
}

void solve() {
	node *root = NULL;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		root = insert(root, x);
	}
	Postorder(root);
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}