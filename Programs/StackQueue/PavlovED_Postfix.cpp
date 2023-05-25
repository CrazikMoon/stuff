#include<iostream>
#include<string>
using namespace std;
struct stack{
    char inf;
    stack *next;
};

void push(stack *&h, int x){
    stack *r = new stack; //создаем новый элемент
    r->inf = x; //поле inf = x
    r->next = h; //следующим элементов является h
    h = r; //теперь r является головой
}


char pop (stack *&h){
    char i = h->inf; //значение первого элемента
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

int prior(char l){
    if (l=='(')
        return 1;
    if (l=='+'|| l=='-')
        return 2;
    if (l=='*'|| l=='/')
        return 3;
}
int main(){
	string str;
	cin>>str;
	stack* res=NULL;
	string result="";
	int i=0;
	while(i<str.length()){
        if (str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9') {
            result += str[i];
            i++;
        }
        if (str[i] == '(') {
            push(res, str[i]);
            i++;
        }
		if (str[i]==')'){
			int x=pop(res);
			while(x!='(') {
 				result+=x;
                x = pop(res);
			}
            i++;
		}
		if(!res){
            push(res,str[i]);
            i++;
		}
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            int j = pop(res);
            if (prior(str[i]) > prior(j)) {
                push(res, j);
                push(res, str[i]);
                i++;
            }
            else {
            while (prior(str[i]) <= prior(j)) {
                result += j;
                if(res) j = pop(res);
                else break;
            }
            push(res, str[i]);
            i++;
            }
        }
    }
    while(res) {
        int x=pop(res);
        result+=x;
    }
    cout<<result<<endl;
}
