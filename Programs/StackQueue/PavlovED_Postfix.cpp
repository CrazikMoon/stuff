#include<iostream>
#include<string>
using namespace std;
struct stack{
    char inf;
    stack *next;
};

void push(stack *&h, int x){
    stack *r = new stack; //������� ����� �������
    r->inf = x; //���� inf = x
    r->next = h; //��������� ��������� �������� h
    h = r; //������ r �������� �������
}


char pop (stack *&h){
    char i = h->inf; //�������� ������� ��������
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
