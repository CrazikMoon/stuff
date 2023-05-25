#include <iostream>
#include <fstream>
#include <cmath>
#include <queue>
using namespace std;
struct tree {//
	int inf;
	tree* parent;
	tree* left;
	tree* right;
};
tree* node(int x) {//
	tree* n = new tree;
	n->inf = x;
	n->left = nullptr;
	n->right = nullptr;
	n->parent = nullptr;
	return n;
}
void create(tree* &tr, int n) {//
	int x;
	if (n > 0) {
		cin >> x;
		tr = node(x);
		int nl = n / 2;
		int nr = n- nl - 1;
		create(tr->left, nl);
		create(tr->right, nr);
	}
}
void preorder(tree* tr) {//прямой обход
	if (tr) {
		cout << tr->inf<<" ";
		preorder(tr->left);
		preorder(tr->right);
	}
}
void print(tree* tr, int k) { //функция вывода идеально сбалансированного дерева на экран
	if (!tr) cout << "empty tree\n";
	else {
		queue <tree*> cur, next;
		tree* r = tr;
		cur.push(r);
		int j = 0;
		while (cur.size()) {
			if (j == 0) {
				for (int i = 0; i < (int)pow(2.0, k) - 1; i++)
					cout << ' ';
			}
			tree* buf = cur.front();
			cur.pop();
			j++;
			if (buf) {
				cout << buf->inf;
				next.push(buf->left);
				next.push(buf->right);
				for (int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)
					cout << ' ';
			}
			if (!buf) {
				for (int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)
					cout << ' ';
				cout << ' ';
			}
			if (cur.empty()) {
				cout << endl;
				swap(cur, next);
				j = 0;
				k--;
			}
		}
	}
}
int sum_of_leafes(tree* tr) { //функция нахождения суммы листьев
	int sum = 0;
	if (!tr) return 0;
	else if (!tr->left && !tr->right)
		sum += tr->inf;
	sum += sum_of_leafes(tr->left) + sum_of_leafes(tr->right);//пройдём по каждому ребёнку каждого элемента
}
int main() {
	tree* tr = nullptr;
	int n, y;
	cout << "Input the number of elements in the tree: ";
	cin >> n;
	cout << "Input the elements of the tree: ";
	create(tr, n);//строим дерево
	preorder(tr);
	cout << endl;
	int k = int(log((float)n) / log((float)2.0));
	print(tr, k);//выведем дерево
	cout << "Answer is" << endl;
	int sum = 0;
	sum = sum_of_leafes(tr);//выведем ответ
	cout << sum;
}