#include<iostream>                    // библиотека дл€ потока ввода-вывода
#include<cmath>                       // библиотека математических функций
using namespace std;
const float e=2.71828182845904523536; // определение константы e
float F(int x,int y){
return sqrt((sqrt(cos(x)+sin(y))+pow(e,x+y))/(sqrt(x+y+log(x)*log(x))));  //в функции написано выражение из задани€ є8
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
