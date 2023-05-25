#include<iostream>
#include<bits/stdc++.h>
#include<string>

struct stack{
    int inf;
    stack *next;
};

void push(stack *&h, int x){
    stack *r = new stack; //создаем новый элемент
    r->inf = x; //поле inf = x
    r->next = h; //следующим элементов является h
    h = r; //теперь r является головой
}


int pop (stack *&h){
    int i = h->inf; //значение первого элемента
    stack *r = h; //указатель на голову стека
    h = h->next; //переносим указатель на следующий элемент
    delete r; //удаляем первый элемент
    return i; //возвращаем значение
}


void reverse(stack *&h){ //"обращение"стека
    stack *head1 = NULL; //инициализация буферного стека
    while (h) //пока стек не пуст
        push(head1, pop(h)); //переписываем из одного стека в другой
    h = head1; //переобозначаем указатели
}

stack *result (stack *&h,int minx,int maxx){
    stack *res = NULL; //инициализация
    int flag=0;
    while(h){
        int x = pop(h); //удаляем первый элемент
        push(res, x); //записываем в результат
        if(x==maxx) push(res,minx);
    }
    reverse(res);//переворачиваем полученный стек
    return res;
}
int main(){
    int n;
    int maxx=-100000000;
    int minx=10000000;
    std::cout << " n = ";
    std::cin >> n;
    stack *head = NULL; //инициализация
    int x;
    std::cout << " ";
    for (int i = 0; i < n; i++){ //создаем стек
        std::cin >> x;
        maxx=std::max(maxx,x);
        minx=std::min(minx,x);
        push(head, x);
        }
    reverse(head); //переворачиваем стек
    stack *res = result(head,minx,maxx); //результат
    std::cout << " ";
    while(res)
    std::cout << pop(res) << " "; //выводим на экран
    std::cout << std::endl;
return 0;
}
