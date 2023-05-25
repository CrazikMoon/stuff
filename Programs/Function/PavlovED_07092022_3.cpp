#include<iostream>                        // библиотека дл€ потока ввода-вывода
#include<cmath>                           // библиотека математических функций
using namespace std;
const float e=2.71828182845904523536; 	  // определение константы e
float F(int x,int y){
	return 2*sin(sqrt((pow(x,2)-pow(y,2))/pow(e,x+y)+pow(x,2)*pow(y,2)))/3+(cos(x)+sin(y))/2; //в функции написано выражение из задани€ є3
}
	int main (){
	setlocale(LC_ALL,"");                 // использование русской клавиатуры
	int x,y;
	cout<<"¬ведите первое число x:";
	cin>>x;                               // ввод первой переменной
	cout<<endl;
	cout<<"¬ведите второе число y:";
	cin>>y;                               // ввод второй переменной
	cout<<endl;
	cout<<"ќтвет:"<<F(x,y);               // вывод результата выполнени€ функции
	return 0;
}
