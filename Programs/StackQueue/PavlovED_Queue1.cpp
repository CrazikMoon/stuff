#include<iostream>
using namespace std;
struct queue {
	int inf;
	queue* next;
};
void push (queue *&h,queue *&t, int x){ //������� �������� � �������
    queue *r = new queue; //������� ����� �������
    r->inf = x;
    r->next = NULL; //������ ���������
    if (!h && !t){ //���� ������� �����
        h = t = r; //��� � ������ � �����
    }
    else {
        t->next = r; //r - ��������� ��� ������
        t = r; //������ r - �����
    }
}

int pop (queue *&h, queue *&t){ //�������� �������� �� �������
    queue *r = h; //������� ��������� �� ������
    int i = h->inf; //��������� �������� ������
    h = h->next; //�������� ��������� �� ��������� �������
    if (!h) //���� ������� ��������� ������� �� �������
        t = NULL;
    delete r; //������� ������ �������
    return i;
}
int main() {
	int k,l,n,x;
	k = 0;
	l = 1;
	int maxx=-1000000;
	int firstx=0;
	queue* head = NULL;
	queue* tail = NULL;
	queue* head1 = NULL;
	queue* tail1 = NULL;
	cout << "Enter the length of the queue:" << endl;
	cin >> n;
	cout << "Enter the elements of the queue" << endl;
	int flag=0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		maxx=max(x,maxx);
		if (flag==0) {
            firstx=x;
            flag=1;
            }
		push(head, tail, x);//�������������� �������� �������
	}
	while (head) {
        x = pop(head, tail);
        push(head1, tail1, x);
        if(x==firstx)
        {
            push(head1,tail1,maxx);
		}
	}
	while(head1){
        x=pop(head1,tail1);
        push(head,tail,x);
	}

	cout << "Answer is" << endl;
	while (head) {
		cout << pop(head, tail) << " ";//������� �����
	}
}
