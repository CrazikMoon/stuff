#include<iostream>
#include<bits/stdc++.h>
#include<string>

struct stack{
    int inf;
    stack *next;
};

void push(stack *&h, int x){
    stack *r = new stack; //������� ����� �������
    r->inf = x; //���� inf = x
    r->next = h; //��������� ��������� �������� h
    h = r; //������ r �������� �������
}


int pop (stack *&h){
    int i = h->inf; //�������� ������� ��������
    stack *r = h; //��������� �� ������ �����
    h = h->next; //��������� ��������� �� ��������� �������
    delete r; //������� ������ �������
    return i; //���������� ��������
}


void reverse(stack *&h){ //"���������"�����
    stack *head1 = NULL; //������������� ��������� �����
    while (h) //���� ���� �� ����
        push(head1, pop(h)); //������������ �� ������ ����� � ������
    h = head1; //�������������� ���������
}

stack *result (stack *&h,int minx,int maxx){
    stack *res = NULL; //�������������
    int flag=0;
    while(h){
        int x = pop(h); //������� ������ �������
        push(res, x); //���������� � ���������
        if(x==maxx) push(res,minx);
    }
    reverse(res);//�������������� ���������� ����
    return res;
}
int main(){
    int n;
    int maxx=-100000000;
    int minx=10000000;
    std::cout << " n = ";
    std::cin >> n;
    stack *head = NULL; //�������������
    int x;
    std::cout << " ";
    for (int i = 0; i < n; i++){ //������� ����
        std::cin >> x;
        maxx=std::max(maxx,x);
        minx=std::min(minx,x);
        push(head, x);
        }
    reverse(head); //�������������� ����
    stack *res = result(head,minx,maxx); //���������
    std::cout << " ";
    while(res)
    std::cout << pop(res) << " "; //������� �� �����
    std::cout << std::endl;
return 0;
}
