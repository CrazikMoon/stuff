#include <iostream>
using namespace std;
struct tree
{
	int inf;
	tree* parent;
	tree* left;
	tree* right;
}; //��������� ������
tree* node(int x) {//������� �������������� ����� � ������� ������
	tree* n = new tree;
	n->inf = x;
	n->parent = nullptr;
	n->right = nullptr;
	n->left = nullptr;
	return n;
}
void inorder(tree* tr) {//������� ������������� ������ ������
	if (tr) {
		if (tr->left)
			inorder(tr->left);
		cout << tr->inf<<" ";
		if(tr->right)
			inorder(tr->right);
	}
}
void insert(tree*& tr,int x) {//������� ������� �������� � ������
	tree* n = node(x);
	if (!tr) {
		tr = n;
	}
	else {
		tree* y = tr;
		while (y) {
			if (n->inf > y->inf)
				if (y->right)
					y = y->right;
				else {
					n->parent = y;
					y->right = n;
					break;
				}
			else if (n->inf < y->inf)
				if (y->left)
					y = y->left;
				else {
					n->parent = y;
					y->left = n;
					break;
				}
		}
	}
}
//������� ���������� ������������ � ������������� �������� � ������, ������������ � ������� �������� �������� ������
tree* Min(tree* tr) {
	if (!tr->left) return tr;
	else return Min(tr->left);
}
tree* Max(tree* tr) {
	if (!tr->right) return tr;
	else return Max(tr->right);
}
tree* find(tree* tr, int x) { //������� ���������� ����� � ������
	if (!tr)
		return nullptr;
	if (x == tr->inf)
		return tr;
	if (x < tr->inf)
		return find(tr->left, x);
	else
		return find(tr->right, x);
}
tree* next(tree* tr, int x) { //������� ���������� ���������� �� ��������� ����� ����� � ������
	tree* n = find(tr, x);
	if (n->right)
		return Min(n->right);
	tree* y = n->parent;
	while (y && n == y->right) {
		n = y;
		y = y->parent;
	}
	return y;
}
void delete_element (tree*& tr, tree* v) { //������� �������� �������� � ������
	tree* p = v->parent;
	if (!p && !v->right && !v->left) tr = nullptr;
	else if (!v->left && !v->right) {
		if (p->left == v)
			p->left = nullptr;
		if (p->right == v)
			p->right = nullptr;
		delete v;
	}
	else if (!v->left || !v->right) {
		if (!p) {
			if (!v->left) {
				tr = v->right;
				v->parent = nullptr;
			}
			else {
				tr = v->left;
				v->parent = nullptr;
			}
		}
		else {
			if (!v->left) {
				if (p->left == v)
					p->left = v->right;
				else
					p->right = v->right;
			}
			else {
				if (p->left == v)
					p->left = v->left;
				else
					p->right = v->left;
			}
			delete v;
		}
	}
	else {
		tree* succ = next(tr, v->inf);
		v->inf = succ->inf;
		if (succ->parent->left == succ) {
			succ->parent->left = succ->right;
			if (succ->right)
				succ->right->parent = succ->parent;
		}
		else {
			succ->parent->right = succ->right;
			if (succ->right)
				succ->right->parent = succ->parent;
		}
		delete succ;
	}
	
}
//������� ��� ������ �� ������ � �������� ��� ���������, ������� ������� �� X
void delete_if_div(tree* &tr,int x) {
	if (tr){
	if (tr->left) 
		delete_if_div(tr->left, x);//�������� �� ����� �����
	if (tr->right)
		delete_if_div(tr->right, x);//�������� �� ������ �����
	}
	if (tr->inf % x == 0) {
		tree* p = tr;
		delete_element(tr, p);//������ �������, ������� ������� �� X
	}
}
int main() {
	tree* tr=nullptr;
	int n,m,x;
	cout << "Input the number of elements in the tree:" << endl;
	cin >> n;
	cout << "Input the elements of the tree:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> m;
		insert(tr, m);//������ ������
	}
	cout << "Input the number X:" << endl;
	cin >> x;
	cout << endl;
	cout << "The starting tree was: ";
	inorder(tr);//������� ������ 
	cout << endl;
	cout <<"The resulting tree is: ";
	delete_if_div(tr,x);
	inorder(tr);//������ ������ ��� ���������, ��������� �� X
}