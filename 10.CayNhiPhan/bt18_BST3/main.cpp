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
	  là cây nhị phân tìm kiếm với gốc cây là A[0]. In ra thứ tự duyệt cây Postorder.

	- Input Format: Dòng đầu tiên là N : số lượng phần tử trong mảng A[]; Dòng thứ 2 gồm N phần tử trong mảng A[];

	- Output Format: In ra thứ tự duyệt in Postorder của cây nhị phân tìm kiếm tạo được.

	- Constraints: 1<=N<=1000; 1<=A[i]<=10^6;

	- IP1:  7
			7 3 5 8 6 2 4

	- OP1:  2 4 6 5 3 8 7 
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