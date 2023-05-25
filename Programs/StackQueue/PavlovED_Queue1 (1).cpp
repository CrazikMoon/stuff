#include<iostream>
using namespace std;
struct queue {
	int inf;
	queue* next;
};
void push (queue *&h,queue *&t, int x){ //вставка элемента в очередь
    queue *r = new queue; //создаем новый элемент
    r->inf = x;
    r->next = NULL; //всегда последний
    if (!h && !t){ //если очередь пуста
        h = t = r; //это и голова и хвост
    }
    else {
        t->next = r; //r - следующий для хвоста
        t = r; //теперь r - хвост
    }
}

int pop (queue *&h, queue *&t){ //удаление элемента из очереди
    queue *r = h; //создаем указатель на голову
    int i = h->inf; //сохраняем значение головы
    h = h->next; //сдвигаем указатель на следующий элемент
    if (!h) //если удаляем последний элемент из очереди
        t = NULL;
    delete r; //удаляем первый элемент
    return i;
}
int main() {
	int k,l,n,x;
	k = 0;
	l = 1;
	int firstx;
	queue* head = NULL;
	queue* tail = NULL;
	queue* head1 = NULL;
	queue* tail1 = NULL;
	cout << "Enter the length of the queue:" << endl;
	cin >> n;
	cout << "Enter the elements of the queue" << endl;
	for (int i = 0; i < n; i++) {
		cin >> x;
		push(head, tail, x);//инициализируем исходную очередь
	}
	while (head) {
        x = pop(head, tail);
        if (x%2==0){
            push(head1,tail1,x);
            break;
            }
        else{
            push(head,tail,x);
		}
	}
	;
	while(head){
        x=pop(head,tail);
        push(head1,tail1,x);
	}

	cout << "Answer is" << endl;
	while (head1) {
		cout << pop(head1, tail1) << " ";//выводим ответ
	}
}
