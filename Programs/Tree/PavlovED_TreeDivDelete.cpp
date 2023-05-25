#include <iostream>
using namespace std;
struct tree
{
	int inf;
	tree* parent;
	tree* left;
	tree* right;
}; //структура дерева
tree* node(int x) {//функция преобразования числа в элемент дерева
	tree* n = new tree;
	n->inf = x;
	n->parent = nullptr;
	n->right = nullptr;
	n->left = nullptr;
	return n;
}
void inorder(tree* tr) {//функция симметричного обхода дерева
	if (tr) {
		if (tr->left)
			inorder(tr->left);
		cout << tr->inf<<" ";
		if(tr->right)
			inorder(tr->right);
	}
}
void insert(tree*& tr,int x) {//функция вставки элемента в дерево
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
//функции нахождения минимального и максимального элемента в дереве, используются в функции удаления элемента дерева
tree* Min(tree* tr) {
	if (!tr->left) return tr;
	else return Min(tr->left);
}
tree* Max(tree* tr) {
	if (!tr->right) return tr;
	else return Max(tr->right);
}
tree* find(tree* tr, int x) { //функция нахождения числа в дереве
	if (!tr)
		return nullptr;
	if (x == tr->inf)
		return tr;
	if (x < tr->inf)
		return find(tr->left, x);
	else
		return find(tr->right, x);
}
tree* next(tree* tr, int x) { //функция нахождения следующего за указанным узлом числа в дереве
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
void delete_element (tree*& tr, tree* v) { //функция удаления элемента в дереве
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
//функция для прохоа по дереву и удаления тех элементов, которые делятся на X
void delete_if_div(tree* &tr,int x) {
	if (tr){
	if (tr->left) 
		delete_if_div(tr->left, x);//проходим по левым детям
	if (tr->right)
		delete_if_div(tr->right, x);//проходим по правым детям
	}
	if (tr->inf % x == 0) {
		tree* p = tr;
		delete_element(tr, p);//удалим элемент, который делится на X
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
		insert(tr, m);//создаём дерево
	}
	cout << "Input the number X:" << endl;
	cin >> x;
	cout << endl;
	cout << "The starting tree was: ";
	inorder(tr);//выведем дерево 
	cout << endl;
	cout <<"The resulting tree is: ";
	delete_if_div(tr,x);
	inorder(tr);//вывдем дерево без элементов, делящихся на X
}