#include<iostream>
using namespace std;

int main() {
setlocale(LC_ALL, "RUS");
int o,r,a,m,n,x,y,z;
cout<<"Выберите фигуру из списка:"<<endl;
cout<<" 1.Круг"<<endl;
cout<<" 2.Квадрат"<<endl;
cout<<" 3.Треугольник"<<endl;
cout<<" 4.Прямоугольник"<<endl;
cout<<endl<<"Введите номер выбранной фигуры: ";
cin>>o;
switch(o){
case 1:

case 2:

case 3:

case 4:

default:
    cout<<"НЕДОПУСТИМЫЙ НОМЕР ФИГУРЫ";
    break;
    }
}
