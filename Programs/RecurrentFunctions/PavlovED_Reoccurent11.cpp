#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){
setlocale (LC_ALL,"Russian");
int N = 100;
float x, eps;
cout << "x="; cin >> x;
cout << "eps="; cin >> eps;
float a = x, S = 0;                                    //начальные условия
cout << left << setw(3) << "i\t" << setw(10) << "S\t"; //заголовок
cout << setw(10) << "a" << endl;

cout << left << setw(3) << 1 << "\t" << setw(10) << S; //1 шаг
cout << "\t" << setw(10) << a << endl;

for (int i = 2; abs(a) > eps && i <= N; i++){          //i-ый шаг

S += a;

a*=-(pow(x,2*i-1)/(2*i-1));

cout << left << setw(3) << i << "\t" << setw(10) << S;
cout << "\t" << setw(10)<< a << endl;
}
return 0;
}
