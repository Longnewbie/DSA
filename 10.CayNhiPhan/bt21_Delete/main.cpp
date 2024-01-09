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
	- Cho mảng số nguyên A[] có N phần tử, lần lượt thêm các phần tử trong mảng vào cây nhị phân sao cho cây nhị phân thu được 
	  là cây nhị phân tìm kiếm với gốc cây là A[0]. Nhiệm vụ của bạn là xóa node có giá trị X trên cây nhị phân tìm kiếm nếu 
	  tồn tại node có giá trị X.

	- Input Format: Dòng đầu tiên là N và X : số lượng phần tử trong mảng A[] và phần tử cần xóa; Dòng thứ 2 gồm N phần tử 
	  trong mảng A[];

	- Output Format: In ra thứ tự duyệt cây Inorder sau khi xóa.

	- Constraints: 1<=N<=1000; 1<=A[i], X<=10^6;

	- IP1:  8
			8 7 5 6 2 4 1 3 
			8

	- OP1:  1 2 3 4 5 6 7 
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

node *minNode(node *root) {
	node *tmp = root;
	while (tmp != NULL && tmp->left != NULL) tmp = tmp->left;
	return tmp;
}

node *DeleteNode(node *root, int key) {
	if (root == NULL) return root;
	if (root->data > key) root->left = DeleteNode(root->left, key);
	else if (root->data < key) root->right = DeleteNode(root->right, key);
	else {
		if (root->left == NULL) {
			node *tmp = root->right;
			delete root;
			return tmp;
		} else if (root->right == NULL) {
			node *tmp = root->left;
			delete root;
			return tmp;
		} else {
			node *tmp = minNode(root->right);
			root->data = tmp->data;
			root->right = DeleteNode(root->right, tmp->data);
		}
	}
	return root;
}

void inOrder(node *root) {
	if (root != NULL) {
		inOrder(root->left);
		cout << root->data << " ";
		inOrder(root->right);
	}
}

void solve() {
	node *root = NULL;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		root = insert(root, x);
	}
	int key; cin >> key;
	root = DeleteNode(root, key);
	inOrder(root);
	cout << root->data;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}