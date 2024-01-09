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
	  là cây nhị phân tìm kiếm với gốc cây là A[0]. Nhiệm vụ của bạn là tìm kiếm sự xuất hiện của phần tử có giá trị X trên cây 
	  nhị phân tìm kiếm.

	- Input Format: Dòng đầu tiên là N và X : số lượng phần tử trong mảng A[] và phần tử cần tìm kiếm; Dòng thứ 2 gồm N phần tử
	  trong mảng A[];

	- Output Format: In YES nếu X xuất hiện trên cây ngược lại in ra NO.

	- Constraints: 1<=N<=1000; 1<=A[i], X<=10^6;

	- IP1:  8
			8 7 5 6 2 4 1 3 
			13

	- OP1:  NO
	
	- IP2:  8
			8 7 5 6 2 4 1 3 
			5

	- OP2:  YES
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

bool Search(node *root, int key) {
	if (root == NULL) return false;
	if (root->data == key) return true;
	if (root->data > key) return Search(root->left, key);
	else return Search(root->right, key);
	return false;
}

void solve() {
	node *root = NULL;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		root = insert(root, x);
	}
	int key; cin >> key;
	if (Search(root, key)) cout << "YES";
	else cout << "NO";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}