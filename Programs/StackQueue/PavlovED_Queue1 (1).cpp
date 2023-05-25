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
		push(head, tail, x);//�������������� �������� �������
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
		cout << pop(head1, tail1) << " ";//������� �����
	}
}
