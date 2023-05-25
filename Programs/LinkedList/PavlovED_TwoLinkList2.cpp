#include <iostream>

using namespace std;

struct list {
	int inf;
	list* next;
	list* prev;
};
void push_back(list*& h, list*& t, int x) { //вставка элемента в конец списка
	list* r = new list; //создаем новый элемент
	r->inf = x;
	r->next = NULL; //всегда последний
	if (!h && !t) { //если список пуст
		r->prev = NULL; //первый элемент
		h = r; //это голова
	}
	else {
		r->prev = t; //хвост - предыдущий для r		
		t->next = r; //r - следующий для хвоста
	}
	t = r; //r теперь хвост
}
void push_front(list*& h, list*& t, int x) {//функция вставки нового элемента в начало списка
	list* r = new list;
	r->inf = x;
	r->prev = nullptr;
	if (!h && !t) {
		r->next = nullptr;
		t = r;
	}
	else {
		r->next = h;
		h->prev = r;
	}
	h = r;//фактически функция реализована, как и вставка в конец, просто все ссылки заменены на противоположные
}
void print(list* h, list* t) { //печать элементов списка
	list* p = h; //укзатель на голову
	while (p) { //пока не дошли до конца списка
		cout << p->inf << " ";
		p = p->next; //переход к следующему элементу
	}
}

list* find(list* h, list* t, int x) { //печать элементов списка
	list* p = h; //укзатель на голову
	while (p) { //пока не дошли до конца списка
		if (p->inf == x) break; // если нашли, прекращаем цикл
		p = p->next; //переход к следующему элементу
	}
	return p; //возвращаем указатель
}
void insert_after(list*& h, list*& t, list* r, int y) { //вставляем после r
	list* p = new list; //создаем новый элемент
	p->inf = y;
	if (r == t) { //если вставляем после хвоста
		p->next = NULL; //вставляемый эл-т - последний
		p->prev = r; //вставляем после r
		r->next = p;
		t = p; //теперь хвост - p
	}
	else { //вставляем в середину списка
		r->next->prev = p; //для следующего за r эл-та предыдущий - p
		p->next = r->next; //следующий за p - следующий за r
		p->prev = r; //p вставляем после r
		r->next = p;
	}
}
void del_node(list*& h, list*& t, list* r) { //удаляем после r
	if (r == h && r == t) //единственный элемент списка
		h = t = NULL;
	else if (r == h) { //удаляем голову списка
		h = h->next; //сдвигаем голову
		h->prev = NULL;
	}
	else if (r == t) { //удаляем хвост списка
		t = t->prev; //сдвигаем хвост
		t->next = NULL;
	}
	else {
		r->next->prev = r->prev; //для следующего от r предыдущим становится r->prev
		r->prev->next = r->next; //для предыдущего от r следующимстановится r->next
	}
	delete r; //удаляем r
}
void del_list(list*& h, list*& t) { //удаляем список
	while (h) { //пока список не пуст
		list* p = h; //указатель на голову
		h = h->next; //переносим голову
		h->prev = NULL; //обнуляем
		delete p; //удаляем p
	}
}
int main() {
	int n, x, firstx = 0, maxx = 0;
	cin >> n;
	list* hlist{}, * tlist{};
	int flag = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (flag == 0) {
			firstx = x;
			flag = 1;
		}
		maxx = max(x, maxx);
		push_back(hlist, tlist, x);
	}
	list* newh = hlist;
	list* newt = tlist;
	while (newh != newt) {
		if (newh->inf % 2 == 0) {
			push_back(newh, tlist, newh->inf);
			newh = newh->next;
			del_node(hlist, tlist, newh->prev);
		}
		if (newh == newt) break;
		newh = newh->next;
	}
	print(hlist, tlist);
}
